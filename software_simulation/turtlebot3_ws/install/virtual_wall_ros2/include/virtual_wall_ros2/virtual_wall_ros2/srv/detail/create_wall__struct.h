// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from virtual_wall_ros2:srv/CreateWall.idl
// generated code does not contain a copyright notice

#ifndef VIRTUAL_WALL_ROS2__SRV__DETAIL__CREATE_WALL__STRUCT_H_
#define VIRTUAL_WALL_ROS2__SRV__DETAIL__CREATE_WALL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'start_point'
// Member 'end_point'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in srv/CreateWall in the package virtual_wall_ros2.
typedef struct virtual_wall_ros2__srv__CreateWall_Request
{
  uint32_t id;
  geometry_msgs__msg__Point start_point;
  geometry_msgs__msg__Point end_point;
} virtual_wall_ros2__srv__CreateWall_Request;

// Struct for a sequence of virtual_wall_ros2__srv__CreateWall_Request.
typedef struct virtual_wall_ros2__srv__CreateWall_Request__Sequence
{
  virtual_wall_ros2__srv__CreateWall_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} virtual_wall_ros2__srv__CreateWall_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/CreateWall in the package virtual_wall_ros2.
typedef struct virtual_wall_ros2__srv__CreateWall_Response
{
  bool status;
} virtual_wall_ros2__srv__CreateWall_Response;

// Struct for a sequence of virtual_wall_ros2__srv__CreateWall_Response.
typedef struct virtual_wall_ros2__srv__CreateWall_Response__Sequence
{
  virtual_wall_ros2__srv__CreateWall_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} virtual_wall_ros2__srv__CreateWall_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VIRTUAL_WALL_ROS2__SRV__DETAIL__CREATE_WALL__STRUCT_H_
