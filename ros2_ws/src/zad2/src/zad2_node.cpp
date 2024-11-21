#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <std_srvs/srv/trigger.hpp>
#include <Eigen/Dense>
#include <cmath>
#include <vector>

using namespace std::chrono_literals;
using Eigen::MatrixXd;

class TrajectoryNode : public rclcpp::Node {
public:
    TrajectoryNode() : Node("zad2_node") {
        // Publisher for JointState messages
        joint_state_pub_ = this->create_publisher<sensor_msgs::msg::JointState>("/joint_states", 10);

        // Service to trigger trajectory generation
        service_ = this->create_service<std_srvs::srv::Trigger>(
            "/generate_trajectory",
            std::bind(&TrajectoryNode::generate_trajectory, this, std::placeholders::_1, std::placeholders::_2)
        );

        RCLCPP_INFO(this->get_logger(), "Node initialized.");
    }

private:
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_state_pub_;
    rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr service_;

    void generate_trajectory(
        const std::shared_ptr<std_srvs::srv::Trigger::Request>,
        std::shared_ptr<std_srvs::srv::Trigger::Response> response) {
        
        RCLCPP_INFO(this->get_logger(), "Generating trajectory...");
        
        // Time vector
        std::vector<double> time_points = {0.0, 1.0, 4.0};
        std::vector<double> q1 = {0.0, 30.0, 90.0};
        std::vector<double> dq1 = {0.0, 0.0, 0.0};
        std::vector<double> q3 = {0.0, 0.0, 0.0};
        std::vector<double> dq3 = {0.0, 0.0, 0.0};

        // Interpolation for each joint
        MatrixXd coeff_q1 = compute_cubic_coefficients(time_points, q1, dq1);
        MatrixXd coeff_q3 = compute_cubic_coefficients(time_points, q3, dq3);

        double t = 0.0;
        double dt = 0.1;
        sensor_msgs::msg::JointState joint_state_msg;

        while (t <= time_points.back()) {
            double pos1 = evaluate_polynomial(coeff_q1, t);
            double pos3 = evaluate_polynomial(coeff_q3, t);

            joint_state_msg.header.stamp = this->get_clock()->now();
            joint_state_msg.name = {"joint1", "joint3"};
            joint_state_msg.position = {pos1, pos3};

            joint_state_pub_->publish(joint_state_msg);
            rclcpp::sleep_for(std::chrono::milliseconds(static_cast<int>(dt * 1000)));
            t += dt;
        }

        response->success = true;
        response->message = "Trajectory generation complete.";
    }

    MatrixXd compute_cubic_coefficients(const std::vector<double>& time, const std::vector<double>& q, const std::vector<double>& dq) {
        size_t n = time.size() - 1;
        MatrixXd A(4 * n, 4 * n);
        A.setZero();
        MatrixXd b(4 * n, 1);
        b.setZero();

        // Boundary conditions and continuity
        for (size_t i = 0; i < n; ++i) {
            double t0 = time[i], t1 = time[i + 1];
            A.block<2, 4>(2 * i, 4 * i) << 1, t0, t0 * t0, t0 * t0 * t0,
                                          1, t1, t1 * t1, t1 * t1 * t1;
            b(2 * i, 0) = q[i];
            b(2 * i + 1, 0) = q[i + 1];
        }

        // Solve for coefficients
        MatrixXd coeff = A.fullPivLu().solve(b);
        return coeff;
    }

    double evaluate_polynomial(const MatrixXd& coeff, double t) {
        return coeff(0, 0) + coeff(1, 0) * t + coeff(2, 0) * t * t + coeff(3, 0) * t * t * t;
    }
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TrajectoryNode>());
    rclcpp::shutdown();
    return 0;
}
