#include "/home/khanh247/software_simulation/turtlebot3_ws/src/plu_virtual_wall/include/plu_virtual_wall/virtual_wall_layer_test.hpp"
#include "nav2_costmap_2d/costmap_2d.hpp"
#include "tf2/convert.h"
#include "tf2_ros/transform_listener.h"
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <yaml-cpp/yaml.h>

namespace virtual_wall_ros2
{

VirtualWallLayer::VirtualWallLayer()
: tf_buffer_(rclcpp::Clock::make_shared()), tf_listener_(tf_buffer_), global_frame_("map")
{
    RCLCPP_INFO(rclcpp::get_logger("virtual_wall_layer"), "VirtualWallLayer constructor called");
}

VirtualWallLayer::~VirtualWallLayer()
{
}

void VirtualWallLayer::onInitialize()
{
    RCLCPP_INFO(logger_, "Khởi tạo VirtualWallLayer...");

    auto node = node_.lock();
    if (!node)
    {
        RCLCPP_ERROR(logger_, "Failed to lock node");
        return;
    }

    // Khai báo các tham số
    node->declare_parameter("virtual_wall_points", rclcpp::ParameterValue(std::string("/home/khanh247/software_simulation/turtlebot3_ws/src/plu_virtual_wall/positions.yaml")));
    node->declare_parameter("global_frame", rclcpp::ParameterValue(std::string("map")));

    std::string points_yaml;
    std::string global_frame;

    if (!node->get_parameter("virtual_wall_points", points_yaml)) {
        RCLCPP_ERROR(logger_, "Failed to get parameter 'virtual_wall_points'");
    } else {
        RCLCPP_INFO(logger_, "Giá trị tham số 'virtual_wall_points': %s", points_yaml.c_str());
    }

    if (!node->get_parameter("global_frame", global_frame)) {
        RCLCPP_ERROR(logger_, "Failed to get parameter 'global_frame'");
    } else {
        global_frame_ = global_frame;
        RCLCPP_INFO(logger_, "Giá trị tham số 'global_frame': %s", global_frame_.c_str());
    }

    if (!points_yaml.empty())
    {
        loadVirtualWallPoints(points_yaml);
    }
    else
    {
        RCLCPP_ERROR(logger_, "Parameter 'virtual_wall_points' is empty");
    }
}

void VirtualWallLayer::loadVirtualWallPoints(const std::string &filename)
{
    RCLCPP_INFO(logger_, "Tải các điểm tường ảo từ tệp: %s", filename.c_str());
    try
    {
        YAML::Node yaml = YAML::LoadFile(filename);
        for (const auto &point : yaml["points"])
        {
            geometry_msgs::msg::Point p;
            p.x = point["x"].as<double>();
            p.y = point["y"].as<double>();
            p.z = point["z"].as<double>();
            virtual_wall_points_.push_back(p);
            RCLCPP_INFO(logger_, "Đã tải điểm: (%f, %f, %f)", p.x, p.y, p.z);
        }
    }
    catch (const std::exception &e)
    {
        RCLCPP_ERROR(logger_, "Failed to load virtual wall points: %s", e.what());
    }
}

void VirtualWallLayer::updateBounds(double /*origin_x*/, double /*origin_y*/, double /*origin_yaw*/, double* min_x, double* min_y, double* max_x, double* max_y)
{
    RCLCPP_INFO(logger_, "Cập nhật biên...");
    for (const auto& point : virtual_wall_points_)
    {
        *min_x = std::min(*min_x, point.x);
        *min_y = std::min(*min_y, point.y);
        *max_x = std::max(*max_x, point.x);
        *max_y = std::max(*max_y, point.y);
    }
    RCLCPP_INFO(logger_, "Biên cập nhật: min_x = %f, min_y = %f, max_x = %f, max_y = %f", *min_x, *min_y, *max_x, *max_y);
}

void VirtualWallLayer::updateCosts(nav2_costmap_2d::Costmap2D& master_grid, int min_i, int min_j, int max_i, int max_j)
{
    RCLCPP_INFO(logger_, "Cập nhật chi phí...");
    markPolygonCells(master_grid, min_i, min_j, max_i, max_j);
}

void VirtualWallLayer::markPolygonCells(nav2_costmap_2d::Costmap2D& master_grid, int min_i, int min_j, int max_i, int max_j)
{
    RCLCPP_INFO(logger_, "Đánh dấu các ô trong vùng tường ảo...");
    if (virtual_wall_points_.size() < 3)
    {
        RCLCPP_WARN(logger_, "Không đủ điểm để tạo thành một đa giác");
        return;
    }

    geometry_msgs::msg::TransformStamped transform;
    try
    {
        transform = tf_buffer_.lookupTransform(global_frame_, "base_link", tf2::TimePointZero);
    }
    catch (tf2::TransformException &ex)
    {
        RCLCPP_WARN(logger_, "Không thể biến đổi: %s", ex.what());
        return;
    }

    RCLCPP_INFO(logger_, "Đã nhận được biến đổi");

    for (unsigned int mx = min_i; mx < max_i; mx++)
    {
        for (unsigned int my = min_j; my < max_j; my++)
        {
            double wx, wy;
            master_grid.mapToWorld(mx, my, wx, wy);

            geometry_msgs::msg::PointStamped point_in, point_out;
            point_in.point.x = wx;
            point_in.point.y = wy;
            point_in.point.z = 0;
            point_in.header.frame_id = global_frame_;

            tf2::doTransform(point_in, point_out, transform);

            if (isPointInPolygon(point_out.point.x, point_out.point.y, virtual_wall_points_))
            {
                RCLCPP_INFO(logger_, "Đặt chi phí tại (%f, %f)", point_out.point.x, point_out.point.y);
                master_grid.setCost(mx, my, nav2_costmap_2d::LETHAL_OBSTACLE);
            }
        }
    }
}

bool VirtualWallLayer::isPointInPolygon(double x, double y, const std::vector<geometry_msgs::msg::Point>& polygon)
{
    int i, j, nvert = polygon.size();
    bool c = false;
    for (i = 0, j = nvert - 1; i < nvert; j = i++)
    {
        if (((polygon[i].y >= y) != (polygon[j].y >= y)) &&
            (x <= (polygon[j].x - polygon[i].x) * (y - polygon[i].y) / (polygon[j].y - polygon[i].y) + polygon[i].x))
        {
            c = !c;
        }
    }
    return c;
}

void VirtualWallLayer::reset()
{
    // Logic to reset the layer if needed
}

bool VirtualWallLayer::isClearable()
{
    return true; // or false depending on whether you want the layer to be clearable
}

rcl_interfaces::msg::SetParametersResult VirtualWallLayer::dynamicParametersCallback(std::vector<rclcpp::Parameter> parameters)
{
    std::lock_guard<std::mutex> guard(layer_mutex_);
    rcl_interfaces::msg::SetParametersResult result;

    for (auto parameter : parameters) {
        const auto & param_type = parameter.get_type();
        const auto & param_name = parameter.get_name();

        if (param_name == name_ + "." + "enabled" && param_type == rclcpp::ParameterType::PARAMETER_BOOL) {
            enabled_ = parameter.as_bool();
        }
    }
    result.successful = true;
    return result;
}

}  // namespace virtual_wall_ros2

PLUGINLIB_EXPORT_CLASS(virtual_wall_ros2::VirtualWallLayer, nav2_costmap_2d::Layer)
