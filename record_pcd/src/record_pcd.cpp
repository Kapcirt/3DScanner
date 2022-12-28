#include "record_pcd/record_pcd.hpp"

RecordPCD::RecordPCD() : Node("record_pcd")
{
  RCLCPP_INFO(this->get_logger(), "In constructor");
  start_recording_srv_ = this->create_service<std_srvs::srv::Trigger>("~/start_record", std::bind(&RecordPCD::startRecording, 
              this, 
              std::placeholders::_1, 
              std::placeholders::_2));

  pointcloud_sub_ = this->create_subscription<sensor_msgs::msg::PointCloud2>("/pointcloud_in", 
      10, std::bind(&RecordPCD::pointcloudCallback, this, std::placeholders::_1));

}

void RecordPCD::startRecording(const std::shared_ptr<std_srvs::srv::Trigger::Request> request,
  std::shared_ptr<std_srvs::srv::Trigger::Response> response) {
  RCLCPP_INFO(this->get_logger(), "In callback service");

  response->success = true;
}

void RecordPCD::pointcloudCallback(const sensor_msgs::msg::PointCloud2::SharedPtr msg) {
  RCLCPP_INFO_STREAM(this->get_logger(), "In callback");
}
    
