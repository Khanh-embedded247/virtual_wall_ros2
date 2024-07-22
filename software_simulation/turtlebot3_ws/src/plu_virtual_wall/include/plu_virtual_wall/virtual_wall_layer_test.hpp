#ifndef VIRTUAL_WALL_LAYER_HPP_
#define VIRTUAL_WALL_LAYER_HPP_

#include <rclcpp/rclcpp.hpp>
#include <nav2_costmap_2d/costmap_layer.hpp>
#include <nav2_costmap_2d/layered_costmap.hpp>
#include <nav2_costmap_2d/costmap_2d_ros.hpp>
#include <geometry_msgs/msg/point_stamped.hpp>
#include <std_msgs/msg/int32.hpp>
#include <visualization_msgs/msg/marker.hpp>
#include <tf2_ros/transform_listener.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <pluginlib/class_list_macros.hpp>
#include <boost/thread/recursive_mutex.hpp>

namespace virtual_wall {

class VirtualWallLayer : public costmap_2d::CostmapLayer
{
public:
  VirtualWallLayer();
  virtual ~VirtualWallLayer();

  virtual void onInitialize() override;
  virtual void updateBounds(double, double, double, double*, double*, double*, double*) override;
  virtual void updateCosts(costmap_2d::Costmap2D&, int, int, int, int) override;

private:
  void matchSize();
  bool WallInterpolation();
  void AddWallCallback(const geometry_msgs::msg::PointStamped::SharedPtr msg);
  void DeleteWallCallback(const std_msgs::msg::Int32::SharedPtr msg);

  double resolution;
  double wallmax_x, wallmax_y, wallmin_x, wallmin_y;
  std::vector<virtual_wall::Wall> wallPoint;
  std::vector<virtual_wall::Wall> v_wall;
  std::string global_frame_, map_frame_;

  rclcpp::Subscription<geometry_msgs::msg::PointStamped>::SharedPtr add_wall_sub_;
  rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr wall_list_pub_;
  rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr delete_wall_sub_;
  rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr wall_maker_pub_;

  boost::recursive_mutex data_access_;
  tf2_ros::Buffer tf_buffer_;
  tf2_ros::TransformListener tf_listener_;
};

}  // namespace virtual_wall

#endif  // VIRTUAL_WALL_LAYER_HPP_
