#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <iostream>
#include <cmath>
#include "surani_interface/srv/teach_point.hpp"
#include <Eigen/Geometry>
#include <fstream>
#include <sstream>
#include <string>

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

double evaluate_velocity(const Eigen::VectorXd& coeffs, double t) {
    return coeffs[1] + 2 * coeffs[2] * t + 3 * coeffs[3] * pow(t, 2) + 4 * coeffs[4] * pow(t, 3) + 5 * coeffs[5] * pow(t, 4);
}

double evaluate_acceleration(const Eigen::VectorXd& coeffs, double t) {
    return 2 * coeffs[2] + 6 * coeffs[3] * t + 12 * coeffs[4] * pow(t, 2) + 20 * coeffs[5] * pow(t, 3);
}

double evaluate_jerk(const Eigen::VectorXd& coeffs, double t) {
    return 6 * coeffs[3] + 24 * coeffs[4] * t + 60 * coeffs[5] * pow(t, 2);
}

class CartesianTrajectoryPlanner : public rclcpp::Node {
private:
    void handle_service_request(const std::shared_ptr<surani_interface::srv::TeachPoint::Request> req,
                                std::shared_ptr<surani_interface::srv::TeachPoint::Response> res);
    void initialize_tool_position();

public:
    CartesianTrajectoryPlanner();
    rclcpp::Service<surani_interface::srv::TeachPoint>::SharedPtr service_server;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr pose_publisher;
    geometry_msgs::msg::PoseStamped tool_pose_msg;
};

void CartesianTrajectoryPlanner::initialize_tool_position() {
    tool_pose_msg.pose.position.x = 1.0;
    tool_pose_msg.pose.position.y = 0.0;
    tool_pose_msg.pose.position.z = 1.6;
    tool_pose_msg.pose.orientation.x = 0.0;
    tool_pose_msg.pose.orientation.y = 1.0;
    tool_pose_msg.pose.orientation.z = 0.0;
    tool_pose_msg.pose.orientation.w = 1.0;
    tool_pose_msg.header.stamp = this->get_clock()->now();
    pose_publisher->publish(tool_pose_msg);
}

CartesianTrajectoryPlanner::CartesianTrajectoryPlanner() : Node("cartesian_trajectory_planner") {
    rclcpp::sleep_for(std::chrono::seconds(1));
    service_server = this->create_service<surani_interface::srv::TeachPoint>("cartesian_trajectory_planner",
        std::bind(&CartesianTrajectoryPlanner::handle_service_request, this, std::placeholders::_1, std::placeholders::_2));
    pose_publisher = this->create_publisher<geometry_msgs::msg::PoseStamped>("tool_pose", 10);

    initialize_tool_position();
}

void CartesianTrajectoryPlanner::handle_service_request(const std::shared_ptr<surani_interface::srv::TeachPoint::Request> req,
                                               std::shared_ptr<surani_interface::srv::TeachPoint::Response> res) {
    ofstream output_file("zad2_2.csv");
    int sample_rate = 100;  // in Hz
    double delta_t = 1.0 / static_cast<double>(sample_rate);  // in seconds
    double current_time = 0.0;
    double total_duration = 9.0;  // total duration in seconds

    // Define the trajectory phases as per Zadanie 2.2
    struct Phase {
        double duration;
        Eigen::Vector3d start_pos;
        Eigen::Vector3d end_pos;
        Eigen::Quaterniond start_rot;
        Eigen::Quaterniond end_rot;
    };

    std::vector<Phase> trajectory_phases = {
        {1.0, Eigen::Vector3d(1.0, 0.0, 1.6), Eigen::Vector3d(1.0, 0.0, 1.0), Eigen::Quaterniond(0, 1, 0, 1), Eigen::Quaterniond(0, 1, 0, 1)}, // Move down in Z
        {1.0, Eigen::Vector3d(1.0, 0.0, 1.0), Eigen::Vector3d(1.0, 0.0, 1.0), Eigen::Quaterniond(0, 1, 0, 1), Eigen::Quaterniond(0, 0.707, 0, 0.707)}, // Rotate 90 degrees around Z
        {1.0, Eigen::Vector3d(1.0, 0.0, 1.0), Eigen::Vector3d(1.0, 0.0, 1.0), Eigen::Quaterniond(0, 0.707, 0, 0.707), Eigen::Quaterniond(0, 0.707, 0, 0.707)}, // Hold for 1 second
        {1.0, Eigen::Vector3d(1.0, 0.0, 1.0), Eigen::Vector3d(1.0, 0.5, 1.0), Eigen::Quaterniond(0, 0.707, 0, 0.707), Eigen::Quaterniond(0, 0.707, 0, 0.707)}, // Move along Y-axis
        {1.0, Eigen::Vector3d(1.0, 0.5, 1.0), Eigen::Vector3d(1.0, 0.5, 1.6), Eigen::Quaterniond(0, 0.707, 0, 0.707), Eigen::Quaterniond(0, 1, 0, 1)}, // Move up along Z and rotate back
        {5.0, Eigen::Vector3d(1.0, 0.5, 1.6), Eigen::Vector3d(1.0, 0.0, 1.6), Eigen::Quaterniond(0, 1, 0, 1), Eigen::Quaterniond(0, 1, 0, 1)} // Return to initial position
    };

    output_file << "time,x [m],y [m],z [m],qx,qy,qz,qw" << endl;

    rclcpp::Rate loop_frequency(sample_rate);

    for (const auto& phase : trajectory_phases) {
        Eigen::Vector3d position = phase.start_pos;
        Eigen::Quaterniond rotation = phase.start_rot;

        double t = 0.0;
        while (t <= phase.duration) {
            double alpha = t / phase.duration;
            position = (1 - alpha) * phase.start_pos + alpha * phase.end_pos;
            rotation = phase.start_rot.slerp(alpha, phase.end_rot);

            tool_pose_msg.pose.position.x = position.x();
            tool_pose_msg.pose.position.y = position.y();
            tool_pose_msg.pose.position.z = position.z();
            tool_pose_msg.pose.orientation.x = rotation.x();
            tool_pose_msg.pose.orientation.y = rotation.y();
            tool_pose_msg.pose.orientation.z = rotation.z();
            tool_pose_msg.pose.orientation.w = rotation.w();
            tool_pose_msg.header.stamp = this->get_clock()->now();
            pose_publisher->publish(tool_pose_msg);

            output_file << current_time << "," << position.x() << "," << position.y() << "," << position.z() << ","
                        << rotation.x() << "," << rotation.y() << "," << rotation.z() << "," << rotation.w() << endl;

            current_time += delta_t;
            t += delta_t;
            loop_frequency.sleep();
        }
    }

    //res->success = true;
}

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<CartesianTrajectoryPlanner>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
