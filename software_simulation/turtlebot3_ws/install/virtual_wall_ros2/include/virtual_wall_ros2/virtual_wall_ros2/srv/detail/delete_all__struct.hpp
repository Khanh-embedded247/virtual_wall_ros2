// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from virtual_wall_ros2:srv/DeleteAll.idl
// generated code does not contain a copyright notice

#ifndef VIRTUAL_WALL_ROS2__SRV__DETAIL__DELETE_ALL__STRUCT_HPP_
#define VIRTUAL_WALL_ROS2__SRV__DETAIL__DELETE_ALL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__virtual_wall_ros2__srv__DeleteAll_Request __attribute__((deprecated))
#else
# define DEPRECATED__virtual_wall_ros2__srv__DeleteAll_Request __declspec(deprecated)
#endif

namespace virtual_wall_ros2
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DeleteAll_Request_
{
  using Type = DeleteAll_Request_<ContainerAllocator>;

  explicit DeleteAll_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit DeleteAll_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    virtual_wall_ros2::srv::DeleteAll_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const virtual_wall_ros2::srv::DeleteAll_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<virtual_wall_ros2::srv::DeleteAll_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<virtual_wall_ros2::srv::DeleteAll_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      virtual_wall_ros2::srv::DeleteAll_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<virtual_wall_ros2::srv::DeleteAll_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      virtual_wall_ros2::srv::DeleteAll_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<virtual_wall_ros2::srv::DeleteAll_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<virtual_wall_ros2::srv::DeleteAll_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<virtual_wall_ros2::srv::DeleteAll_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__virtual_wall_ros2__srv__DeleteAll_Request
    std::shared_ptr<virtual_wall_ros2::srv::DeleteAll_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__virtual_wall_ros2__srv__DeleteAll_Request
    std::shared_ptr<virtual_wall_ros2::srv::DeleteAll_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DeleteAll_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const DeleteAll_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DeleteAll_Request_

// alias to use template instance with default allocator
using DeleteAll_Request =
  virtual_wall_ros2::srv::DeleteAll_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace virtual_wall_ros2


#ifndef _WIN32
# define DEPRECATED__virtual_wall_ros2__srv__DeleteAll_Response __attribute__((deprecated))
#else
# define DEPRECATED__virtual_wall_ros2__srv__DeleteAll_Response __declspec(deprecated)
#endif

namespace virtual_wall_ros2
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DeleteAll_Response_
{
  using Type = DeleteAll_Response_<ContainerAllocator>;

  explicit DeleteAll_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = false;
    }
  }

  explicit DeleteAll_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    virtual_wall_ros2::srv::DeleteAll_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const virtual_wall_ros2::srv::DeleteAll_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<virtual_wall_ros2::srv::DeleteAll_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<virtual_wall_ros2::srv::DeleteAll_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      virtual_wall_ros2::srv::DeleteAll_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<virtual_wall_ros2::srv::DeleteAll_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      virtual_wall_ros2::srv::DeleteAll_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<virtual_wall_ros2::srv::DeleteAll_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<virtual_wall_ros2::srv::DeleteAll_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<virtual_wall_ros2::srv::DeleteAll_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__virtual_wall_ros2__srv__DeleteAll_Response
    std::shared_ptr<virtual_wall_ros2::srv::DeleteAll_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__virtual_wall_ros2__srv__DeleteAll_Response
    std::shared_ptr<virtual_wall_ros2::srv::DeleteAll_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DeleteAll_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const DeleteAll_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DeleteAll_Response_

// alias to use template instance with default allocator
using DeleteAll_Response =
  virtual_wall_ros2::srv::DeleteAll_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace virtual_wall_ros2

namespace virtual_wall_ros2
{

namespace srv
{

struct DeleteAll
{
  using Request = virtual_wall_ros2::srv::DeleteAll_Request;
  using Response = virtual_wall_ros2::srv::DeleteAll_Response;
};

}  // namespace srv

}  // namespace virtual_wall_ros2

#endif  // VIRTUAL_WALL_ROS2__SRV__DETAIL__DELETE_ALL__STRUCT_HPP_
