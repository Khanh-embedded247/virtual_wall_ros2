// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from virtual_wall:srv/DeleteAll.idl
// generated code does not contain a copyright notice

#ifndef VIRTUAL_WALL__SRV__DETAIL__DELETE_ALL__BUILDER_HPP_
#define VIRTUAL_WALL__SRV__DETAIL__DELETE_ALL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "virtual_wall/srv/detail/delete_all__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace virtual_wall
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::virtual_wall::srv::DeleteAll_Request>()
{
  return ::virtual_wall::srv::DeleteAll_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace virtual_wall


namespace virtual_wall
{

namespace srv
{

namespace builder
{

class Init_DeleteAll_Response_status
{
public:
  Init_DeleteAll_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::virtual_wall::srv::DeleteAll_Response status(::virtual_wall::srv::DeleteAll_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::virtual_wall::srv::DeleteAll_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::virtual_wall::srv::DeleteAll_Response>()
{
  return virtual_wall::srv::builder::Init_DeleteAll_Response_status();
}

}  // namespace virtual_wall

#endif  // VIRTUAL_WALL__SRV__DETAIL__DELETE_ALL__BUILDER_HPP_
