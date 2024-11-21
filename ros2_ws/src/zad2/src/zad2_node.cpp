#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <std_srvs/srv/trigger.hpp>
#include <vector>

class TrajectoryNode : public rclcpp::Node {
public:
    TrajectoryNode() : Node("zad2_node") {
        // Publisher
        joint_state_pub_ = this->create_publisher<sensor_msgs::msg::JointState>("joint_states", 10);

        // Service
        traj_service_ = this->create_service<std_srvs::srv::Trigger>(
            "start_trajectory",
            std::bind(&TrajectoryNode::handle_trajectory_service, this, std::placeholders::_1, std::placeholders::_2)
        );

        RCLCPP_INFO(this->get_logger(), "Node initialized and waiting for service calls.");
    }

private:
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_state_pub_;
    rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr traj_service_;

    void handle_trajectory_service(
        const std::shared_ptr<std_srvs::srv::Trigger::Request> request,
        std::shared_ptr<std_srvs::srv::Trigger::Response> response) {
        (void)request;

        RCLCPP_INFO(this->get_logger(), "Service called. Generating and publishing trajectory...");

        // Generate trajectory
        std::vector<sensor_msgs::msg::JointState> trajectory = generate_trajectory();

        // Publish trajectory
        for (const auto &joint_state : trajectory) {
            joint_state_pub_->publish(joint_state);
            rclcpp::sleep_for(std::chrono::milliseconds(10)); // Simulate 10Hz
        }

        response->success = true;
        response->message = "Trajectory executed successfully.";
    }

    std::vector<sensor_msgs::msg::JointState> generate_trajectory() {
        std::vector<sensor_msgs::msg::JointState> trajectory;

        // Define waypoints (tabuľka 1)
        std::vector<std::vector<double>> waypoints = {
            {0.0, 0.0, 0.0},      // t = 0s
            {30.0, 0.0, 0.0},     // t = 1s
            {90.0, 0.0, 0.0},     // t = 4s
        };

        // Time and interpolation step
        double total_time = 4.0;
        double dt = 0.1;

        for (double t = 0; t <= total_time; t += dt) {
            sensor_msgs::msg::JointState joint_state;
            joint_state.header.stamp = this->now();
            joint_state.name = {"joint_1", "joint_2", "joint_3"};

            // Interpolate using simple linear interpolation (adjust for smooth trajectory)
            double q1 = interpolate(t, {0.0, 1.0, 4.0}, {0.0, 30.0, 90.0});
            double q3 = interpolate(t, {0.0, 1.0, 4.0}, {0.0, 0.0, 0.0});

            joint_state.position = {q1, 0.0, q3};
            trajectory.push_back(joint_state);
        }

        return trajectory;
    }

    double interpolate(double t, const std::vector<double>& times, const std::vector<double>& values) {
        // Linear interpolation
        for (size_t i = 1; i < times.size(); ++i) {
            if (t <= times[i]) {
                double ratio = (t - times[i - 1]) / (times[i] - times[i - 1]);
                return values[i - 1] + ratio * (values[i] - values[i - 1]);
            }
        }
        return values.back();
    }
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TrajectoryNode>());
    rclcpp::shutdown();
    return 0;
}
