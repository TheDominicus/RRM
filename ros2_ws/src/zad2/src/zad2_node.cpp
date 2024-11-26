#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <Eigen/Geometry>
#include <iostream>
#include <cmath>
#include "surani_interface/srv/teach_point.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <vector>

using namespace std::chrono_literals;

struct Phase {
    double duration;
    Eigen::Vector3d start_pos;
    Eigen::Vector3d end_pos;
    Eigen::Quaterniond start_rot;
    Eigen::Quaterniond end_rot;
};

class TrajectoryPlanner : public rclcpp::Node {
public:
    TrajectoryPlanner() : Node("cartesian_trajectory_planner") {
        joint_publisher_ = this->create_publisher<sensor_msgs::msg::JointState>("joint_states", 10);
        pose_publisher_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("tool_pose", 10);
        service_ = this->create_service<surani_interface::srv::TeachPoint>(
            "start_trajectory",
            std::bind(&TrajectoryPlanner::handle_service_request, this, std::placeholders::_1, std::placeholders::_2)
        );
        joint_state_msg_.name = {"joint_1", "joint_2", "joint_3", "joint_4", "joint_5", "joint_6"};
        joint_state_msg_.position.resize(joint_state_msg_.name.size(), 0.0);
        joint_state_msg_.velocity.resize(joint_state_msg_.name.size(), 0.0);
        joint_state_msg_.effort.resize(joint_state_msg_.name.size(), 0.0);
        initialize_joint_positions();
    }

private:
    void initialize_joint_positions() {
        for (auto& pos : joint_state_msg_.position) {
            pos = 0.0;
        }
        joint_state_msg_.header.stamp = this->get_clock()->now();
        joint_publisher_->publish(joint_state_msg_);
    }

    void handle_service_request(const std::shared_ptr<surani_interface::srv::TeachPoint::Request> request,
                                std::shared_ptr<surani_interface::srv::TeachPoint::Response> response) {
        (void)request; // Prevent unused parameter warning
        execute_trajectory();
        response->success = true;
        response->message = "Trajectory executed successfully.";
    }

    void execute_trajectory() {
        // Define trajectory phases as described in Zadanie 2.2
        std::vector<Phase> phases = {
            {1.0, Eigen::Vector3d(1.0, 0.0, 1.6), Eigen::Vector3d(1.0, 0.0, 1.0), Eigen::Quaterniond(0, 1, 0, 1), Eigen::Quaterniond(0, 1, 0, 1)},       // Move down along Z
            {1.0, Eigen::Vector3d(1.0, 0.0, 1.0), Eigen::Vector3d(1.0, 0.0, 1.0), Eigen::Quaterniond(0, 1, 0, 1), Eigen::Quaterniond(0, 0.707, 0, 0.707)}, // Rotate around Z
            {1.0, Eigen::Vector3d(1.0, 0.0, 1.0), Eigen::Vector3d(1.0, 0.0, 1.0), Eigen::Quaterniond(0, 0.707, 0, 0.707), Eigen::Quaterniond(0, 0.707, 0, 0.707)}, // Hold position
            {1.0, Eigen::Vector3d(1.0, 0.0, 1.0), Eigen::Vector3d(1.0, 0.5, 1.0), Eigen::Quaterniond(0, 0.707, 0, 0.707), Eigen::Quaterniond(0, 0.707, 0, 0.707)}, // Move along Y
            {1.0, Eigen::Vector3d(1.0, 0.5, 1.0), Eigen::Vector3d(1.0, 0.5, 1.6), Eigen::Quaterniond(0, 0.707, 0, 0.707), Eigen::Quaterniond(0, 1, 0, 1)}, // Move up and rotate back
            {5.0, Eigen::Vector3d(1.0, 0.5, 1.6), Eigen::Vector3d(1.0, 0.0, 1.6), Eigen::Quaterniond(0, 1, 0, 1), Eigen::Quaterniond(0, 1, 0, 1)}        // Return to initial
        };

        // Execute each phase
        for (const auto& phase : phases) {
            execute_phase(phase);
        }
    }

    void execute_phase(const Phase& phase) {
        auto start_time = std::chrono::steady_clock::now();
        double alpha = 0.0;
        double duration = phase.duration;

        while (alpha < 1.0) {
            auto current_time = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed_time = current_time - start_time;
            double t = elapsed_time.count();

            if (t >= duration) {
                alpha = 1.0;
            } else {
                alpha = t / duration;
            }

            Eigen::Vector3d position = (1 - alpha) * phase.start_pos + alpha * phase.end_pos;
            Eigen::Quaterniond rotation = phase.start_rot.slerp(alpha, phase.end_rot);

            tool_pose_.pose.position.x = position.x();
            tool_pose_.pose.position.y = position.y();
            tool_pose_.pose.position.z = position.z();
            tool_pose_.pose.orientation.x = rotation.x();
            tool_pose_.pose.orientation.y = rotation.y();
            tool_pose_.pose.orientation.z = rotation.z();
            tool_pose_.pose.orientation.w = rotation.w();
            tool_pose_.header.stamp = this->get_clock()->now();

            pose_publisher_->publish(tool_pose_);

            rclcpp::sleep_for(10ms);
        }
    }

    Eigen::Quaterniond create_quaternion(double x, double y, double z, double w) {
        Eigen::Quaterniond q(w, x, y, z);
        q.normalize();
        return q;
    }

    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_publisher_;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr pose_publisher_;
    rclcpp::Service<surani_interface::srv::TeachPoint>::SharedPtr service_;
    sensor_msgs::msg::JointState joint_state_msg_;
    geometry_msgs::msg::PoseStamped tool_pose_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TrajectoryPlanner>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
