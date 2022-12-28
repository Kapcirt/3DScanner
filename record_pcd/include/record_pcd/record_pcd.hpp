#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_srvs/srv/trigger.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"


class RecordPCD : public rclcpp::Node
{
public:
  RecordPCD();
  void startRecording(const std::shared_ptr<std_srvs::srv::Trigger::Request> request,
          std::shared_ptr<std_srvs::srv::Trigger::Response> response);
    void pointcloudCallback(const sensor_msgs::msg::PointCloud2::SharedPtr msg);

 private:
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr start_recording_srv_;
  rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr pointcloud_sub_;
};