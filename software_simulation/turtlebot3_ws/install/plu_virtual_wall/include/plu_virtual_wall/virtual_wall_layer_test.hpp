#ifndef VIRTUAL_WALL_LAYER_HPP_
#define VIRTUAL_WALL_LAYER_HPP_

#include "nav2_costmap_2d/layer.hpp"
#include "nav2_costmap_2d/layered_costmap.hpp"
#include "pluginlib/class_list_macros.hpp"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "nav_msgs/msg/occupancy_grid.hpp"
#include <vector>

namespace virtual_wall_ros2
{

class VirtualWallLayer : public nav2_costmap_2d::Layer
{
public:
    VirtualWallLayer();
    virtual ~VirtualWallLayer();
    virtual void onInitialize() override;
    virtual void updateBounds(double origin_x, double origin_y, double origin_yaw, double *min_x, double *min_y, double *max_x, double *max_y) override;
    virtual void updateCosts(nav2_costmap_2d::Costmap2D &master_grid, int min_i, int min_j, int max_i, int max_j) override;
    virtual bool isClearable() const override { return false; }
    virtual void reset() override;
    virtual void matchSize() override;

private:
    void loadVirtualWallPoints(const std::string &filename);
    void processMap(const nav_msgs::msg::OccupancyGrid &map);
    void markPolygonCells(nav2_costmap_2d::Costmap2D &master_grid, int min_i, int min_j, int max_i, int max_j);
    bool isPointInPolygon(double x, double y, const std::vector<geometry_msgs::msg::Point> &polygon);
    void incomingMap(const nav_msgs::msg::OccupancyGrid::SharedPtr new_map);
    void getParameters();

    tf2_ros::Buffer tf_buffer_;
    tf2_ros::TransformListener tf_listener_;
    std::string global_frame_;
    rclcpp::Duration transform_tolerance_;
    std::vector<geometry_msgs::msg::Point> virtual_wall_points_;
    nav_msgs::msg::OccupancyGrid::SharedPtr map_buffer_;
    rclcpp::Subscription<nav_msgs::msg::OccupancyGrid>::SharedPtr map_sub_;
};

} // namespace virtual_wall_ros2

#endif // VIRTUAL_WALL_LAYER_HPP_
