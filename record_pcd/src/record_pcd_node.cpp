#include "record_pcd/record_pcd.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<RecordPCD>());
  rclcpp::shutdown();
  return 0;
}