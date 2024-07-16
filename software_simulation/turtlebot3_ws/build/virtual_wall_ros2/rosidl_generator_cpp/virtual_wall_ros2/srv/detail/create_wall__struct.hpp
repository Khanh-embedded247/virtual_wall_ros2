// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from virtual_wall_ros2:srv/CreateWall.idl
// generated code does not contain a copyright notice

#ifndef VIRTUAL_WALL_ROS2__SRV__DETAIL__CREATE_WALL__STRUCT_HPP_
#define VIRTUAL_WALL_ROS2__SRV__DETAIL__CREATE_WALL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'start_point'
// Member 'end_point'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__virtual_wall_ros2__srv__CreateWall_Request __attribute__((deprecated))
#else
# define DEPRECATED__virtual_wall_ros2__srv__CreateWall_Request __declspec(deprecated)
#endif

namespace virtual_wall_ros2
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CreateWall_Request_
{
  using Type = CreateWall_Request_<ContainerAllocator>;

  explicit CreateWall_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : start_point(_init),
    end_point(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0ul;
    }
  }

  explicit CreateWall_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : start_point(_alloc, _init),
    end_point(_alloc, _init)
  {
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
  using _start_point_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _start_point_type start_point;
  using _end_point_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _end_point_type end_point;

  // setters for named parameter idiom
  Type & set__id(
    const uint32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__start_point(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->start_point = _arg;
    return *this;
  }
  Type & set__end_point(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->end_point = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    virtual_wall_ros2::srv::CreateWall_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const virtual_wall_ros2::srv::CreateWall_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<virtual_wall_ros2::srv::CreateWall_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<virtual_wall_ros2::srv::CreateWall_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      virtual_wall_ros2::srv::CreateWall_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<virtual_wall_ros2::srv::CreateWall_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      virtual_wall_ros2::srv::CreateWall_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<virtual_wall_ros2::srv::CreateWall_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<virtual_wall_ros2::srv::CreateWall_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<virtual_wall_ros2::srv::CreateWall_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__virtual_wall_ros2__srv__CreateWall_Request
    std::shared_ptr<virtual_wall_ros2::srv::CreateWall_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__virtual_wall_ros2__srv__CreateWall_Request
    std::shared_ptr<virtual_wall_ros2::srv::CreateWall_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CreateWall_Request_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->start_point != other.start_point) {
      return false;
    }
    if (this->end_point != other.end_point) {
      return false;
    }
    return true;
  }
  bool operator!=(const CreateWall_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CreateWall_Request_

// alias to use template instance with default allocator
using CreateWall_Request =
  virtual_wall_ros2::srv::CreateWall_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace virtual_wall_ros2


#ifndef _WIN32
# define DEPRECATED__virtual_wall_ros2__srv__CreateWall_Response __attribute__((deprecated))
#else
# define DEPRECATED__virtual_wall_ros2__srv__CreateWall_Response __declspec(deprecated)
#endif

namespace virtual_wall_ros2
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CreateWall_Response_
{
  using Type = CreateWall_Response_<ContainerAllocator>;

  explicit CreateWall_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = false;
    }
  }

  explicit CreateWall_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    virtual_wall_ros2::srv::CreateWall_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const virtual_wall_ros2::srv::CreateWall_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<virtual_wall_ros2::srv::CreateWall_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<virtual_wall_ros2::srv::CreateWall_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      virtual_wall_ros2::srv::CreateWall_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<virtual_wall_ros2::srv::CreateWall_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      virtual_wall_ros2::srv::CreateWall_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<virtual_wall_ros2::srv::CreateWall_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<virtual_wall_ros2::srv::CreateWall_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<virtual_wall_ros2::srv::CreateWall_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__virtual_wall_ros2__srv__CreateWall_Response
    std::shared_ptr<virtual_wall_ros2::srv::CreateWall_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__virtual_wall_ros2__srv__CreateWall_Response
    std::shared_ptr<virtual_wall_ros2::srv::CreateWall_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CreateWall_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const CreateWall_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CreateWall_Response_

// alias to use template instance with default allocator
using CreateWall_Response =
  virtual_wall_ros2::srv::CreateWall_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace virtual_wall_ros2

namespace virtual_wall_ros2
{

namespace srv
{

struct CreateWall
{
  using Request = virtual_wall_ros2::srv::CreateWall_Request;
  using Response = virtual_wall_ros2::srv::CreateWall_Response;
};

}  // namespace srv

}  // namespace virtual_wall_ros2

#endif  // VIRTUAL_WALL_ROS2__SRV__DETAIL__CREATE_WALL__STRUCT_HPP_
