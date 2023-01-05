#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"
#include "geometry_msgs/msg/pose.hpp"

#include "rclcpp_action/rclcpp_action.hpp"
#include "record_pcd/action/get_bounding_box.hpp"

using namespace std::placeholders;

class GetDimensions : public rclcpp::Node
{
public:
  using GetBoundingBox = record_pcd::action::GetBoundingBox;
  using GoalHangleGetBoundingBox = rclcpp_action::ServerGoalHandle<GetBoundingBox>;

  GetDimensions();
  void getBoundingBox();
  geometry_msgs::msg::Pose getQRCodePose();

  rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID & uuid,
    std::shared_ptr<const GetBoundingBox::Goal> goal);
  rclcpp_action::CancelResponse handle_cancel(
    const std::shared_ptr<GoalHangleGetBoundingBox> goal);
  void handle_accepted(
    const std::shared_ptr<GoalHangleGetBoundingBox> goal);

    void execute(const std::shared_ptr<GoalHangleGetBoundingBox> goal_handle);

  rclcpp_action::Server<GetBoundingBox>::SharedPtr get_bounding_box_as_;

};