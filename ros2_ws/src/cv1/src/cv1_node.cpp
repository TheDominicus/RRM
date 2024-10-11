#include "cv1/robot.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char **argv) {
	rclcpp::init(argc, argv);

	Robot robot;
	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Position: %f", robot.getCurrentPosition());
	robot.move(1.0);
	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Position: %f", robot.getCurrentPosition());
return 0;
}
