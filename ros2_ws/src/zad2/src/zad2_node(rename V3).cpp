#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <Eigen/Geometry>
#include <iostream>
#include <cmath>
#include "surani_interface/srv/teach_point.hpp"
#include <std_msgs/msg/float64.hpp>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <vector>

using namespace std::chrono_literals;
using namespace std;

struct Phase {
    double duration;
    Eigen::Vector3d start_pos;
    Eigen::Vector3d end_pos;
    Eigen::Quaterniond start_rot;
    Eigen::Quaterniond end_rot;
};

class CartesianTrajectoryPlanner : public rclcpp::Node {
public:
    CartesianTrajectoryPlanner();

private:
    void handle_service_request(const std::shared_ptr<surani_interface::srv::TeachPoint::Request> req,
                                std::shared_ptr<surani_interface::srv::TeachPoint::Response> res);
    void initialize_tool_position();
    void execute_trajectory();
    void execute_phase(const Phase& phase);
    void publish_all_transforms(const Eigen::Vector3d& position, const Eigen::Quaterniond& rotation);
    void publish_transform(const std::string& parent_frame, const std::string& child_frame, const geometry_msgs::msg::Pose& pose);
    void update_joint_state(const Eigen::Vector3d& position);
    rclcpp::Service<surani_interface::srv::TeachPoint>::SharedPtr service_server;
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_publisher;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr pose_publisher;
    std::shared_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
    sensor_msgs::msg::JointState joint_state_msg;
    geometry_msgs::msg::PoseStamped tool_pose;
};

CartesianTrajectoryPlanner::CartesianTrajectoryPlanner() : Node("cartesian_trajectory_planner") {
    rclcpp::sleep_for(std::chrono::seconds(1));
    service_server = this->create_service<surani_interface::srv::TeachPoint>("cartesian_trajectory",
        std::bind(&CartesianTrajectoryPlanner::handle_service_request, this, std::placeholders::_1, std::placeholders::_2));
    joint_publisher = this->create_publisher<sensor_msgs::msg::JointState>("joint_states", 10);
    pose_publisher = this->create_publisher<geometry_msgs::msg::PoseStamped>("tool_pose", 10);
    tf_broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(this);

    joint_state_msg.name = {"joint_1", "joint_2", "joint_3", "joint_4", "joint_5", "joint_6"};
    joint_state_msg.position.resize(joint_state_msg.name.size(), 0.0);
    joint_state_msg.velocity.resize(joint_state_msg.name.size(), 0.0);
    joint_state_msg.effort.resize(joint_state_msg.name.size(), 0.0);
    initialize_tool_position();
}

void CartesianTrajectoryPlanner::initialize_tool_position() {
    for (auto& pos : joint_state_msg.position) {
        pos = 0.0;
    }
    joint_state_msg.header.stamp = this->get_clock()->now();
    joint_publisher->publish(joint_state_msg);
}

void CartesianTrajectoryPlanner::handle_service_request(const std::shared_ptr<surani_interface::srv::TeachPoint::Request> req,
                                                        std::shared_ptr<surani_interface::srv::TeachPoint::Response> res) {
    if (req->velocity == 0) {
        res->success = false;
        return;
    }
    execute_trajectory();
    res->success = true;
}

void CartesianTrajectoryPlanner::execute_trajectory() {
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

void CartesianTrajectoryPlanner::execute_phase(const Phase& phase) {
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
        rotation.normalize(); // Ensure quaternion is normalized

        tool_pose.pose.position.x = position.x();
        tool_pose.pose.position.y = position.y();
        tool_pose.pose.position.z = position.z();
        tool_pose.pose.orientation.x = rotation.x();
        tool_pose.pose.orientation.y = rotation.y();
        tool_pose.pose.orientation.z = rotation.z();
        tool_pose.pose.orientation.w = rotation.w();
        tool_pose.header.stamp = this->get_clock()->now();

        pose_publisher->publish(tool_pose);

        // Update and publish joint states
        update_joint_state(position);
        joint_state_msg.header.stamp = tool_pose.header.stamp; // Use the same timestamp for synchronization
        joint_publisher->publish(joint_state_msg);

        // Broadcast the transform for each link
        publish_all_transforms(position, rotation);

        rclcpp::sleep_for(10ms);
    }
}

void CartesianTrajectoryPlanner::update_joint_state(const Eigen::Vector3d& position) {
    // Update joint states to reflect the new Cartesian position
    // Note: this is a placeholder logic. Replace it with the actual kinematic mapping if necessary.
    joint_state_msg.position[0] = position.x();  // Assuming joint_1 controls x position
    joint_state_msg.position[1] = position.y();  // Assuming joint_2 controls y position
    joint_state_msg.position[2] = position.z();  // Assuming joint_3 controls z position
}

void CartesianTrajectoryPlanner::publish_all_transforms(const Eigen::Vector3d& position, const Eigen::Quaterniond& rotation) {
    geometry_msgs::msg::Pose link_pose;
    link_pose.position.x = position.x();
    link_pose.position.y = position.y();
    link_pose.position.z = position.z();
    link_pose.orientation.x = rotation.x();
    link_pose.orientation.y = rotation.y();
    link_pose.orientation.z = rotation.z();
    link_pose.orientation.w = rotation.w();

    publish_transform("base_link", "tool_link", link_pose);
}

void CartesianTrajectoryPlanner::publish_transform(const std::string& parent_frame, const std::string& child_frame, const geometry_msgs::msg::Pose& pose) {
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

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<CartesianTrajectoryPlanner>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
