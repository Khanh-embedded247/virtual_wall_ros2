// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from virtual_wall_ros2:srv/DeleteWall.idl
// generated code does not contain a copyright notice

#ifndef VIRTUAL_WALL_ROS2__SRV__DETAIL__DELETE_WALL__BUILDER_HPP_
#define VIRTUAL_WALL_ROS2__SRV__DETAIL__DELETE_WALL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "virtual_wall_ros2/srv/detail/delete_wall__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace virtual_wall_ros2
{

namespace srv
{

namespace builder
{

class Init_DeleteWall_Request_id
{
public:
  Init_DeleteWall_Request_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::virtual_wall_ros2::srv::DeleteWall_Request id(::virtual_wall_ros2::srv::DeleteWall_Request::_id_type arg)
  {
    msg_.id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::virtual_wall_ros2::srv::DeleteWall_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::virtual_wall_ros2::srv::DeleteWall_Request>()
{
  return virtual_wall_ros2::srv::builder::Init_DeleteWall_Request_id();
}

}  // namespace virtual_wall_ros2


namespace virtual_wall_ros2
{

namespace srv
{

namespace builder
{

class Init_DeleteWall_Response_status
{
public:
  Init_DeleteWall_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::virtual_wall_ros2::srv::DeleteWall_Response status(::virtual_wall_ros2::srv::DeleteWall_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::virtual_wall_ros2::srv::DeleteWall_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::virtual_wall_ros2::srv::DeleteWall_Response>()
{
  return virtual_wall_ros2::srv::builder::Init_DeleteWall_Response_status();
}

}  // namespace virtual_wall_ros2

#endif  // VIRTUAL_WALL_ROS2__SRV__DETAIL__DELETE_WALL__BUILDER_HPP_
