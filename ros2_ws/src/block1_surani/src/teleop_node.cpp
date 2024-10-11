#include "rclcpp/rclcpp.hpp"
#include "rrm_msgs/msg/command.hpp"
#include "rrm_msgs/srv/command.hpp"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Define a class Teleop that inherits from rclcpp::Node
class Teleop : public rclcpp::Node {
public:
  // Constructor for the Teleop class
  Teleop() : Node("Teleop") {
    RCLCPP_INFO(this->get_logger(), "Teleop initialized"); // Log initialization message
    publisher_ = this->create_publisher<rrm_msgs::msg::Command>("move_command", 10); // Create a publisher for move_command topic
    client_ = this->create_client<rrm_msgs::srv::Command>("move_command"); // Create a client for move_command service
  }

  // Method to send move command via service
  bool move(const std::vector<double>& positions, double max_velocity) {
    auto request = std::make_shared<rrm_msgs::srv::Command::Request>();
    request->velocities = calculate_velocities(positions, max_velocity);

    auto result = client_->async_send_request(request);
    if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), result) == rclcpp::FutureReturnCode::SUCCESS) {
      return result.get()->result_code ? false : true;
    } else {
      RCLCPP_ERROR(this->get_logger(), "Failed to call service move_command");
      return false;
    }
  }

private:
  rclcpp::Publisher<rrm_msgs::msg::Command>::SharedPtr publisher_; // Publisher for move_command topic
  rclcpp::Client<rrm_msgs::srv::Command>::SharedPtr client_; // Client for move_command service

  // Method to calculate velocities based on positions and max_velocity
  std::vector<double> calculate_velocities(const std::vector<double>& positions, double max_velocity) {
    std::vector<double> velocities(positions.size(), 0.0); // Initialize velocities vector with zeros
    double max_position = 0.0; // Initialize max_position to zero

    // Find the maximum position change
    for (const auto& pos : positions) {
      if (std::abs(pos) > max_position) {
        max_position = std::abs(pos); // Update max_position if current position is greater
      }
    }

    // Calculate velocities based on the maximum position change
    for (size_t i = 0; i < positions.size(); ++i) {
      if (max_position > 0) {
        velocities[i] = (positions[i] / max_position) * max_velocity; // Scale velocities based on max_position
      }
    }

    return velocities;
  }
};

int main(int argc, char ** argv) {
  rclcpp::init(argc, argv);
  auto robot = std::make_shared<Teleop>(); // Create a shared pointer to Teleop object

  char c;
  while (c != 'q') {
    cout << "Enter 'w' to move forward, 's' to move backward, 'a' to move left, 'd' to move right, 'q' to quit" << endl;
    cin >> c; 

    switch(c) {
      case 'w':
        robot->move({1, 1, 1}, 1);
        break;
      case 's':
        robot->move({-1, -1}, 1);
        break;
      case 'a':
        robot->move({1, -1}, 1);
        break;
      case 'd':
        robot->move({-1, 1}, 1);
        break;
      case 'h':
        robot->move({0, 0}, 1);
        break;
      case 'q':
        break;
    }
  }

  rclcpp::shutdown();
  return 0;
}
