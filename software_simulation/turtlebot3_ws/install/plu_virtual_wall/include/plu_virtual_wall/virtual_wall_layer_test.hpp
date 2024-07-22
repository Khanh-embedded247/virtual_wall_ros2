#ifndef VIRTUAL_WALL_LAYER_HPP
#define VIRTUAL_WALL_LAYER_HPP

#include <rclcpp/rclcpp.hpp>
#include <nav2_costmap_2d/layer.hpp>
#include <nav2_costmap_2d/layered_costmap.hpp>
#include <pluginlib/class_list_macros.hpp>
#include <tf2_ros/transform_listener.h>
#include <geometry_msgs/msg/point.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <nav_msgs/msg/occupancy_grid.hpp>
#include <yaml-cpp/yaml.h>
#include <pcl/point_types.h>
#include <pcl_ros/point_cloud.h>
#include <pcl_conversions/pcl_conversions.h>

namespace virtual_wall_ros2
{

class VirtualWallLayer : public nav2_costmap_2d::Layer
{
public:
    VirtualWallLayer();
    virtual ~VirtualWallLayer();

    virtual void onInitialize() override;
    virtual void updateBounds(double, double, double, double *, double *, double *, double *) override;
    virtual void updateCosts(nav2_costmap_2d::Costmap2D &, int, int, int, int) override;
    virtual bool isClearable() override { return false; }

private:
    void mapCallback(const nav_msgs::msg::OccupancyGrid::SharedPtr msg);
    void loadVirtualWallPoints(const std::string &filename);
    void publishPointCloud();
    void createLineCloud(double wx0, double wx1, double wy0, double wy1, pcl::PointCloud<pcl::PointXYZ> &pc);
    void getLineCells(int x0, int x1, int y0, int y1, std::vector<Point2D> &pts);

    rclcpp::Subscription<nav_msgs::msg::OccupancyGrid>::SharedPtr map_sub_;
    rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr point_cloud_pub_;
    std::vector<geometry_msgs::msg::Point> virtual_wall_points_;
    std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
    std::shared_ptr<tf2_ros::TransformListener> tf_listener_;
    std::string global_frame_;
    tf2::Duration transform_tolerance_;
    bool has_updated_data_;
};

struct Point2D
{
    int x;
    int y;
};

} // namespace virtual_wall_ros2

#endif // VIRTUAL_WALL_LAYER_HPP
