// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from virtual_wall_ros2:srv/DeleteAll.idl
// generated code does not contain a copyright notice

#ifndef VIRTUAL_WALL_ROS2__SRV__DETAIL__DELETE_ALL__STRUCT_H_
#define VIRTUAL_WALL_ROS2__SRV__DETAIL__DELETE_ALL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/DeleteAll in the package virtual_wall_ros2.
typedef struct virtual_wall_ros2__srv__DeleteAll_Request
{
  uint8_t structure_needs_at_least_one_member;
} virtual_wall_ros2__srv__DeleteAll_Request;

// Struct for a sequence of virtual_wall_ros2__srv__DeleteAll_Request.
typedef struct virtual_wall_ros2__srv__DeleteAll_Request__Sequence
{
  virtual_wall_ros2__srv__DeleteAll_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} virtual_wall_ros2__srv__DeleteAll_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/DeleteAll in the package virtual_wall_ros2.
typedef struct virtual_wall_ros2__srv__DeleteAll_Response
{
  bool status;
} virtual_wall_ros2__srv__DeleteAll_Response;

// Struct for a sequence of virtual_wall_ros2__srv__DeleteAll_Response.
typedef struct virtual_wall_ros2__srv__DeleteAll_Response__Sequence
{
  virtual_wall_ros2__srv__DeleteAll_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} virtual_wall_ros2__srv__DeleteAll_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VIRTUAL_WALL_ROS2__SRV__DETAIL__DELETE_ALL__STRUCT_H_
