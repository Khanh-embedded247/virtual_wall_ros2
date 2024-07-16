#include "rclcpp/rclcpp.hpp"
#include "nav2_costmap_2d/layered_costmap.hpp"
#include "plu_virtual_wall/virtual_wall_layer.hpp"

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);

  auto node = rclcpp::Node::make_shared("virtual_wall_node");
  auto lifecycle_node = std::make_shared<rclcpp_lifecycle::LifecycleNode>("virtual_wall_lifecycle_node");

  nav2_costmap_2d::LayeredCostmap layered_costmap("map", false, false);
  auto virtual_wall_layer = std::make_shared<virtual_wall_ros2::VirtualWallLayer>();

  tf2_ros::Buffer tf_buffer(node->get_clock());
  tf2_ros::TransformListener tf_listener(tf_buffer);

  auto weak_node_handle = std::weak_ptr<rclcpp_lifecycle::LifecycleNode>(lifecycle_node);

  virtual_wall_layer->initialize(&layered_costmap, "virtual_wall_layer", &tf_buffer, weak_node_handle, nullptr);

  rclcpp::spin(node);
  rclcpp::shutdown();

  return 0;
}
