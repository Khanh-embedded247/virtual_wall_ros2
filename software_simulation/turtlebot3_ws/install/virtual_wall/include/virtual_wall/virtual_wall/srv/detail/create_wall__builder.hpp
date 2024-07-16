// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from virtual_wall:srv/CreateWall.idl
// generated code does not contain a copyright notice

#ifndef VIRTUAL_WALL__SRV__DETAIL__CREATE_WALL__BUILDER_HPP_
#define VIRTUAL_WALL__SRV__DETAIL__CREATE_WALL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "virtual_wall/srv/detail/create_wall__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace virtual_wall
{

namespace srv
{

namespace builder
{

class Init_CreateWall_Request_end_point
{
public:
  explicit Init_CreateWall_Request_end_point(::virtual_wall::srv::CreateWall_Request & msg)
  : msg_(msg)
  {}
  ::virtual_wall::srv::CreateWall_Request end_point(::virtual_wall::srv::CreateWall_Request::_end_point_type arg)
  {
    msg_.end_point = std::move(arg);
    return std::move(msg_);
  }

private:
  ::virtual_wall::srv::CreateWall_Request msg_;
};

class Init_CreateWall_Request_start_point
{
public:
  explicit Init_CreateWall_Request_start_point(::virtual_wall::srv::CreateWall_Request & msg)
  : msg_(msg)
  {}
  Init_CreateWall_Request_end_point start_point(::virtual_wall::srv::CreateWall_Request::_start_point_type arg)
  {
    msg_.start_point = std::move(arg);
    return Init_CreateWall_Request_end_point(msg_);
  }

private:
  ::virtual_wall::srv::CreateWall_Request msg_;
};

class Init_CreateWall_Request_id
{
public:
  Init_CreateWall_Request_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CreateWall_Request_start_point id(::virtual_wall::srv::CreateWall_Request::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_CreateWall_Request_start_point(msg_);
  }

private:
  ::virtual_wall::srv::CreateWall_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::virtual_wall::srv::CreateWall_Request>()
{
  return virtual_wall::srv::builder::Init_CreateWall_Request_id();
}

}  // namespace virtual_wall


namespace virtual_wall
{

namespace srv
{

namespace builder
{

class Init_CreateWall_Response_status
{
public:
  Init_CreateWall_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::virtual_wall::srv::CreateWall_Response status(::virtual_wall::srv::CreateWall_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::virtual_wall::srv::CreateWall_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::virtual_wall::srv::CreateWall_Response>()
{
  return virtual_wall::srv::builder::Init_CreateWall_Response_status();
}

}  // namespace virtual_wall

#endif  // VIRTUAL_WALL__SRV__DETAIL__CREATE_WALL__BUILDER_HPP_
