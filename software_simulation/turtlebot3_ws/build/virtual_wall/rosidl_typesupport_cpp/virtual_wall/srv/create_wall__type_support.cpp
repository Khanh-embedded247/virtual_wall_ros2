// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from virtual_wall:srv/CreateWall.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "virtual_wall/srv/detail/create_wall__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace virtual_wall
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _CreateWall_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _CreateWall_Request_type_support_ids_t;

static const _CreateWall_Request_type_support_ids_t _CreateWall_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _CreateWall_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _CreateWall_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _CreateWall_Request_type_support_symbol_names_t _CreateWall_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, virtual_wall, srv, CreateWall_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, virtual_wall, srv, CreateWall_Request)),
  }
};

typedef struct _CreateWall_Request_type_support_data_t
{
  void * data[2];
} _CreateWall_Request_type_support_data_t;

static _CreateWall_Request_type_support_data_t _CreateWall_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _CreateWall_Request_message_typesupport_map = {
  2,
  "virtual_wall",
  &_CreateWall_Request_message_typesupport_ids.typesupport_identifier[0],
  &_CreateWall_Request_message_typesupport_symbol_names.symbol_name[0],
  &_CreateWall_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t CreateWall_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_CreateWall_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace virtual_wall

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<virtual_wall::srv::CreateWall_Request>()
{
  return &::virtual_wall::srv::rosidl_typesupport_cpp::CreateWall_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, virtual_wall, srv, CreateWall_Request)() {
  return get_message_type_support_handle<virtual_wall::srv::CreateWall_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "virtual_wall/srv/detail/create_wall__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace virtual_wall
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _CreateWall_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _CreateWall_Response_type_support_ids_t;

static const _CreateWall_Response_type_support_ids_t _CreateWall_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _CreateWall_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _CreateWall_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _CreateWall_Response_type_support_symbol_names_t _CreateWall_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, virtual_wall, srv, CreateWall_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, virtual_wall, srv, CreateWall_Response)),
  }
};

typedef struct _CreateWall_Response_type_support_data_t
{
  void * data[2];
} _CreateWall_Response_type_support_data_t;

static _CreateWall_Response_type_support_data_t _CreateWall_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _CreateWall_Response_message_typesupport_map = {
  2,
  "virtual_wall",
  &_CreateWall_Response_message_typesupport_ids.typesupport_identifier[0],
  &_CreateWall_Response_message_typesupport_symbol_names.symbol_name[0],
  &_CreateWall_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t CreateWall_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_CreateWall_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace virtual_wall

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<virtual_wall::srv::CreateWall_Response>()
{
  return &::virtual_wall::srv::rosidl_typesupport_cpp::CreateWall_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, virtual_wall, srv, CreateWall_Response)() {
  return get_message_type_support_handle<virtual_wall::srv::CreateWall_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "virtual_wall/srv/detail/create_wall__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace virtual_wall
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _CreateWall_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _CreateWall_type_support_ids_t;

static const _CreateWall_type_support_ids_t _CreateWall_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _CreateWall_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _CreateWall_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _CreateWall_type_support_symbol_names_t _CreateWall_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, virtual_wall, srv, CreateWall)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, virtual_wall, srv, CreateWall)),
  }
};

typedef struct _CreateWall_type_support_data_t
{
  void * data[2];
} _CreateWall_type_support_data_t;

static _CreateWall_type_support_data_t _CreateWall_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _CreateWall_service_typesupport_map = {
  2,
  "virtual_wall",
  &_CreateWall_service_typesupport_ids.typesupport_identifier[0],
  &_CreateWall_service_typesupport_symbol_names.symbol_name[0],
  &_CreateWall_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t CreateWall_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_CreateWall_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace virtual_wall

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<virtual_wall::srv::CreateWall>()
{
  return &::virtual_wall::srv::rosidl_typesupport_cpp::CreateWall_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp
