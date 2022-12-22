#include "record_pcd/record_pcd.hpp"

RecordPCD::RecordPCD() : Node("record_pcd")
{
    RCLCPP_INFO(this->get_logger(), "In constructor");
    start_recording_srv_ = this->create_service<std_srvs::srv::Trigger>("add_two_ints", std::bind(&RecordPCD::startRecording, 
                this, 
                std::placeholders::_1, 
                std::placeholders::_2));
}

void RecordPCD::startRecording(const std::shared_ptr<std_srvs::srv::Trigger::Request> request,
    std::shared_ptr<std_srvs::srv::Trigger::Response> response) {
    RCLCPP_INFO(this->get_logger(), "In callback");
}
    
