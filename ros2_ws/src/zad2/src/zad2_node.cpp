#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <Eigen/Geometry>
#include <iostream>
#include <cmath>
#include "surani_interface/srv/teach_point.hpp"
#include <std_msgs/msg/float64.hpp>
#include <rclcpp/publisher.hpp>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/msg/transform_stamped.hpp>
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
        plot_publisher_joint_1_ = this->create_publisher<std_msgs::msg::Float64>("plot/joint_1", 10);
        plot_publisher_joint_3_ = this->create_publisher<std_msgs::msg::Float64>("plot/joint_3", 10);
        tf_broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(this);
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
        if (request->velocity == 0) {
            response->result = false;
            response->message = "Velocity cannot be zero.";
            return;
        }
        execute_trajectory();
        response->result = true;
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

            // Publish joint state values to PlotJuggler topics
            std_msgs::msg::Float64 joint_1_msg;
            joint_1_msg.data = joint_state_msg_.position[0];
            plot_publisher_joint_1_->publish(joint_1_msg);

            std_msgs::msg::Float64 joint_3_msg;
            joint_3_msg.data = joint_state_msg_.position[2];
            plot_publisher_joint_3_->publish(joint_3_msg);

            // Update and publish joint states
            joint_state_msg_.header.stamp = this->get_clock()->now();
            joint_state_msg_.position[0] = position.x();  // Assuming joint_1 represents the position along X
            joint_state_msg_.position[2] = position.z();  // Assuming joint_3 represents the position along Z
            joint_publisher_->publish(joint_state_msg_);

            // Broadcast the transform for each link
            publish_all_transforms(position, rotation);

            rclcpp::sleep_for(10ms);
        }
    }

    void publish_all_transforms(const Eigen::Vector3d& position, const Eigen::Quaterniond& rotation) {
        // Example of broadcasting transforms for all links relative to base_link
        geometry_msgs::msg::Pose link_pose;
        link_pose.position.x = position.x();
        link_pose.position.y = position.y();
        link_pose.position.z = position.z();
        link_pose.orientation.x = rotation.x();
        link_pose.orientation.y = rotation.y();
        link_pose.orientation.z = rotation.z();
        link_pose.orientation.w = rotation.w();

        publish_transform("base_link", "link_1", link_pose);
        publish_transform("link_1", "link_2", link_pose);
        publish_transform("link_2", "link_3", link_pose);
        publish_transform("link_3", "link_4", link_pose);
        publish_transform("link_4", "link_5", link_pose);
        publish_transform("link_5", "link_6", link_pose);
        publish_transform("link_6", "tool_link", link_pose);
    }

    void publish_transform(const std::string& parent_frame, const std::string& child_frame, const geometry_msgs::msg::Pose& pose) {
        geometry_msgs::msg::TransformStamped transform_stamped;

        transform_stamped.header.stamp = this->get_clock()->now();
        transform_stamped.header.frame_id = parent_frame;
        transform_stamped.child_frame_id = child_frame;

        transform_stamped.transform.translation.x = pose.position.x;
        transform_stamped.transform.translation.y = pose.position.y;
        transform_stamped.transform.translation.z = pose.position.z;

        transform_stamped.transform.rotation = pose.orientation;

        tf_broadcaster_->sendTransform(transform_stamped);
    }

    Eigen::Quaterniond create_quaternion(double x, double y, double z, double w) {
        Eigen::Quaterniond q(w, x, y, z);
        q.normalize();
        return q;
    }

    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_publisher_;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr pose_publisher_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr plot_publisher_joint_1_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr plot_publisher_joint_3_;
    rclcpp::Service<surani_interface::srv::TeachPoint>::SharedPtr service_;
    std::shared_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
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
