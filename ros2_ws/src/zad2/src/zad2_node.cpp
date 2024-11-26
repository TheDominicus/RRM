#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <iostream>
#include <cmath>
#include "surani_interface/srv/teach_point.hpp"
#include <Eigen/Geometry>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

Eigen::VectorXd calculate_coefficients(double t_start, double t_end, double start_pos, double end_pos,
 double start_vel, double end_vel, double start_acc, double end_acc) {
    Eigen::VectorXd coefficients(6);
    Eigen::MatrixXd coefficient_matrix(6, 6);
    Eigen::VectorXd boundary_conditions(6);

    coefficient_matrix << 1, t_start, pow(t_start, 2), pow(t_start, 3), pow(t_start, 4), pow(t_start, 5),
                          0, 1, 2 * t_start, 3 * pow(t_start, 2), 4 * pow(t_start, 3), 5 * pow(t_start, 4),
                          0, 0, 2, 6 * t_start, 12 * pow(t_start, 2), 20 * pow(t_start, 3),
                          1, t_end, pow(t_end, 2), pow(t_end, 3), pow(t_end, 4), pow(t_end, 5),
                          0, 1, 2 * t_end, 3 * pow(t_end, 2), 4 * pow(t_end, 3), 5 * pow(t_end, 4),
                          0, 0, 2, 6 * t_end, 12 * pow(t_end, 2), 20 * pow(t_end, 3);

    boundary_conditions << start_pos, start_vel, start_acc, end_pos, end_vel, end_acc;

    coefficients = coefficient_matrix.inverse() * boundary_conditions;
    return coefficients;
}

double evaluate_position(const Eigen::VectorXd& coeffs, double t) {
    return coeffs[0] + coeffs[1] * t + coeffs[2] * pow(t, 2) + coeffs[3] * pow(t, 3) + coeffs[4] * pow(t, 4) + coeffs[5] * pow(t, 5);
}

double evaluate_velocity(const Eigen::VectorXd& coeffs, double t) {
    return coeffs[1] + 2 * coeffs[2] * t + 3 * coeffs[3] * pow(t, 2) + 4 * coeffs[4] * pow(t, 3) + 5 * coeffs[5] * pow(t, 4);
}

double evaluate_acceleration(const Eigen::VectorXd& coeffs, double t) {
    return 2 * coeffs[2] + 6 * coeffs[3] * t + 12 * coeffs[4] * pow(t, 2) + 20 * coeffs[5] * pow(t, 3);
}

double evaluate_jerk(const Eigen::VectorXd& coeffs, double t) {
    return 6 * coeffs[3] + 24 * coeffs[4] * t + 60 * coeffs[5] * pow(t, 2);
}

class TrajectoryPlanner : public rclcpp::Node {
private:
    void handle_service_request(const std::shared_ptr<surani_interface::srv::TeachPoint::Request> req,
                                std::shared_ptr<surani_interface::srv::TeachPoint::Response> res);
    void initialize_joint_positions();

public:
    TrajectoryPlanner();
    rclcpp::Service<surani_interface::srv::TeachPoint>::SharedPtr service_server;
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_publisher;
    sensor_msgs::msg::JointState joint_state_msg;
};

void TrajectoryPlanner::initialize_joint_positions() {
    for (auto& pos : joint_state_msg.position) {
        pos = 0.0;
    }
    joint_state_msg.header.stamp = this->get_clock()->now();
    joint_publisher->publish(joint_state_msg);
}

TrajectoryPlanner::TrajectoryPlanner() : Node("zad2") {
    rclcpp::sleep_for(std::chrono::seconds(1));
    service_server = this->create_service<surani_interface::srv::TeachPoint>("trajectory_planner",
        std::bind(&TrajectoryPlanner::handle_service_request, this, std::placeholders::_1, std::placeholders::_2));
    joint_publisher = this->create_publisher<sensor_msgs::msg::JointState>("joint_states", 10);

    joint_state_msg.name = {"joint_1", "joint_2", "joint_3", "joint_4", "joint_5", "joint_6"};
    joint_state_msg.position.resize(joint_state_msg.name.size(), 0.0);
    joint_state_msg.velocity.resize(joint_state_msg.name.size(), 0.0);
    joint_state_msg.effort.resize(joint_state_msg.name.size(), 0.0);
    initialize_joint_positions();
}

void TrajectoryPlanner::handle_service_request(const std::shared_ptr<surani_interface::srv::TeachPoint::Request> req,
                                               std::shared_ptr<surani_interface::srv::TeachPoint::Response> res) {
    ofstream output_file("zad2.csv");
    int sample_rate = 100;  // in Hz
    double delta_t = 1.0 / static_cast<double>(sample_rate);  // in seconds
    double total_duration = 4.0;  // in seconds
    double switch_time = 1.0;  // in seconds
    double current_time = 0.0;

    Eigen::VectorXd coeffs_joint_1 = calculate_coefficients(0.0, 4.0, 0.0, 1.57, 0.0, 0.0, 0.0, 0.0);
    Eigen::VectorXd coeffs_joint_3_phase1 = calculate_coefficients(0.0, 1.0, 0.0, 0.5236, 0.0, 0.0, 0.0, 0.0);
    Eigen::VectorXd coeffs_joint_3_phase2 = calculate_coefficients(1.0, 4.0, 0.5236, 0.0, 0.0, 0.0, 0.0, 0.0);

    output_file << "time,position_joint_1 [rad],velocity_joint_1 [rad/s],acceleration_joint_1 [rad/s^2],jerk_joint_1 [rad/s^3],"
                << "position_joint_3 [rad],velocity_joint_3 [rad/s],acceleration_joint_3 [rad/s^2],jerk_joint_3 [rad/s^3]"
                << endl;

    rclcpp::Rate loop_frequency(sample_rate);
    while (rclcpp::ok()) {
        for (size_t i = 0; i < joint_state_msg.position.size(); ++i) {
            if (i == 0) { 
                joint_state_msg.position[i] = evaluate_position(coeffs_joint_1, current_time);
                joint_state_msg.velocity[i] = evaluate_velocity(coeffs_joint_1, current_time);
                double joint_1_acc = evaluate_acceleration(coeffs_joint_1, current_time);
                double joint_1_jerk = evaluate_jerk(coeffs_joint_1, current_time);
                output_file << current_time << "," << joint_state_msg.position[i] << "," << joint_state_msg.velocity[i] << "," <<
                 joint_1_acc << "," << joint_1_jerk;
            } else if (i == 2) { 
                if (current_time <= switch_time) {
                    joint_state_msg.position[i] = evaluate_position(coeffs_joint_3_phase1, current_time);
                    joint_state_msg.velocity[i] = evaluate_velocity(coeffs_joint_3_phase1, current_time);
                    double joint_3_acc = evaluate_acceleration(coeffs_joint_3_phase1, current_time);
                    double joint_3_jerk = evaluate_jerk(coeffs_joint_3_phase1, current_time);
                    output_file << "," << joint_state_msg.position[i] << "," << joint_state_msg.velocity[i] << "," << joint_3_acc <<
                     "," << joint_3_jerk;
                } else {
                    joint_state_msg.position[i] = evaluate_position(coeffs_joint_3_phase2, current_time);
                    joint_state_msg.velocity[i] = evaluate_velocity(coeffs_joint_3_phase2, current_time);
                    double joint_3_acc = evaluate_acceleration(coeffs_joint_3_phase2, current_time);
                    double joint_3_jerk = evaluate_jerk(coeffs_joint_3_phase2, current_time);
                    output_file << "," << joint_state_msg.position[i] << "," << joint_state_msg.velocity[i] << "," << joint_3_acc << 
                     "," << joint_3_jerk;
                }
            } else {
                joint_state_msg.position[i] = evaluate_position(coeffs_joint_1, current_time);
                joint_state_msg.velocity[i] = evaluate_velocity(coeffs_joint_1, current_time);
            }
        }

        output_file << endl;
        joint_state_msg.header.stamp = this->get_clock()->now();
        joint_publisher->publish(joint_state_msg);
        current_time += delta_t;
        if (current_time > total_duration) break;

        loop_frequency.sleep();
    }

    //res->success = true;
}

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TrajectoryPlanner>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
