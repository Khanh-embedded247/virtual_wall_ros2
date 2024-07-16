// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from virtual_wall_ros2:srv/DeleteAll.idl
// generated code does not contain a copyright notice

#ifndef VIRTUAL_WALL_ROS2__SRV__DETAIL__DELETE_ALL__FUNCTIONS_H_
#define VIRTUAL_WALL_ROS2__SRV__DETAIL__DELETE_ALL__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "virtual_wall_ros2/msg/rosidl_generator_c__visibility_control.h"

#include "virtual_wall_ros2/srv/detail/delete_all__struct.h"

/// Initialize srv/DeleteAll message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * virtual_wall_ros2__srv__DeleteAll_Request
 * )) before or use
 * virtual_wall_ros2__srv__DeleteAll_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_wall_ros2
bool
virtual_wall_ros2__srv__DeleteAll_Request__init(virtual_wall_ros2__srv__DeleteAll_Request * msg);

/// Finalize srv/DeleteAll message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_wall_ros2
void
virtual_wall_ros2__srv__DeleteAll_Request__fini(virtual_wall_ros2__srv__DeleteAll_Request * msg);

/// Create srv/DeleteAll message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * virtual_wall_ros2__srv__DeleteAll_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_wall_ros2
virtual_wall_ros2__srv__DeleteAll_Request *
virtual_wall_ros2__srv__DeleteAll_Request__create();

/// Destroy srv/DeleteAll message.
/**
 * It calls
 * virtual_wall_ros2__srv__DeleteAll_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_wall_ros2
void
virtual_wall_ros2__srv__DeleteAll_Request__destroy(virtual_wall_ros2__srv__DeleteAll_Request * msg);

/// Check for srv/DeleteAll message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_wall_ros2
bool
virtual_wall_ros2__srv__DeleteAll_Request__are_equal(const virtual_wall_ros2__srv__DeleteAll_Request * lhs, const virtual_wall_ros2__srv__DeleteAll_Request * rhs);

/// Copy a srv/DeleteAll message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_wall_ros2
bool
virtual_wall_ros2__srv__DeleteAll_Request__copy(
  const virtual_wall_ros2__srv__DeleteAll_Request * input,
  virtual_wall_ros2__srv__DeleteAll_Request * output);

/// Initialize array of srv/DeleteAll messages.
/**
 * It allocates the memory for the number of elements and calls
 * virtual_wall_ros2__srv__DeleteAll_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_wall_ros2
bool
virtual_wall_ros2__srv__DeleteAll_Request__Sequence__init(virtual_wall_ros2__srv__DeleteAll_Request__Sequence * array, size_t size);

/// Finalize array of srv/DeleteAll messages.
/**
 * It calls
 * virtual_wall_ros2__srv__DeleteAll_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_wall_ros2
void
virtual_wall_ros2__srv__DeleteAll_Request__Sequence__fini(virtual_wall_ros2__srv__DeleteAll_Request__Sequence * array);

/// Create array of srv/DeleteAll messages.
/**
 * It allocates the memory for the array and calls
 * virtual_wall_ros2__srv__DeleteAll_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_wall_ros2
virtual_wall_ros2__srv__DeleteAll_Request__Sequence *
virtual_wall_ros2__srv__DeleteAll_Request__Sequence__create(size_t size);

/// Destroy array of srv/DeleteAll messages.
/**
 * It calls
 * virtual_wall_ros2__srv__DeleteAll_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_wall_ros2
void
virtual_wall_ros2__srv__DeleteAll_Request__Sequence__destroy(virtual_wall_ros2__srv__DeleteAll_Request__Sequence * array);

/// Check for srv/DeleteAll message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_wall_ros2
bool
virtual_wall_ros2__srv__DeleteAll_Request__Sequence__are_equal(const virtual_wall_ros2__srv__DeleteAll_Request__Sequence * lhs, const virtual_wall_ros2__srv__DeleteAll_Request__Sequence * rhs);

/// Copy an array of srv/DeleteAll messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_wall_ros2
bool
virtual_wall_ros2__srv__DeleteAll_Request__Sequence__copy(
  const virtual_wall_ros2__srv__DeleteAll_Request__Sequence * input,
  virtual_wall_ros2__srv__DeleteAll_Request__Sequence * output);

/// Initialize srv/DeleteAll message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * virtual_wall_ros2__srv__DeleteAll_Response
 * )) before or use
 * virtual_wall_ros2__srv__DeleteAll_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_wall_ros2
bool
virtual_wall_ros2__srv__DeleteAll_Response__init(virtual_wall_ros2__srv__DeleteAll_Response * msg);

/// Finalize srv/DeleteAll message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_wall_ros2
void
virtual_wall_ros2__srv__DeleteAll_Response__fini(virtual_wall_ros2__srv__DeleteAll_Response * msg);

/// Create srv/DeleteAll message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * virtual_wall_ros2__srv__DeleteAll_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_wall_ros2
virtual_wall_ros2__srv__DeleteAll_Response *
virtual_wall_ros2__srv__DeleteAll_Response__create();

/// Destroy srv/DeleteAll message.
/**
 * It calls
 * virtual_wall_ros2__srv__DeleteAll_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_wall_ros2
void
virtual_wall_ros2__srv__DeleteAll_Response__destroy(virtual_wall_ros2__srv__DeleteAll_Response * msg);

/// Check for srv/DeleteAll message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_wall_ros2
bool
virtual_wall_ros2__srv__DeleteAll_Response__are_equal(const virtual_wall_ros2__srv__DeleteAll_Response * lhs, const virtual_wall_ros2__srv__DeleteAll_Response * rhs);

/// Copy a srv/DeleteAll message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_wall_ros2
bool
virtual_wall_ros2__srv__DeleteAll_Response__copy(
  const virtual_wall_ros2__srv__DeleteAll_Response * input,
  virtual_wall_ros2__srv__DeleteAll_Response * output);

/// Initialize array of srv/DeleteAll messages.
/**
 * It allocates the memory for the number of elements and calls
 * virtual_wall_ros2__srv__DeleteAll_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_wall_ros2
bool
virtual_wall_ros2__srv__DeleteAll_Response__Sequence__init(virtual_wall_ros2__srv__DeleteAll_Response__Sequence * array, size_t size);

/// Finalize array of srv/DeleteAll messages.
/**
 * It calls
 * virtual_wall_ros2__srv__DeleteAll_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_wall_ros2
void
virtual_wall_ros2__srv__DeleteAll_Response__Sequence__fini(virtual_wall_ros2__srv__DeleteAll_Response__Sequence * array);

/// Create array of srv/DeleteAll messages.
/**
 * It allocates the memory for the array and calls
 * virtual_wall_ros2__srv__DeleteAll_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_wall_ros2
virtual_wall_ros2__srv__DeleteAll_Response__Sequence *
virtual_wall_ros2__srv__DeleteAll_Response__Sequence__create(size_t size);

/// Destroy array of srv/DeleteAll messages.
/**
 * It calls
 * virtual_wall_ros2__srv__DeleteAll_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_wall_ros2
void
virtual_wall_ros2__srv__DeleteAll_Response__Sequence__destroy(virtual_wall_ros2__srv__DeleteAll_Response__Sequence * array);

/// Check for srv/DeleteAll message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_wall_ros2
bool
virtual_wall_ros2__srv__DeleteAll_Response__Sequence__are_equal(const virtual_wall_ros2__srv__DeleteAll_Response__Sequence * lhs, const virtual_wall_ros2__srv__DeleteAll_Response__Sequence * rhs);

/// Copy an array of srv/DeleteAll messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_wall_ros2
bool
virtual_wall_ros2__srv__DeleteAll_Response__Sequence__copy(
  const virtual_wall_ros2__srv__DeleteAll_Response__Sequence * input,
  virtual_wall_ros2__srv__DeleteAll_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // VIRTUAL_WALL_ROS2__SRV__DETAIL__DELETE_ALL__FUNCTIONS_H_
