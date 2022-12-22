#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_srvs/srv/trigger.hpp"


class RecordPCD : public rclcpp::Node
{
public:
  RecordPCD();
  void startRecording(const std::shared_ptr<std_srvs::srv::Trigger::Request> request,
          std::shared_ptr<std_srvs::srv::Trigger::Response> response);

 private:
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr start_recording_srv_;
};