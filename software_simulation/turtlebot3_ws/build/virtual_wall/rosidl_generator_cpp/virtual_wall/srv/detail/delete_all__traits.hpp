// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from virtual_wall:srv/DeleteAll.idl
// generated code does not contain a copyright notice

#ifndef VIRTUAL_WALL__SRV__DETAIL__DELETE_ALL__TRAITS_HPP_
#define VIRTUAL_WALL__SRV__DETAIL__DELETE_ALL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "virtual_wall/srv/detail/delete_all__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace virtual_wall
{

namespace srv
{

inline void to_flow_style_yaml(
  const DeleteAll_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DeleteAll_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DeleteAll_Request & msg, bool use_flow_style = false)
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

}  // namespace virtual_wall

namespace rosidl_generator_traits
{

[[deprecated("use virtual_wall::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const virtual_wall::srv::DeleteAll_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  virtual_wall::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use virtual_wall::srv::to_yaml() instead")]]
inline std::string to_yaml(const virtual_wall::srv::DeleteAll_Request & msg)
{
  return virtual_wall::srv::to_yaml(msg);
}

template<>
inline const char * data_type<virtual_wall::srv::DeleteAll_Request>()
{
  return "virtual_wall::srv::DeleteAll_Request";
}

template<>
inline const char * name<virtual_wall::srv::DeleteAll_Request>()
{
  return "virtual_wall/srv/DeleteAll_Request";
}

template<>
struct has_fixed_size<virtual_wall::srv::DeleteAll_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<virtual_wall::srv::DeleteAll_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<virtual_wall::srv::DeleteAll_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace virtual_wall
{

namespace srv
{

inline void to_flow_style_yaml(
  const DeleteAll_Response & msg,
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
  const DeleteAll_Response & msg,
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

inline std::string to_yaml(const DeleteAll_Response & msg, bool use_flow_style = false)
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

}  // namespace virtual_wall

namespace rosidl_generator_traits
{

[[deprecated("use virtual_wall::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const virtual_wall::srv::DeleteAll_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  virtual_wall::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use virtual_wall::srv::to_yaml() instead")]]
inline std::string to_yaml(const virtual_wall::srv::DeleteAll_Response & msg)
{
  return virtual_wall::srv::to_yaml(msg);
}

template<>
inline const char * data_type<virtual_wall::srv::DeleteAll_Response>()
{
  return "virtual_wall::srv::DeleteAll_Response";
}

template<>
inline const char * name<virtual_wall::srv::DeleteAll_Response>()
{
  return "virtual_wall/srv/DeleteAll_Response";
}

template<>
struct has_fixed_size<virtual_wall::srv::DeleteAll_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<virtual_wall::srv::DeleteAll_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<virtual_wall::srv::DeleteAll_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<virtual_wall::srv::DeleteAll>()
{
  return "virtual_wall::srv::DeleteAll";
}

template<>
inline const char * name<virtual_wall::srv::DeleteAll>()
{
  return "virtual_wall/srv/DeleteAll";
}

template<>
struct has_fixed_size<virtual_wall::srv::DeleteAll>
  : std::integral_constant<
    bool,
    has_fixed_size<virtual_wall::srv::DeleteAll_Request>::value &&
    has_fixed_size<virtual_wall::srv::DeleteAll_Response>::value
  >
{
};

template<>
struct has_bounded_size<virtual_wall::srv::DeleteAll>
  : std::integral_constant<
    bool,
    has_bounded_size<virtual_wall::srv::DeleteAll_Request>::value &&
    has_bounded_size<virtual_wall::srv::DeleteAll_Response>::value
  >
{
};

template<>
struct is_service<virtual_wall::srv::DeleteAll>
  : std::true_type
{
};

template<>
struct is_service_request<virtual_wall::srv::DeleteAll_Request>
  : std::true_type
{
};

template<>
struct is_service_response<virtual_wall::srv::DeleteAll_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // VIRTUAL_WALL__SRV__DETAIL__DELETE_ALL__TRAITS_HPP_
