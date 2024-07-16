// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from virtual_wall:srv/DeleteWall.idl
// generated code does not contain a copyright notice

#ifndef VIRTUAL_WALL__SRV__DETAIL__DELETE_WALL__STRUCT_H_
#define VIRTUAL_WALL__SRV__DETAIL__DELETE_WALL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/DeleteWall in the package virtual_wall.
typedef struct virtual_wall__srv__DeleteWall_Request
{
  uint32_t id;
} virtual_wall__srv__DeleteWall_Request;

// Struct for a sequence of virtual_wall__srv__DeleteWall_Request.
typedef struct virtual_wall__srv__DeleteWall_Request__Sequence
{
  virtual_wall__srv__DeleteWall_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} virtual_wall__srv__DeleteWall_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/DeleteWall in the package virtual_wall.
typedef struct virtual_wall__srv__DeleteWall_Response
{
  bool status;
} virtual_wall__srv__DeleteWall_Response;

// Struct for a sequence of virtual_wall__srv__DeleteWall_Response.
typedef struct virtual_wall__srv__DeleteWall_Response__Sequence
{
  virtual_wall__srv__DeleteWall_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} virtual_wall__srv__DeleteWall_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VIRTUAL_WALL__SRV__DETAIL__DELETE_WALL__STRUCT_H_
