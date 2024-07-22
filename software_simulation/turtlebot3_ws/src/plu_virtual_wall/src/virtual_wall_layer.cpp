#include "/home/khanh247/virtual_wall_ros2/software_simulation/turtlebot3_ws/src/plu_virtual_wall/include/plu_virtual_wall/virtual_wall_layer.hpp"
#include <pluginlib/class_list_macros.hpp>
namespace virtual_wall_ros2
{

  VirtualWallLayer::VirtualWallLayer()
      : tf_buffer_(std::make_shared<rclcpp::Clock>(RCL_ROS_TIME)), tf_listener_(tf_buffer_), map_received_(false)
  {
  }

  void VirtualWallLayer::onInitialize()
  {
    auto node = node_.lock();
    if (!node)
    {
      RCLCPP_ERROR(rclcpp::get_logger("virtual_wall_layer"), "Unable to lock node in onInitialize");
      return;
    }

    node->declare_parameter("global_frame", rclcpp::ParameterValue(std::string("map")));
    node->declare_parameter("map_frame", rclcpp::ParameterValue(std::string("map")));
    node->declare_parameter("virtual_wall_points_file", rclcpp::ParameterValue(std::string("")));

    node->get_parameter("global_frame", global_frame_);
    node->get_parameter("map_frame", map_frame_);
    node->get_parameter("virtual_wall_points_file", virtual_wall_points_file_);

    RCLCPP_INFO(node->get_logger(), "Global frame: %s", global_frame_.c_str());
    RCLCPP_INFO(node->get_logger(), "Map frame: %s", map_frame_.c_str());
    RCLCPP_INFO(node->get_logger(), "Virtual wall points file: %s", virtual_wall_points_file_.c_str());

    map_sub_ = node->create_subscription<nav_msgs::msg::OccupancyGrid>(
        "/map", rclcpp::QoS(10).transient_local(),
        std::bind(&VirtualWallLayer::mapCallback, this, std::placeholders::_1));

    point_cloud_pub_ = node->create_publisher<sensor_msgs::msg::PointCloud2>(
        "virtual_wall_cloud", rclcpp::SystemDefaultsQoS());

    loadVirtualWallPoints(virtual_wall_points_file_);
    timer_ = node->create_wall_timer(
        std::chrono::seconds(1),
        std::bind(&VirtualWallLayer::publishCloud, this));
    while (rclcpp::ok())
  {
    if (tf_buffer_.canTransform(global_frame_, "base_link", tf2::TimePointZero, tf2::durationFromSec(1.0)))
    {
      RCLCPP_INFO(node->get_logger(), "Transform available from base_link to %s", global_frame_.c_str());
      break;
    }
    else
    {
      RCLCPP_WARN(node->get_logger(), "Waiting for transform from base_link to %s", global_frame_.c_str());
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
  }
  }

  void VirtualWallLayer::mapCallback(const nav_msgs::msg::OccupancyGrid::SharedPtr msg)
  {
    auto node = node_.lock();
    if (!node)
    {
      RCLCPP_ERROR(rclcpp::get_logger("virtual_wall_layer"), "Unable to lock node in mapCallback");
      return;
    }

    RCLCPP_INFO(node->get_logger(), "Map received with resolution %f and dimensions [%d, %d]",
                msg->info.resolution, msg->info.width, msg->info.height);

    map_received_ = true;
    map_info_ = msg->info;
  }

  void VirtualWallLayer::loadVirtualWallPoints(const std::string &filename)
  {
    auto node = node_.lock();
    if (!node)
    {
      RCLCPP_ERROR(rclcpp::get_logger("virtual_wall_layer"), "Unable to lock node in loadVirtualWallPoints");
      return;
    }

    try
    {
      YAML::Node config = YAML::LoadFile(filename);
      if (!config["points"])
      {
        RCLCPP_ERROR(node->get_logger(), "Invalid YAML file: missing 'points' key");
        return;
      }

      for (const auto &point : config["points"])
      {
        if (!point["x"] || !point["y"] || !point["z"])
        {
          RCLCPP_ERROR(node->get_logger(), "Invalid point format in YAML file: %s", filename.c_str());
          continue;
        }
        geometry_msgs::msg::Point p;
        p.x = point["x"].as<double>();
        p.y = point["y"].as<double>();
        p.z = point["z"].as<double>();
        virtual_wall_points_.push_back(p);
        RCLCPP_INFO(node->get_logger(), "Loaded point (x: %f, y: %f, z: %f)", p.x, p.y, p.z);
      }

      createLineCloud();
    }
    catch (const std::exception &e)
    {
      RCLCPP_ERROR(node->get_logger(), "Failed to load virtual wall points from file: %s", e.what());
    }
  }

  void VirtualWallLayer::createLineCloud()
  {
    RCLCPP_INFO(rclcpp::get_logger("virtual_wall_layer"), "Creating line cloud");

    for (size_t i = 0; i < virtual_wall_points_.size() - 1; ++i)
    {
      int x0, y0, x1, y1;
      x0 = (virtual_wall_points_[i].x - map_info_.origin.position.x) / map_info_.resolution;
      y0 = (virtual_wall_points_[i].y - map_info_.origin.position.y) / map_info_.resolution;
      x1 = (virtual_wall_points_[i + 1].x - map_info_.origin.position.x) / map_info_.resolution;
      y1 = (virtual_wall_points_[i + 1].y - map_info_.origin.position.y) / map_info_.resolution;

      getLineCells(x0, x1, y0, y1, line_cells_);
    }

    RCLCPP_INFO(rclcpp::get_logger("virtual_wall_layer"), "Line cloud created");
  }

  void VirtualWallLayer::getLineCells(int x0, int x1, int y0, int y1, std::vector<std::pair<int, int>> &pts)
  {

    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2, e2;

    while (true)
    {
      RCLCPP_INFO(rclcpp::get_logger("virtual_wall_layer"), "get Line Cells");
      pts.emplace_back(x0, y0);
      if (x0 == x1 && y0 == y1)
        break;
      e2 = err;
      if (e2 > -dx)
      {
        err -= dy;
        x0 += sx;
      }
      if (e2 < dy)
      {
        err += dx;
        y0 += sy;
      }
    }
  }

  void VirtualWallLayer::publishCloud()
  {
    auto node = node_.lock();
    if (!node)
    {
      RCLCPP_ERROR(rclcpp::get_logger("virtual_wall_layer"), "Unable to lock node in publishCloud");
      return;
    }

    RCLCPP_INFO(node->get_logger(), "Publishing virtual wall cloud");

    pcl::PointCloud<pcl::PointXYZ> pcl_cloud;
    for (const auto &cell : line_cells_)
    {
      double wx = cell.first * map_info_.resolution + map_info_.origin.position.x;
      double wy = cell.second * map_info_.resolution + map_info_.origin.position.y;
      pcl_cloud.push_back(pcl::PointXYZ(wx, wy, 0.0));
    }

    sensor_msgs::msg::PointCloud2 cloud;
    pcl::toROSMsg(pcl_cloud, cloud);

    cloud.header.frame_id = global_frame_;
    cloud.header.stamp = node->now();
    point_cloud_pub_->publish(cloud);

    RCLCPP_INFO(node->get_logger(), "Published virtual wall cloud with %zu points", pcl_cloud.size());
  }

  void VirtualWallLayer::updateBounds(double origin_x, double origin_y, double origin_yaw, double *min_x, double *min_y, double *max_x, double *max_y)
  {
    auto node = node_.lock();
    if (!node)
    {
      RCLCPP_ERROR(rclcpp::get_logger("virtual_wall_layer"), "Unable to lock node in updateBounds");
      return;
    }

    if (!map_received_)
    {
      RCLCPP_WARN(node->get_logger(), "Map not received yet, skipping updateBounds");
      return;
    }

    for (const auto &point : virtual_wall_points_)
    {
      *min_x = std::min(*min_x, point.x);
      *min_y = std::min(*min_y, point.y);
      *max_x = std::max(*max_x, point.x);
      *max_y = std::max(*max_y, point.y);
    }

    RCLCPP_INFO(node->get_logger(), "Updated bounds: min_x=%f, min_y=%f, max_x=%f, max_y=%f", *min_x, *min_y, *max_x, *max_y);
  }

  void VirtualWallLayer::updateCosts(nav2_costmap_2d::Costmap2D &master_grid, int min_i, int min_j, int max_i, int max_j)
  {
    auto node = node_.lock();
    if (!node)
    {
      RCLCPP_ERROR(rclcpp::get_logger("virtual_wall_layer"), "Unable to lock node in updateCosts");
      return;
    }

    if (!map_received_)
    {
      RCLCPP_WARN(node->get_logger(), "Map not received yet, skipping updateCosts");
      return;
    }

    for (const auto &cell : line_cells_)
    {
      unsigned int mx, my;
      if (master_grid.worldToMap(cell.first, cell.second, mx, my))
      {
        if (mx >= (unsigned int)min_i && mx <= (unsigned int)max_i && my >= (unsigned int)min_j && my <= (unsigned int)max_j)
        {
          master_grid.setCost(mx, my, nav2_costmap_2d::LETHAL_OBSTACLE);
        }
      }
    }

    RCLCPP_INFO(node->get_logger(), "Updated costs in the costmap");
  }

} // namespace virtual_wall_ros2

PLUGINLIB_EXPORT_CLASS(virtual_wall_ros2::VirtualWallLayer, nav2_costmap_2d::Layer)
