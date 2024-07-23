#include </home/khanh247/virtual_wall_ros2/software_simulation/turtlebot3_ws/src/plu_virtual_wall/include/plu_virtual_wall/virtual_wall_layer_test.hpp>

PLUGINLIB_EXPORT_CLASS(virtual_wall::VirtualWallLayer, nav2_costmap_2d::Layer)

namespace virtual_wall {

VirtualWallLayer::VirtualWallLayer()
: tf_listener_(tf_buffer_)
{
  wallmax_x = 0.0;
  wallmax_y = 0.0;
  wallmin_x = 0.0;
  wallmin_y = 0.0;
}

VirtualWallLayer::~VirtualWallLayer()
{
}

void VirtualWallLayer::onInitialize()
{
  auto node = node_.lock();
  if (!node) {
    RCLCPP_ERROR(rclcpp::get_logger("virtual_wall_layer"), "Unable to lock node in onInitialize");
    return;
  }
  matchSize();
  current_ = true;
  enabled_ = true;

  add_wall_sub_ = node->create_subscription<geometry_msgs::msg::PointStamped>(
    "/clicked_point", 1, std::bind(&VirtualWallLayer::AddWallCallback, this, std::placeholders::_1));
  wall_list_pub_ = node->create_publisher<std_msgs::msg::Int32>("/virtual_wall_list", 1);
  delete_wall_sub_ = node->create_subscription<std_msgs::msg::Int32>(
    "/delete_wall", 1, std::bind(&VirtualWallLayer::DeleteWallCallback, this, std::placeholders::_1));
  wall_maker_pub_ = node->create_publisher<visualization_msgs::msg::Marker>("virtual_wall_vis", 1);
}

void VirtualWallLayer::matchSize()
{
  boost::unique_lock<boost::recursive_mutex> lock(data_access_);
  auto master = layered_costmap_->getCostmap();
  resolution = master->getResolution();

  global_frame_ = layered_costmap_->getGlobalFrameID();
  map_frame_ = "map";
}

void VirtualWallLayer::updateBounds(double robot_x, double robot_y, double robot_yaw, double* min_x, double* min_y, double* max_x, double* max_y)
{
  *min_x = std::min(wallmin_x, *min_x);
  *min_y = std::min(wallmin_y, *min_y);
  *max_x = std::max(wallmax_x, *max_x);
  *max_y = std::max(wallmax_y, *max_y);
}

void VirtualWallLayer::updateCosts(nav2_costmap_2d::Costmap2D& master_grid, int min_i, int min_j, int max_i, int max_j)
{
  boost::unique_lock<boost::recursive_mutex> lock(data_access_);
  auto node = node_.lock();
  if (!node) {
    RCLCPP_ERROR(rclcpp::get_logger("virtual_wall_layer"), "Unable to lock node in updateCosts");
    return;
  }

  if (global_frame_ == map_frame_) {
    visualization_msgs::msg::Marker node_vis;
    node_vis.header.frame_id = map_frame_;
    node_vis.header.stamp = node->now();
    node_vis.type = visualization_msgs::msg::Marker::CUBE_LIST;
    node_vis.action = visualization_msgs::msg::Marker::ADD;
    node_vis.id = 0;
    node_vis.pose.orientation.x = 0.0;
    node_vis.pose.orientation.y = 0.0;
    node_vis.pose.orientation.z = 0.0;
    node_vis.pose.orientation.w = 1.0;
    node_vis.color.a = 1.0;
    node_vis.color.r = 1.0;
    node_vis.color.g = 0.0;
    node_vis.color.b = 0.0;

    node_vis.scale.x = resolution;
    node_vis.scale.y = resolution;
    node_vis.scale.z = 0.3;

    geometry_msgs::msg::Point pt;
    pt.z = 0.15;
    for (size_t i = 0; i < wallPoint.size(); i++) {
      std_msgs::msg::Int32 msg;
      msg.data = wallPoint[i].id;
      wall_list_pub_->publish(msg);
      for (size_t j = 0; j < wallPoint[i].polygon.points.size(); j++) {
        unsigned int pixle_x;
        unsigned int pixle_y;
        bool ret = master_grid.worldToMap(wallPoint[i].polygon.points[j].x, wallPoint[i].polygon.points[j].y, pixle_x, pixle_y);
        if (ret) {
          master_grid.setCost(pixle_x, pixle_y, nav2_costmap_2d::LETHAL_OBSTACLE);
          pt.x = wallPoint[i].polygon.points[j].x;
          pt.y = wallPoint[i].polygon.points[j].y;
          node_vis.points.push_back(pt);
        }
      }
    }
    wall_maker_pub_->publish(node_vis);
  } else {
    geometry_msgs::msg::TransformStamped transform;
    try {
      transform = tf_buffer_.lookupTransform(global_frame_, map_frame_, tf2::TimePointZero);
    } catch (tf2::TransformException &ex) {
      RCLCPP_ERROR(rclcpp::get_logger("virtual_wall_layer"), "%s", ex.what());
      return;
    }

    tf2::Transform tf2_transform;
    tf2::convert(transform.transform, tf2_transform);

    for (size_t i = 0; i < wallPoint.size(); i++) {
      std_msgs::msg::Int32 msg;
      msg.data = wallPoint[i].id;
      wall_list_pub_->publish(msg);
      double wx, wy;
      for (size_t j = 0; j < wallPoint[i].polygon.points.size(); j++) {
        unsigned int pixle_x;
        unsigned int pixle_y;
        wx = wallPoint[i].polygon.points[j].x;
        wy = wallPoint[i].polygon.points[j].y;
        tf2::Vector3 p(wx, wy, 0);
        p = tf2_transform * p;
        bool ret = master_grid.worldToMap(p.x(), p.y(), pixle_x, pixle_y);
        if (ret) {
          master_grid.setCost(pixle_x, pixle_y, nav2_costmap_2d::LETHAL_OBSTACLE);
        }
      }
    }
  }
}

bool VirtualWallLayer::WallInterpolation()
{
  double pixle_x[2];
  double pixle_y[2];
  double k, b;
  for (size_t i = 0; i < 2; i++) {
    if (fabs(wallPoint.back().polygon.points[0].x - wallPoint.back().polygon.points[1].x) > 
        fabs(wallPoint.back().polygon.points[0].y - wallPoint.back().polygon.points[1].y)) {
      pixle_x[i] = wallPoint.back().polygon.points[i].x;
      pixle_y[i] = wallPoint.back().polygon.points[i].y;
    } else {
      pixle_x[i] = wallPoint.back().polygon.points[i].y;
      pixle_y[i] = wallPoint.back().polygon.points[i].x;
    }
  }

  if (pixle_x[0] == pixle_x[1]) {
    return false;
  }

  if (pixle_x[0] < pixle_x[1]) {
    k = (pixle_y[1] - pixle_y[0]) / (pixle_x[1] - pixle_x[0]);
    b = pixle_y[0] - k * pixle_x[0];
    for (pixle_x[0] += resolution; pixle_x[0] < pixle_x[1]; pixle_x[0] += resolution) {
      geometry_msgs::msg::Point32 pt;
      if (fabs(wallPoint.back().polygon.points[0].x - wallPoint.back().polygon.points[1].x) >
          fabs(wallPoint.back().polygon.points[0].y - wallPoint.back().polygon.points[1].y)) {
        pt.x = pixle_x[0];
        pt.y = k * pixle_x[0] + b;
      } else {
        pt.y = pixle_x[0];
        pt.x = k * pixle_x[0] + b;
      }
      wallPoint.back().polygon.points.push_back(pt);
    }
  } else {
    k = (pixle_y[0] - pixle_y[1]) / (pixle_x[0] - pixle_x[1]);
    b = pixle_y[1] - k * pixle_x[1];
    for (pixle_x[1] += resolution; pixle_x[1] < pixle_x[0]; pixle_x[1] += resolution) {
      geometry_msgs::msg::Point32 pt;
      if (fabs(wallPoint.back().polygon.points[0].x - wallPoint.back().polygon.points[1].x) >
          fabs(wallPoint.back().polygon.points[0].y - wallPoint.back().polygon.points[1].y)) {
        pt.x = pixle_x[1];
        pt.y = k * pixle_x[1] + b;
      } else {
        pt.y = pixle_x[1];
        pt.x = k * pixle_x[1] + b;
      }
      wallPoint.back().polygon.points.push_back(pt);
    }
  }

  return true;
}

void VirtualWallLayer::AddWallCallback(const geometry_msgs::msg::PointStamped::SharedPtr msg)
{
  geometry_msgs::msg::Point32 p;
  p.x = msg->point.x;
  p.y = msg->point.y;
  p.z = 0;
  v_wall.back().polygon.points.push_back(p);
  if (v_wall.back().polygon.points.size() == 2) {
    WallInterpolation();
    wallPoint.push_back(v_wall.back());
    v_wall.back().polygon.points.clear();
  }

  if (p.x > wallmax_x) wallmax_x = p.x;
  if (p.x < wallmin_x) wallmin_x = p.x;
  if (p.y > wallmax_y) wallmax_y = p.y;
  if (p.y < wallmin_y) wallmin_y = p.y;
}

void VirtualWallLayer::DeleteWallCallback(const std_msgs::msg::Int32::SharedPtr msg)
{
  int index = 0;
  for (auto it = wallPoint.begin(); it != wallPoint.end(); ++it, ++index) {
    if (msg->data == it->id) {
      wallPoint.erase(it);
      return;
    }
  }
}

}  // namespace virtual_wall
