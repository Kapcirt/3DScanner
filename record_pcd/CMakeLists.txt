cmake_minimum_required(VERSION 3.5)
project(record_pcd)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(std_srvs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(Boost REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(PCL REQUIRED QUIET COMPONENTS common io)
find_package(pcl_msgs REQUIRED)

set(dependencies
  pcl_msgs
  rclcpp
  sensor_msgs
  std_msgs
  std_srvs
)


add_library(record_pcd src/record_pcd.cpp)
ament_target_dependencies(record_pcd rclcpp std_msgs std_srvs pcl_msgs)
target_include_directories(record_pcd PUBLIC include/)
target_link_libraries(record_pcd ${DRIVER})

add_executable(record_pcd_node src/record_pcd_node.cpp)
ament_target_dependencies(record_pcd_node rclcpp std_msgs pcl_msgs)
target_include_directories(record_pcd_node PUBLIC include/)
target_link_libraries(record_pcd_node record_pcd)

install(TARGETS
  record_pcd
  record_pcd_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include
  DESTINATION include/${PROJECT_NAME}
)

install(DIRECTORY 
    launch
    DESTINATION share/${PROJECT_NAME}
    )

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
