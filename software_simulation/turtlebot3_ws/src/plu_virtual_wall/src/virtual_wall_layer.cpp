#include "plu_virtual_wall/virtual_wall_layer.hpp"
#include "nav2_costmap_2d/costmap_2d.hpp"
#include "tf2/convert.h"
#include "tf2_ros/transform_listener.h"
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <yaml-cpp/yaml.h>
#include "nav_msgs/msg/occupancy_grid.hpp"
#include "nav2_util/validate_messages.hpp"

namespace virtual_wall_ros2
{

// Constructor: Khởi tạo bộ đệm biến đổi và trình nghe, đặt giá trị mặc định cho khung toàn cục và độ trễ biến đổi tf
VirtualWallLayer::VirtualWallLayer()
    : tf_buffer_(rclcpp::Clock::make_shared()), tf_listener_(tf_buffer_), global_frame_("map"), transform_tolerance_(tf2::durationFromSec(0.1)), has_updated_data_(false)
{
    RCLCPP_INFO(rclcpp::get_logger("virtual_wall_layer"), "VirtualWallLayer constructor called");
}
//hàm hủy fdde giải phóng bộ nhớ đệm 
VirtualWallLayer::~VirtualWallLayer()
{
}

// Hàm khởi tạo lớp VirtualWallLayer
void VirtualWallLayer::onInitialize()
{
    RCLCPP_INFO(logger_, "Khởi tạo VirtualWallLayer...");
// Khóa và kiểm tra node
    auto node = std::dynamic_pointer_cast<rclcpp_lifecycle::LifecycleNode>(node_.lock());
    if (!node)
    {
        RCLCPP_ERROR(logger_, "Failed to lock node");
        return;
    }
// Lấy các tham số
    getParameters();
// Cài đặt QoS cho việc subscribe bản đồ
    rclcpp::QoS map_qos(10);
    map_qos.transient_local();
    map_qos.reliable();
    map_qos.keep_last(1);

    RCLCPP_INFO(logger_, "Subscribing to the map topic with transient local durability");
// Tạo subscription cho topic bản đồ
    map_sub_ = node->create_subscription<nav_msgs::msg::OccupancyGrid>(
        "map", map_qos,
        std::bind(&VirtualWallLayer::incomingMap, this, std::placeholders::_1));
}

// Hàm lấy các tham số của lớp VirtualWallLayer
void VirtualWallLayer::getParameters()
{RCLCPP_INFO(logger_, "Getting parameters for VirtualWallLayer..."); 
    auto node = std::dynamic_pointer_cast<rclcpp_lifecycle::LifecycleNode>(node_.lock());
    if (!node)
    {
        throw std::runtime_error{"Failed to lock node"};
    }

    std::string points_yaml;
    node->declare_parameter("virtual_wall_points", rclcpp::ParameterValue(std::string("/home/khanh247/software_simulation/turtlebot3_ws/src/plu_virtual_wall/positions.yaml")));
    node->declare_parameter("global_frame", rclcpp::ParameterValue(std::string("map")));
    node->declare_parameter("transform_tolerance", rclcpp::ParameterValue(0.1));// // Khai báo tham số "transform_tolerance

    node->get_parameter("virtual_wall_points", points_yaml);
    if (!points_yaml.empty())
    {
        loadVirtualWallPoints(points_yaml);// Tải các điểm tường ảo từ file yaml
    }
    else
    {
        RCLCPP_ERROR(logger_, "Parameter 'virtual_wall_points' is empty");
    }

    std::string global_frame;
    node->get_parameter("global_frame", global_frame);
    global_frame_ = global_frame;

    double transform_tolerance;
    node->get_parameter("transform_tolerance", transform_tolerance);
    transform_tolerance_ = tf2::durationFromSec(transform_tolerance);
}

// Hàm tải các điểm tường ảo từ file yaml
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
            virtual_wall_points_.push_back(p); // Thêm điểm vào danh sách các điểm tường ảo
            RCLCPP_INFO(logger_, "Đã tải điểm: (%f, %f, %f)", p.x, p.y, p.z);
        }
    }
    catch (const std::exception &e)
    {
        RCLCPP_ERROR(logger_, "Failed to load virtual wall points: %s", e.what());
    }
}

// Hàm xử lý bản đồ
void VirtualWallLayer::processMap(const nav_msgs::msg::OccupancyGrid &map)
{
    RCLCPP_DEBUG(logger_, "VirtualWallLayer: Process map");

    unsigned int size_x = map.info.width;
    unsigned int size_y = map.info.height;

    RCLCPP_DEBUG(logger_, "VirtualWallLayer: Received a %d X %d map at %f m/pix", size_x, size_y, map.info.resolution);

    nav2_costmap_2d::Costmap2D *master = layered_costmap_->getCostmap(); // In thông tin kích thước và độ phân giải của bản đồ nhận được

    if (!layered_costmap_->isRolling() && (master->getSizeInCellsX() != size_x ||
                                           master->getSizeInCellsY() != size_y ||
                                           master->getResolution() != map.info.resolution ||
                                           master->getOriginX() != map.info.origin.position.x ||
                                           master->getOriginY() != map.info.origin.position.y ||
                                           !layered_costmap_->isSizeLocked()))
    {
        RCLCPP_INFO(logger_, "VirtualWallLayer: Resizing costmap to %d X %d at %f m/pix", size_x, size_y, map.info.resolution);
        resizeMap(size_x, size_y, map.info.resolution, map.info.origin.position.x, map.info.origin.position.y);
    }
// Khóa mutex để đảm bảo an toàn khi truy cập đồng thời
    std::lock_guard<nav2_costmap_2d::Costmap2D::mutex_t> guard(*master->getMutex());
// Cập nhật tất cả các ô trong costmap thành FREE_SPACE
    for (unsigned int i = 0; i < size_y; ++i)
    {
        for (unsigned int j = 0; j < size_x; ++j)
        {
            master->setCost(j, i, nav2_costmap_2d::FREE_SPACE);
        }
    }
// Đánh dấu các ô trong costmap thuộc vùng tường ảo
    markPolygonCells(*master, 0, 0, size_x, size_y);
    has_updated_data_ = true;// Đặt cờ dữ liệu đã được cập nhật

}

/// Hàm cập nhật các giới hạn của costmap
void VirtualWallLayer::updateBounds(double /*origin_x*/, double /*origin_y*/, double /*origin_yaw*/, double *min_x, double *min_y, double *max_x, double *max_y)
{
    if (!map_buffer_)
    {
        return;
    }
// Cập nhật các giá trị min_x, min_y, max_x, max_y dựa trên các điểm tường ảo
    for (const auto &point : virtual_wall_points_)
    {
        *min_x = std::min(*min_x, point.x);
        *min_y = std::min(*min_y, point.y);
        *max_x = std::max(*max_x, point.x);
        *max_y = std::max(*max_y, point.y);
    }
}

// Hàm cập nhật chi phí trong costmap
void VirtualWallLayer::updateCosts(nav2_costmap_2d::Costmap2D &master_grid, int min_i, int min_j, int max_i, int max_j)
{RCLCPP_DEBUG(logger_, "Updating costs..."); // In thông báo khi bắt đầu cập nhật chi phí
    markPolygonCells(master_grid, min_i, min_j, max_i, max_j); // Đánh dấu các ô thuộc vùng tường ảo trong costmap
RCLCPP_DEBUG(logger_, "Costs updated."); // In thông báo khi cập nhật xong chi phí
}

// Hàm đánh dấu các ô trong costmap thuộc vùng tường ảo
void VirtualWallLayer::markPolygonCells(nav2_costmap_2d::Costmap2D &master_grid, int min_i, int min_j, int max_i, int max_j)
{RCLCPP_DEBUG(logger_, "Marking polygon cells...");
    if (virtual_wall_points_.size() < 3)
    {
        RCLCPP_WARN(logger_, "Không đủ điểm để tạo thành một đa giác");
        return;
    }

    for (int mx = min_i; mx < max_i; mx++)
    {
        for (int my = min_j; my < max_j; my++)
        {
            double wx, wy;
            master_grid.mapToWorld(mx, my, wx, wy);// Chuyển đổi tọa độ ô lưới sang tọa độ thế giới

            if (isPointInPolygon(wx, wy, virtual_wall_points_))
            {
                master_grid.setCost(mx, my, nav2_costmap_2d::LETHAL_OBSTACLE);
            }
            
        }
    }
    RCLCPP_DEBUG(logger_, "Polygon cells marked.");
}

// Hàm kiểm tra xem một điểm có nằm trong đa giác hay không
bool VirtualWallLayer::isPointInPolygon(double x, double y, const std::vector<geometry_msgs::msg::Point> &polygon)
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

// Hàm nhận bản đồ mới từ topic
void VirtualWallLayer::incomingMap(const nav_msgs::msg::OccupancyGrid::SharedPtr new_map)
{RCLCPP_INFO(logger_, "Received new map.");
    if (!nav2_util::validateMsg(*new_map))
    {
        RCLCPP_ERROR(logger_, "Received map message is malformed. Rejecting.");
        return;
    }
    processMap(*new_map);// Xử lý bản đồ mới
}

// Hàm reset lớp VirtualWallLayer
void VirtualWallLayer::reset()
{
    has_updated_data_ = true;// Đặt cờ dữ liệu đã được cập nhật
    current_ = false;
}

// Hàm khớp kích thước costmap
void VirtualWallLayer::matchSize()
{
    nav2_costmap_2d::Costmap2D *master = layered_costmap_->getCostmap();
    resizeMap(master->getSizeInCellsX(), master->getSizeInCellsY(), master->getResolution(), master->getOriginX(), master->getOriginY()); // Thay đổi kích thước costmap
}

/// Hàm thay đổi kích thước costmap
void VirtualWallLayer::resizeMap(unsigned int size_x, unsigned int size_y, double resolution, double origin_x, double origin_y)
{
    layered_costmap_->resizeMap(size_x, size_y, resolution, origin_x, origin_y, true);// Gọi hàm resizeMap của layered_costmap
}

// Hàm kiểm tra xem lớp có thể bị xóa hay không
bool VirtualWallLayer::isClearable()
{
    return false;
}

} // namespace virtual_wall_ros2

PLUGINLIB_EXPORT_CLASS(virtual_wall_ros2::VirtualWallLayer, nav2_costmap_2d::Layer)
