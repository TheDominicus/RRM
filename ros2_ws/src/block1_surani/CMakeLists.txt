cmake_minimum_required(VERSION 3.8)
project(block1_surani)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rrm_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(surani_interface REQUIRED)
find_package(Eigen3 REQUIRED)

include_directories( ${EIGEN3_INCLUDE_DIRS} )

add_executable(teleop_node src/teleop_node.cpp)
add_executable(logger_node src/logger_node.cpp)
add_executable(jointlogger_node src/jointlogger.cpp)

target_include_directories(teleop_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)
target_include_directories(logger_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)
target_include_directories(jointlogger_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)

target_compile_features(teleop_node PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
target_compile_features(logger_node PUBLIC c_std_99 cxx_std_17)
target_compile_features(jointlogger_node PUBLIC c_std_99 cxx_std_17)

ament_target_dependencies(
  teleop_node
  "surani_interface"
  "rclcpp"
  "rrm_msgs"
  "geometry_msgs"
  "sensor_msgs"
  "tf2_ros"
  "Eigen3"
)
ament_target_dependencies(
  logger_node
  "rclcpp"
  "tf2_ros"
  "sensor_msgs"
  "geometry_msgs"
  "rrm_msgs"
  "surani_interface"
  "Eigen3"
)
ament_target_dependencies(
  jointlogger_node
  "rclcpp"
  "tf2_ros"
  "sensor_msgs"
  "geometry_msgs"
  "rrm_msgs"
  "surani_interface"
  "Eigen3"
)

install(TARGETS teleop_node logger_node jointlogger_node
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}/
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
