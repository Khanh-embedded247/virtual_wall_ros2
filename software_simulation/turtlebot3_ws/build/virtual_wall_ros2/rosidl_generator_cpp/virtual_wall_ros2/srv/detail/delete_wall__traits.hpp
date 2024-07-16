// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from virtual_wall_ros2:srv/DeleteWall.idl
// generated code does not contain a copyright notice

#ifndef VIRTUAL_WALL_ROS2__SRV__DETAIL__DELETE_WALL__TRAITS_HPP_
#define VIRTUAL_WALL_ROS2__SRV__DETAIL__DELETE_WALL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "virtual_wall_ros2/srv/detail/delete_wall__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace virtual_wall_ros2
{

namespace srv
{

inline void to_flow_style_yaml(
  const DeleteWall_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DeleteWall_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DeleteWall_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace virtual_wall_ros2

namespace rosidl_generator_traits
{

[[deprecated("use virtual_wall_ros2::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const virtual_wall_ros2::srv::DeleteWall_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  virtual_wall_ros2::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use virtual_wall_ros2::srv::to_yaml() instead")]]
inline std::string to_yaml(const virtual_wall_ros2::srv::DeleteWall_Request & msg)
{
  return virtual_wall_ros2::srv::to_yaml(msg);
}

template<>
inline const char * data_type<virtual_wall_ros2::srv::DeleteWall_Request>()
{
  return "virtual_wall_ros2::srv::DeleteWall_Request";
}

template<>
inline const char * name<virtual_wall_ros2::srv::DeleteWall_Request>()
{
  return "virtual_wall_ros2/srv/DeleteWall_Request";
}

template<>
struct has_fixed_size<virtual_wall_ros2::srv::DeleteWall_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<virtual_wall_ros2::srv::DeleteWall_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<virtual_wall_ros2::srv::DeleteWall_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace virtual_wall_ros2
{

namespace srv
{

inline void to_flow_style_yaml(
  const DeleteWall_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DeleteWall_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DeleteWall_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace virtual_wall_ros2

namespace rosidl_generator_traits
{

[[deprecated("use virtual_wall_ros2::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const virtual_wall_ros2::srv::DeleteWall_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  virtual_wall_ros2::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use virtual_wall_ros2::srv::to_yaml() instead")]]
inline std::string to_yaml(const virtual_wall_ros2::srv::DeleteWall_Response & msg)
{
  return virtual_wall_ros2::srv::to_yaml(msg);
}

template<>
inline const char * data_type<virtual_wall_ros2::srv::DeleteWall_Response>()
{
  return "virtual_wall_ros2::srv::DeleteWall_Response";
}

template<>
inline const char * name<virtual_wall_ros2::srv::DeleteWall_Response>()
{
  return "virtual_wall_ros2/srv/DeleteWall_Response";
}

template<>
struct has_fixed_size<virtual_wall_ros2::srv::DeleteWall_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<virtual_wall_ros2::srv::DeleteWall_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<virtual_wall_ros2::srv::DeleteWall_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<virtual_wall_ros2::srv::DeleteWall>()
{
  return "virtual_wall_ros2::srv::DeleteWall";
}

template<>
inline const char * name<virtual_wall_ros2::srv::DeleteWall>()
{
  return "virtual_wall_ros2/srv/DeleteWall";
}

template<>
struct has_fixed_size<virtual_wall_ros2::srv::DeleteWall>
  : std::integral_constant<
    bool,
    has_fixed_size<virtual_wall_ros2::srv::DeleteWall_Request>::value &&
    has_fixed_size<virtual_wall_ros2::srv::DeleteWall_Response>::value
  >
{
};

template<>
struct has_bounded_size<virtual_wall_ros2::srv::DeleteWall>
  : std::integral_constant<
    bool,
    has_bounded_size<virtual_wall_ros2::srv::DeleteWall_Request>::value &&
    has_bounded_size<virtual_wall_ros2::srv::DeleteWall_Response>::value
  >
{
};

template<>
struct is_service<virtual_wall_ros2::srv::DeleteWall>
  : std::true_type
{
};

template<>
struct is_service_request<virtual_wall_ros2::srv::DeleteWall_Request>
  : std::true_type
{
};

template<>
struct is_service_response<virtual_wall_ros2::srv::DeleteWall_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // VIRTUAL_WALL_ROS2__SRV__DETAIL__DELETE_WALL__TRAITS_HPP_
