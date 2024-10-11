#include "cv1/robot.hpp"
#include "rclcpp/rclcpp.hpp"

Robot::Robot() : position_(0.0) {
RCLCPP_INFO(rclcpp::get_logger("rclcpp"),"Hello I'm robot" );
}
void Robot::move(const double position){
this->position_ = position;
}
double Robot::getCurrentPosition () const {
return position_;
}
