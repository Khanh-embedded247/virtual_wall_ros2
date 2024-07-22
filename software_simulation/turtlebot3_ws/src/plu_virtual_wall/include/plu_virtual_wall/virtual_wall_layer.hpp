#ifndef VIRTUAL_WALL_LAYER_HPP
#define VIRTUAL_WALL_LAYER_HPP

#include <rclcpp/rclcpp.hpp>
#include <nav_msgs/msg/occupancy_grid.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <yaml-cpp/yaml.h>
#include <pluginlib/class_list_macros.hpp>
#include <nav2_costmap_2d/layer.hpp>
#include <nav2_costmap_2d/costmap_layer.hpp>
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/buffer.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>

namespace virtual_wall_ros2
{

class VirtualWallLayer : public nav2_costmap_2d::CostmapLayer
{
public:
  VirtualWallLayer();
  virtual void onInitialize() override;
  virtual void updateBounds(double, double, double, double*, double*, double*, double*) override;
  virtual void updateCosts(nav2_costmap_2d::Costmap2D&, int, int, int, int) override;
  virtual void activate() override {}
  virtual void deactivate() override {}
  virtual void reset() override {}
  virtual bool isClearable() override { return true; }

private:
  void mapCallback(const nav_msgs::msg::OccupancyGrid::SharedPtr map);
  void loadVirtualWallPoints(const std::string& filename);
  void createLineCloud();
  void getLineCells(int x0, int x1, int y0, int y1, std::vector<std::pair<int, int>>& pts);
  void publishCloud();

  rclcpp::Subscription<nav_msgs::msg::OccupancyGrid>::SharedPtr map_sub_;
  rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr point_cloud_pub_;
  rclcpp::TimerBase::SharedPtr timer_;

  tf2_ros::Buffer tf_buffer_;
  tf2_ros::TransformListener tf_listener_;

  std::vector<geometry_msgs::msg::Point> virtual_wall_points_;
  std::vector<std::pair<int, int>> line_cells_;

  bool map_received_;
  nav_msgs::msg::MapMetaData map_info_;
  std::string global_frame_;
  std::string map_frame_;
  std::string virtual_wall_points_file_;
};

}  // namespace virtual_wall_ros2

#endif  // VIRTUAL_WALL_LAYER_HPP
