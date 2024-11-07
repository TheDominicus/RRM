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

class JointLogger : public rclcpp::Node {
	public:
		JointLogger();
		~JointLogger();
		void joint_states_callback(const sensor_msgs::msg::JointState::SharedPtr msg);
		bool handle_service(const std::shared_ptr<surani_interface::srv::TeachPoint::Request> request, std::shared_ptr<surani_interface::srv::TeachPoint::Response> response);

	private:
		rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscription_;
		rclcpp::Service<surani_interface::srv::TeachPoint>::SharedPtr service_;
		std::ofstream file;
		std::vector<double> previous_positions_;
		sensor_msgs::msg::JointState::SharedPtr last_msg_;
		int id = 0;
		tf2_ros::TransformBroadcaster tf_broadcaster_;
	};

JointLogger::JointLogger() : Node("joint_logger"), tf_broadcaster_(this) {
	subscription_ = this->create_subscription<sensor_msgs::msg::JointState>("joint_states", 10, std::bind(&JointLogger::joint_states_callback, this, std::placeholders::_1));
	service_ = this->create_service<surani_interface::srv::TeachPoint>("log_joint_positions", std::bind(&JointLogger::handle_service, this, std::placeholders::_1, std::placeholders::_2));

	file.open("/home/dominik/RRM/ros2_ws/src/block1_surani/Zad1.6_log.txt", std::ios_base::app);
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
	for (int i = 0; i <= 5; i++) {
		RCLCPP_INFO(this->get_logger(), "Nazov: %s\tPozicia: %f", msg->name[i].c_str(), msg->position[i]);
	}

	last_msg_ = msg;
	geometry_msgs::msg::TransformStamped transform;
	transform.header.stamp = this->get_clock()->now();
	transform.header.frame_id = "base_link";
	transform.child_frame_id = "tool0_calculated";

	double a[6] = {0, 0.2, 0, 0, 0, 0};
	double d[6] = {0, 0, 0, 0.25, 0, 0.1805+ msg->position[5]};
	double Alpha[6] = {M_PI/2, 0, M_PI/2, M_PI/2, M_PI/2, 0};
	double Theta[6] = {msg->position[0]+M_PI, msg->position[1]+M_PI/2, msg->position[2]+M_PI/2, msg->position[3]+M_PI, msg->position[4]+M_PI, 0};
	Eigen::Matrix4d Ai, A1, A2, A3, A4, A5, A6, T;
	
	for (int i = 0; i <  6;i++) {
		Ai << cos(Theta[i]), -1*sin(Theta[i])*cos(Alpha[i]), sin(Theta[i])*sin(Alpha[i]), a[i]*cos(Theta[i]),
			sin(Theta[i]), cos(Theta[i])*cos(Alpha[i]), -1*cos(Theta[i])*sin(Alpha[i]), a[i]*sin(Theta[i]),
			0, sin(Alpha[i]), cos(Alpha[i]), d[i],
			0, 0, 0, 1;
		
		if (i == 0)
		{
			A1 = Ai;
		}
		else if (i == 1)
		{
			A2 = Ai;
		}
		else if (i == 2)
		{
			A3 = Ai;
		}
		else if (i == 3)
		{
			A4 = Ai;
		}
		else if (i == 4)
		{
			A5 = Ai;
		}
		else if (i == 5)
		{
			A6 = Ai;
		}
	}
	T = A1 * A2 * A3 * A4 * A5 * A6;
	
	transform.transform.translation.x = T(0, 3);
	transform.transform.translation.y = T(1, 3);
	transform.transform.translation.z = T(2, 3);
	Eigen::Quaterniond q(T.block<3,3>(0,0));
	transform.transform.rotation.x = q.x();
	transform.transform.rotation.y = q.y();
	transform.transform.rotation.z = q.z();
	transform.transform.rotation.w = q.w();

	tf_broadcaster_.sendTransform(transform);
}

bool JointLogger::handle_service(const std::shared_ptr<surani_interface::srv::TeachPoint::Request> request, std::shared_ptr<surani_interface::srv::TeachPoint::Response> response) {
	if (last_msg_ == nullptr)
	{
		response->result = false;
		response->message = "Ziadne data na zalogovanie.";
		return true;
	}

	if (file.is_open())
	{
		file << "ID: " << id << ",\n Pozicia 1: " << last_msg_->position[0] << ",\n Pozicia 2: " << last_msg_->position[1] << ",\n Pozicia 3: " << last_msg_->position[2] << ",\n Max Velocity: " << request->velocity << "\n\n";
		response->result = true;
		response->message = "Zapis prebehol uspesne";
		id++;
	}
	else
	{
		response->result = false;
		response->message = "Nepodarilo sa otvorit subor na zapis!\n";
	}
	return true;
}

int main(int argc, char **argv) {
	rclcpp::init(argc, argv);
	std::shared_ptr<JointLogger> logger = std::make_shared<JointLogger>();
	rclcpp::spin(logger);
	rclcpp::shutdown();
	return 0;
}
