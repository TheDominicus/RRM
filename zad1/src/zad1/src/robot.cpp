#include "zad1/robot.hpp"
#include "rclcpp/rclcpp.hpp"

Robot::Robot() : positionX_(0.0), positionY_(0.0) {
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Hello, I'm a robot");
}

void Robot::move(const double x, const double y) {
    this->positionX_ = x;
    this->positionY_ = y;
}

double Robot::getX () const {
    return positionX_;
}

double Robot::getY () const {
    return positionY_;
}