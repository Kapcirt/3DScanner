#include "record_pcd/get_dimensions.hpp"

GetDimensions::GetDimensions() : Node("get_dimensions")
{
    rclcpp_action::create_server<GetBoundingBox>(
      this,
      "get_bounding_box",
      std::bind(&GetDimensions::handle_goal, this, _1, _2),
      std::bind(&GetDimensions::handle_cancel, this, _1),
      std::bind(&GetDimensions::handle_accepted, this, _1));
}

    
