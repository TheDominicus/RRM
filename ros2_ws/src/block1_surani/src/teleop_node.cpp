#include "rclcpp/rclcpp.hpp"
#include "rrm_msgs/msg/command.hpp"
#include "rrm_msgs/srv/command.hpp"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Teleop : public rclcpp::Node {
public:
  // Constructor for the Teleop class
  Teleop() : Node("Teleop") {
    RCLCPP_INFO(this->get_logger(), "Teleop initialized");
    client_ = this->create_client<rrm_msgs::srv::Command>("move_command");
  }

  // Function to send move commands to the robot
  bool move(const std::vector<double>& positions, double max_velocity) {
    auto request = std::make_shared<rrm_msgs::srv::Command::Request>();
    request->positions = positions;

    // Calculate the maximum distance any joint needs to travel
    double max_distance = 0.0;
    for (double position : positions) {
      max_distance = std::max(max_distance, std::abs(position));
    }

    // Calculate the velocities for each joint based on the maximum distance
    std::vector<double> velocities;
    for (double position : positions) {
      double velocity = (max_distance > 0) ? (std::abs(position) / max_distance) * max_velocity : 0;
      velocities.push_back(velocity);
    }
    request->velocities = velocities;

    // Send the request to the service and wait for the result
    auto result = client_->async_send_request(request);
    if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), result) ==
        rclcpp::FutureReturnCode::SUCCESS) {
      return 0; //result.get()->success;
    } else {
      RCLCPP_ERROR(this->get_logger(), "Failed to call service move_command");
      return false;
    }
  }

private:
  // Client to communicate with the move_command service
  rclcpp::Client<rrm_msgs::srv::Command>::SharedPtr client_;
};

int main(int argc, char ** argv) {
  rclcpp::init(argc, argv);
  auto robot = std::make_shared<Teleop>();

  // Initial move command
  robot->move({0, 0, 0}, 1.0);

  char c;
  while (c != 'q') {
    cout << "Enter 'w' to move forward, 's' to move backward, 'a' to move left, 'd' to move right, 'q' to quit" << endl;
    cin >> c;

    // Handle user input and send corresponding move commands
    switch(c) {
      case 'w':
        robot->move({1, 1, 1}, 1.0);
        break;
      case 's':
        robot->move({-1, -1, -1}, 1.0);
        break;
      case 'a':
        robot->move({1, -1, 0}, 1.0);
        break;
      case 'd':
        robot->move({-1, 1, 0}, 1.0);
        break;
      case 'h':
        robot->move({0, 0, 0}, 1.0);
        break;
      case 'q':
        break;
    }
  }

  rclcpp::shutdown();
  return 0;
}
