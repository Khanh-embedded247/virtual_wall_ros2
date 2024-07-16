// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from virtual_wall:srv/DeleteWall.idl
// generated code does not contain a copyright notice

#ifndef VIRTUAL_WALL__SRV__DETAIL__DELETE_WALL__STRUCT_HPP_
#define VIRTUAL_WALL__SRV__DETAIL__DELETE_WALL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__virtual_wall__srv__DeleteWall_Request __attribute__((deprecated))
#else
# define DEPRECATED__virtual_wall__srv__DeleteWall_Request __declspec(deprecated)
#endif

namespace virtual_wall
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DeleteWall_Request_
{
  using Type = DeleteWall_Request_<ContainerAllocator>;

  explicit DeleteWall_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0ul;
    }
  }

  explicit DeleteWall_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0ul;
    }
  }

  // field types and members
  using _id_type =
    uint32_t;
  _id_type id;

  // setters for named parameter idiom
  Type & set__id(
    const uint32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    virtual_wall::srv::DeleteWall_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const virtual_wall::srv::DeleteWall_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<virtual_wall::srv::DeleteWall_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<virtual_wall::srv::DeleteWall_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      virtual_wall::srv::DeleteWall_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<virtual_wall::srv::DeleteWall_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      virtual_wall::srv::DeleteWall_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<virtual_wall::srv::DeleteWall_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<virtual_wall::srv::DeleteWall_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<virtual_wall::srv::DeleteWall_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__virtual_wall__srv__DeleteWall_Request
    std::shared_ptr<virtual_wall::srv::DeleteWall_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__virtual_wall__srv__DeleteWall_Request
    std::shared_ptr<virtual_wall::srv::DeleteWall_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DeleteWall_Request_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    return true;
  }
  bool operator!=(const DeleteWall_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DeleteWall_Request_

// alias to use template instance with default allocator
using DeleteWall_Request =
  virtual_wall::srv::DeleteWall_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace virtual_wall


#ifndef _WIN32
# define DEPRECATED__virtual_wall__srv__DeleteWall_Response __attribute__((deprecated))
#else
# define DEPRECATED__virtual_wall__srv__DeleteWall_Response __declspec(deprecated)
#endif

namespace virtual_wall
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DeleteWall_Response_
{
  using Type = DeleteWall_Response_<ContainerAllocator>;

  explicit DeleteWall_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = false;
    }
  }

  explicit DeleteWall_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = false;
    }
  }

  // field types and members
  using _status_type =
    bool;
  _status_type status;

  // setters for named parameter idiom
  Type & set__status(
    const bool & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    virtual_wall::srv::DeleteWall_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const virtual_wall::srv::DeleteWall_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<virtual_wall::srv::DeleteWall_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<virtual_wall::srv::DeleteWall_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      virtual_wall::srv::DeleteWall_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<virtual_wall::srv::DeleteWall_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      virtual_wall::srv::DeleteWall_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<virtual_wall::srv::DeleteWall_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<virtual_wall::srv::DeleteWall_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<virtual_wall::srv::DeleteWall_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__virtual_wall__srv__DeleteWall_Response
    std::shared_ptr<virtual_wall::srv::DeleteWall_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__virtual_wall__srv__DeleteWall_Response
    std::shared_ptr<virtual_wall::srv::DeleteWall_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DeleteWall_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const DeleteWall_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DeleteWall_Response_

// alias to use template instance with default allocator
using DeleteWall_Response =
  virtual_wall::srv::DeleteWall_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace virtual_wall

namespace virtual_wall
{

namespace srv
{

struct DeleteWall
{
  using Request = virtual_wall::srv::DeleteWall_Request;
  using Response = virtual_wall::srv::DeleteWall_Response;
};

}  // namespace srv

}  // namespace virtual_wall

#endif  // VIRTUAL_WALL__SRV__DETAIL__DELETE_WALL__STRUCT_HPP_