#include "rclcpp/rclcpp.hpp"
#include "rrm_msgs/msg/command.hpp"
#include "rrm_msgs/srv/command.hpp"
#include <iostream>

using namespace std;

class Teleop : public rclcpp::Node{
  public:
  Teleop() : Node("Teleop")
  {
    RCLCPP_INFO(this->get_logger(), "Teleop initialized");
    publisher_ = this->create_publisher<rrm_msgs::msg::Command>("move_command", 10);
  }

  void move(int joint_id, double position) {
    rrm_msgs::msg::Command message;
    message.joint_id = joint_id;
    message.position = position;
    publisher_->publish(message);
  }

  private:
    rclcpp::Publisher<rrm_msgs::msg::Command>::SharedPtr publisher_;
};

int main(int argc, char ** argv){
  rclcpp::init(argc, argv);
  auto robot = std::make_shared<Teleop>();

  robot->move(1, 0);
  robot->move(2, 0);

  char c;
  while (c != 'q'){
    cout << "Enter 'w' to move forward, 's' to move backward, 'a' to move left, 'd' to move right, 'q' to quit" << endl;
    cin >> c;

    switch(c){
      case 'w':
      robot->move(1, 1);
      robot->move(2, 1);
      break;
      case 's':
      robot->move(1, -1);
      robot->move(2, -1);
      break;
      case 'a':
      robot->move(1, 1);
      robot->move(2, -1);
      break;
      case 'd':
      robot->move(1, -1);
      robot->move(2, 1);
      break;
      case 'h':
      robot->move(1, 0);
      robot->move(2, 0);
      case 'q':
      break;
    }
  }

  rclcpp::shutdown();
  return 0;
}