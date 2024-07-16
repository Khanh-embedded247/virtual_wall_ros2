// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from virtual_wall:srv/DeleteWall.idl
// generated code does not contain a copyright notice
#include "virtual_wall/srv/detail/delete_wall__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
virtual_wall__srv__DeleteWall_Request__init(virtual_wall__srv__DeleteWall_Request * msg)
{
  if (!msg) {
    return false;
  }
  // id
  return true;
}

void
virtual_wall__srv__DeleteWall_Request__fini(virtual_wall__srv__DeleteWall_Request * msg)
{
  if (!msg) {
    return;
  }
  // id
}

bool
virtual_wall__srv__DeleteWall_Request__are_equal(const virtual_wall__srv__DeleteWall_Request * lhs, const virtual_wall__srv__DeleteWall_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  return true;
}

bool
virtual_wall__srv__DeleteWall_Request__copy(
  const virtual_wall__srv__DeleteWall_Request * input,
  virtual_wall__srv__DeleteWall_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  return true;
}

virtual_wall__srv__DeleteWall_Request *
virtual_wall__srv__DeleteWall_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  virtual_wall__srv__DeleteWall_Request * msg = (virtual_wall__srv__DeleteWall_Request *)allocator.allocate(sizeof(virtual_wall__srv__DeleteWall_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(virtual_wall__srv__DeleteWall_Request));
  bool success = virtual_wall__srv__DeleteWall_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
virtual_wall__srv__DeleteWall_Request__destroy(virtual_wall__srv__DeleteWall_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    virtual_wall__srv__DeleteWall_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
virtual_wall__srv__DeleteWall_Request__Sequence__init(virtual_wall__srv__DeleteWall_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  virtual_wall__srv__DeleteWall_Request * data = NULL;

  if (size) {
    data = (virtual_wall__srv__DeleteWall_Request *)allocator.zero_allocate(size, sizeof(virtual_wall__srv__DeleteWall_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = virtual_wall__srv__DeleteWall_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        virtual_wall__srv__DeleteWall_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
virtual_wall__srv__DeleteWall_Request__Sequence__fini(virtual_wall__srv__DeleteWall_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      virtual_wall__srv__DeleteWall_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

virtual_wall__srv__DeleteWall_Request__Sequence *
virtual_wall__srv__DeleteWall_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  virtual_wall__srv__DeleteWall_Request__Sequence * array = (virtual_wall__srv__DeleteWall_Request__Sequence *)allocator.allocate(sizeof(virtual_wall__srv__DeleteWall_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = virtual_wall__srv__DeleteWall_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
virtual_wall__srv__DeleteWall_Request__Sequence__destroy(virtual_wall__srv__DeleteWall_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    virtual_wall__srv__DeleteWall_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
virtual_wall__srv__DeleteWall_Request__Sequence__are_equal(const virtual_wall__srv__DeleteWall_Request__Sequence * lhs, const virtual_wall__srv__DeleteWall_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!virtual_wall__srv__DeleteWall_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
virtual_wall__srv__DeleteWall_Request__Sequence__copy(
  const virtual_wall__srv__DeleteWall_Request__Sequence * input,
  virtual_wall__srv__DeleteWall_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(virtual_wall__srv__DeleteWall_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    virtual_wall__srv__DeleteWall_Request * data =
      (virtual_wall__srv__DeleteWall_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!virtual_wall__srv__DeleteWall_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          virtual_wall__srv__DeleteWall_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!virtual_wall__srv__DeleteWall_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
virtual_wall__srv__DeleteWall_Response__init(virtual_wall__srv__DeleteWall_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  return true;
}

void
virtual_wall__srv__DeleteWall_Response__fini(virtual_wall__srv__DeleteWall_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
}

bool
virtual_wall__srv__DeleteWall_Response__are_equal(const virtual_wall__srv__DeleteWall_Response * lhs, const virtual_wall__srv__DeleteWall_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  return true;
}

bool
virtual_wall__srv__DeleteWall_Response__copy(
  const virtual_wall__srv__DeleteWall_Response * input,
  virtual_wall__srv__DeleteWall_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  return true;
}

virtual_wall__srv__DeleteWall_Response *
virtual_wall__srv__DeleteWall_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  virtual_wall__srv__DeleteWall_Response * msg = (virtual_wall__srv__DeleteWall_Response *)allocator.allocate(sizeof(virtual_wall__srv__DeleteWall_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(virtual_wall__srv__DeleteWall_Response));
  bool success = virtual_wall__srv__DeleteWall_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
virtual_wall__srv__DeleteWall_Response__destroy(virtual_wall__srv__DeleteWall_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    virtual_wall__srv__DeleteWall_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
virtual_wall__srv__DeleteWall_Response__Sequence__init(virtual_wall__srv__DeleteWall_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  virtual_wall__srv__DeleteWall_Response * data = NULL;

  if (size) {
    data = (virtual_wall__srv__DeleteWall_Response *)allocator.zero_allocate(size, sizeof(virtual_wall__srv__DeleteWall_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = virtual_wall__srv__DeleteWall_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        virtual_wall__srv__DeleteWall_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
virtual_wall__srv__DeleteWall_Response__Sequence__fini(virtual_wall__srv__DeleteWall_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      virtual_wall__srv__DeleteWall_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

virtual_wall__srv__DeleteWall_Response__Sequence *
virtual_wall__srv__DeleteWall_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  virtual_wall__srv__DeleteWall_Response__Sequence * array = (virtual_wall__srv__DeleteWall_Response__Sequence *)allocator.allocate(sizeof(virtual_wall__srv__DeleteWall_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = virtual_wall__srv__DeleteWall_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
virtual_wall__srv__DeleteWall_Response__Sequence__destroy(virtual_wall__srv__DeleteWall_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    virtual_wall__srv__DeleteWall_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
virtual_wall__srv__DeleteWall_Response__Sequence__are_equal(const virtual_wall__srv__DeleteWall_Response__Sequence * lhs, const virtual_wall__srv__DeleteWall_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!virtual_wall__srv__DeleteWall_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
virtual_wall__srv__DeleteWall_Response__Sequence__copy(
  const virtual_wall__srv__DeleteWall_Response__Sequence * input,
  virtual_wall__srv__DeleteWall_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(virtual_wall__srv__DeleteWall_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    virtual_wall__srv__DeleteWall_Response * data =
      (virtual_wall__srv__DeleteWall_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!virtual_wall__srv__DeleteWall_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          virtual_wall__srv__DeleteWall_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!virtual_wall__srv__DeleteWall_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}