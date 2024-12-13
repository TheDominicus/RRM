#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <Eigen/Geometry>
#include <cmath>

using namespace std;

Eigen::VectorXd calculate_coefficients(double t_start, double t_end, double start_pos, double end_pos,
                                       double start_vel, double end_vel, double start_acc, double end_acc) {
    Eigen::VectorXd coefficients(6);
    Eigen::MatrixXd coefficient_matrix(6, 6);
    Eigen::VectorXd boundary_conditions(6);

    coefficient_matrix << 1, t_start, pow(t_start, 2), pow(t_start, 3), pow(t_start, 4), pow(t_start, 5),
                          0, 1, 2 * t_start, 3 * pow(t_start, 2), 4 * pow(t_start, 3), 5 * pow(t_start, 4),
                          0, 0, 2, 6 * t_start, 12 * pow(t_start, 2), 20 * pow(t_start, 3),
                          1, t_end, pow(t_end, 2), pow(t_end, 3), pow(t_end, 4), pow(t_end, 5),
                          0, 1, 2 * t_end, 3 * pow(t_end, 2), 4 * pow(t_end, 3), 5 * pow(t_end, 4),
                          0, 0, 2, 6 * t_end, 12 * pow(t_end, 2), 20 * pow(t_end, 3);

    boundary_conditions << start_pos, start_vel, start_acc, end_pos, end_vel, end_acc;

    coefficients = coefficient_matrix.inverse() * boundary_conditions;
    return coefficients;
}

double evaluate_position(const Eigen::VectorXd& coeffs, double t) {
    return coeffs[0] + coeffs[1] * t + coeffs[2] * pow(t, 2) + coeffs[3] * pow(t, 3) + coeffs[4] * pow(t, 4) + coeffs[5] * pow(t, 5);
}

class TrajectoryPlanner : public rclcpp::Node {
public:
    TrajectoryPlanner();
    void execute_trajectory();

private:
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_publisher_;
    sensor_msgs::msg::JointState joint_state_msg_;
};

TrajectoryPlanner::TrajectoryPlanner() : Node("trajectory_planner") {
    joint_publisher_ = this->create_publisher<sensor_msgs::msg::JointState>("joint_states", 10);

    joint_state_msg_.name = {"joint_1", "joint_2", "joint_3", "joint_4", "joint_5", "joint_6"};
    joint_state_msg_.position.resize(joint_state_msg_.name.size(), 0.0);
    joint_state_msg_.velocity.resize(joint_state_msg_.name.size(), 0.0);
    joint_state_msg_.effort.resize(joint_state_msg_.name.size(), 0.0);
}

void TrajectoryPlanner::execute_trajectory() {
    rclcpp::Rate loop_rate(100);  // 100 Hz
    double current_time = 0.0;
    double total_duration = 4.0;

    // Joint 1 trajectory: 0 -> 90 degrees (1.57 radians) over 4 seconds
    Eigen::VectorXd coeffs_joint_1 = calculate_coefficients(0.0, total_duration, 0.0, 1.57, 0.0, 0.0, 0.0, 0.0);

    // Joint 3 trajectory: two phases
    Eigen::VectorXd coeffs_joint_3_phase1 = calculate_coefficients(0.0, 1.0, 0.0, 0.5236, 0.0, 0.0, 0.0, 0.0);  // Phase 1
    Eigen::VectorXd coeffs_joint_3_phase2 = calculate_coefficients(1.0, 4.0, 0.5236, 0.0, 0.0, 0.0, 0.0, 0.0);  // Phase 2

    while (rclcpp::ok() && current_time <= total_duration) {
        joint_state_msg_.header.stamp = this->get_clock()->now();

        // Update joint_1 position
        joint_state_msg_.position[0] = evaluate_position(coeffs_joint_1, current_time);

        // Update joint_3 position based on the current phase
        if (current_time <= 1.0) {
            joint_state_msg_.position[2] = evaluate_position(coeffs_joint_3_phase1, current_time);
        } else {
            joint_state_msg_.position[2] = evaluate_position(coeffs_joint_3_phase2, current_time);
        }

        // Publish the updated joint states
        joint_publisher_->publish(joint_state_msg_);

        current_time += 0.01;  // Step by 10 ms
        loop_rate.sleep();
    }
}

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);

    auto node = std::make_shared<TrajectoryPlanner>();
    node->execute_trajectory();

    rclcpp::shutdown();
    return 0;
}
