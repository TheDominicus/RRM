#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"

// First node: JointLogger
class JointLogger : public rclcpp::Node {
public:
    JointLogger() : Node("joint_logger") {
        subscription_ = this->create_subscription<sensor_msgs::msg::JointState>(
            "joint_states", 10, std::bind(&JointLogger::joint_states_callback, this, std::placeholders::_1));
    }

    void joint_states_callback(const sensor_msgs::msg::JointState::SharedPtr msg) {
        RCLCPP_INFO(this->get_logger(), "First joint name: %s, position: %f", msg->name[0].c_str(), msg->position[0]);
    }

private:
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscription_;
};

// Second node: JointPositionPrinter
class JointPositionPrinter : public rclcpp::Node {
public:
    JointPositionPrinter() : Node("joint_position_printer") {
        subscription_ = this->create_subscription<sensor_msgs::msg::JointState>(
            "joint_states", 10, std::bind(&JointPositionPrinter::joint_states_callback, this, std::placeholders::_1));
    }

    void joint_states_callback(const sensor_msgs::msg::JointState::SharedPtr msg) {
        RCLCPP_INFO(this->get_logger(), "Current robot position: ");
        for (size_t i = 0; i < msg->name.size(); ++i) {
            RCLCPP_INFO(this->get_logger(), "Joint %s: position %f", msg->name[i].c_str(), msg->position[i]);
        }
    }

private:
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscription_;
};

int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);

    auto logger = std::make_shared<JointLogger>();
    auto position_printer = std::make_shared<JointPositionPrinter>();

    rclcpp::executors::SingleThreadedExecutor executor;
    executor.add_node(logger);
    executor.add_node(position_printer);

    executor.spin();

    rclcpp::shutdown();

    return 0;
}