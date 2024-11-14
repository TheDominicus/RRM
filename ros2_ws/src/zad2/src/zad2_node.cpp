#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <cmath>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "std_srvs/srv/trigger.hpp"

using namespace std::chrono_literals;

class TrajectoryNode : public rclcpp::Node {
public:
    TrajectoryNode() : Node("trajectory_node"), running_(false) {
        // Create publisher for joint state
        joint_pub_ = create_publisher<sensor_msgs::msg::JointState>("joint_states", 10);

        // Create service for starting trajectory
        service_ = create_service<std_srvs::srv::Trigger>("start_trajectory", 
            std::bind(&TrajectoryNode::start_trajectory, this, std::placeholders::_1, std::placeholders::_2));

        timer_ = create_wall_timer(100ms, std::bind(&TrajectoryNode::update, this));
    }

private:
    void start_trajectory(const std::shared_ptr<std_srvs::srv::Trigger::Request> request,
                          std::shared_ptr<std_srvs::srv::Trigger::Response> response) {
        running_ = true;
        start_time_ = now();
        response->success = true;
        response->message = "Trajectory started.";
    }

    void update() {
        if (!running_) return;

        auto current_time = now() - start_time_;
        double t = current_time.seconds();

        sensor_msgs::msg::JointState joint_state;
        joint_state.name = {"joint_1", "joint_3"};
        joint_state.position.resize(2);
        joint_state.velocity.resize(2);
        joint_state.effort.resize(2);

        // According to Table 1:
        if (t < 1.0) {
            joint_state.position[0] = 0.0;
            joint_state.velocity[0] = 0.0;
            joint_state.position[1] = 0.0;
        } else if (t < 4.0) {
            joint_state.position[0] = 90.0 * (t - 1.0) / 3.0;
            joint_state.velocity[0] = 30.0;
            joint_state.position[1] = 0.0;
        } else {
            joint_state.position[0] = 90.0;
            joint_state.velocity[0] = 0.0;
            joint_state.position[1] = 0.0;
        }

        joint_pub_->publish(joint_state);
    }

    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_pub_;
    rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr service_;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Time start_time_;
    bool running_;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TrajectoryNode>());
    rclcpp::shutdown();
    return 0;
}
