#include "zad1/robot.hpp"
#include "rclcpp/rclcpp.hpp"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);

    Robot robot;

    char c;
    while (true) {
        cout << "Enter one letter of WASD to move the robot or E to exit: " << endl;
        cin >> c;

        if (c == 'E') {
            break;
        }

        switch (c) {
            case 'W':
                robot.move(0.0, 1.0);
                break;
            case 'A':
                robot.move(-1.0, 0.0);
                break;
            case 'S':
                robot.move(0.0, -1.0);
                break;
            case 'D':
                robot.move(1.0, 0.0);
                break;
            default:
                cout << "Invalid input" << endl;
                continue;
        }

        cout << "Position: " << robot.getX() << ", " << robot.getY() << endl;
    }
}