#include <cstdio>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2/LinearMath/Quaternion.h>
#include <iostream>
#include <fstream>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "surani_interface/srv/TeachPoint.hpp"
#include <Eigen/Geometry>
#include <cmath>
#include <array>

class JointLogger : public rclcpp::Node {
	public:
		JointLogger();
		~JointLogger();
		void joint_states_callback(const sensor_msgs::msg::JointState::SharedPtr msg);
		bool handle_service(const std::shared_ptr<surani_interface::srv::TeachPoint::Request> request,
		 std::shared_ptr<surani_interface::srv::TeachPoint::Response> response);

	private:
		int id = 0;
		rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr sub_;
		rclcpp::Service<surani_interface::srv::TeachPoint>::SharedPtr srvc_;
		std::ofstream file;
		std::vector<double> prev_pos_;
		sensor_msgs::msg::JointState::SharedPtr end_msg_;
		tf2_ros::TransformBroadcaster tf_broadcaster_;
};

JointLogger::JointLogger() : Node("joint_logger"), tf_broadcaster_(this) {
	sub_ = this->create_subscription<sensor_msgs::msg::JointState>("joint_states", 10, std::bind(&JointLogger::joint_states_callback,
	 this, std::placeholders::_1));
	srvc_ = this->create_service<surani_interface::srv::TeachPoint>("log_joint_positions", std::bind(&JointLogger::handle_service, 
	 this, std::placeholders::_1, std::placeholders::_2));

	file.open("/home/dominik/RRM/ros2_ws/src/block1_surani/Zad1.6_logs.txt", std::ios_base::app);
	if (!file.is_open()) {
		RCLCPP_ERROR(this->get_logger(), "Otvorenie neuspesne!\n");
	}
}

JointLogger::~JointLogger() {
	if (file.is_open()) {
		file.close();
	}
}

void JointLogger::joint_states_callback(const sensor_msgs::msg::JointState::SharedPtr msg) {
	for (size_t i = 0; i < msg->name.size(); ++i) {
		RCLCPP_INFO(this->get_logger(), "Nazov: %s\tPozicia: %f", msg->name[i].c_str(), msg->position[i]);
	}

	end_msg_ = msg;
	geometry_msgs::msg::TransformStamped transform;
	transform.header.stamp = this->get_clock()->now();
	transform.header.frame_id = "base_link";
	transform.child_frame_id = "tool0";

	std::array<double, 6> a = {0, 0.25, 0.3, 0, 1, 0};
	std::array<double, 6> d = {0, 1, 0, 0.5, 0, 0.1805 + msg->position[5]};
	std::array<double, 6> Alpha = {M_PI / 2, 0, M_PI / 2, M_PI / 2, M_PI / 2, 0};
	std::array<double, 6> Theta = {msg->position[0] + M_PI, msg->position[1] + M_PI / 2, msg->position[2] + M_PI / 2,
	 msg->position[3] + M_PI, msg->position[4] + M_PI, 0};

	Eigen::Matrix4d T = Eigen::Matrix4d::Identity();
	for (int i = 0; i < 6; ++i) {
		Eigen::Matrix4d Ai;
		Ai << cos(Theta[i]), -sin(Theta[i]) * cos(Alpha[i]), sin(Theta[i]) * sin(Alpha[i]), a[i] * cos(Theta[i]),
			  sin(Theta[i]), cos(Theta[i]) * cos(Alpha[i]), -cos(Theta[i]) * sin(Alpha[i]), a[i] * sin(Theta[i]),
			  0, sin(Alpha[i]), cos(Alpha[i]), d[i],
			  0, 0, 0, 1;
		T *= Ai;
	}

	transform.transform.translation.x = T(0, 3);
	transform.transform.translation.y = T(1, 3);
	transform.transform.translation.z = T(2, 3);
	Eigen::Quaterniond q(T.block<3, 3>(0, 0));
	transform.transform.rotation.x = q.x();
	transform.transform.rotation.y = q.y();
	transform.transform.rotation.z = q.z();
	transform.transform.rotation.w = q.w();

	tf_broadcaster_.sendTransform(transform);
}

bool JointLogger::handle_service(const std::shared_ptr<surani_interface::srv::TeachPoint::Request> request,
 std::shared_ptr<surani_interface::srv::TeachPoint::Response> response) {
	
	if (!end_msg_) {
		response->result = false;
		response->message = "Ziadne data na zalogovanie.";
		return true;
	}

	if (file.is_open()) {
		file << "ID: " << id << ",\n Pozicia 1: " << end_msg_->position[0] << ",\n Pozicia 2: " << end_msg_->position[1] <<
		 ",\n Pozicia 3: " << end_msg_->position[2] << ",\n Max Velocity: " << request->velocity << "\n\n";
		
		response->result = true;
		response->message = "Zapis prebehol uspesne";
		id++;
	} else {
		response->result = false;
		response->message = "Nepodarilo sa otvorit subor na zapis!\n";
	}

	return true;
}

int main(int argc, char **argv) {
	rclcpp::init(argc, argv);
	auto logger = std::make_shared<JointLogger>();
	rclcpp::spin(logger);
	rclcpp::shutdown();

	return 0;
}