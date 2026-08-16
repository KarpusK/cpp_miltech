// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from antidrone_turret:msg/GimbalCommand.idl
// generated code does not contain a copyright notice

#ifndef ANTIDRONE_TURRET__MSG__DETAIL__GIMBAL_COMMAND__STRUCT_HPP_
#define ANTIDRONE_TURRET__MSG__DETAIL__GIMBAL_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__antidrone_turret__msg__GimbalCommand __attribute__((deprecated))
#else
# define DEPRECATED__antidrone_turret__msg__GimbalCommand __declspec(deprecated)
#endif

namespace antidrone_turret
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GimbalCommand_
{
  using Type = GimbalCommand_<ContainerAllocator>;

  explicit GimbalCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->direction = 0;
      this->target_y = 0.0f;
      this->error_y = 0.0f;
    }
  }

  explicit GimbalCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->direction = 0;
      this->target_y = 0.0f;
      this->error_y = 0.0f;
    }
  }

  // field types and members
  using _direction_type =
    int8_t;
  _direction_type direction;
  using _target_y_type =
    float;
  _target_y_type target_y;
  using _error_y_type =
    float;
  _error_y_type error_y;

  // setters for named parameter idiom
  Type & set__direction(
    const int8_t & _arg)
  {
    this->direction = _arg;
    return *this;
  }
  Type & set__target_y(
    const float & _arg)
  {
    this->target_y = _arg;
    return *this;
  }
  Type & set__error_y(
    const float & _arg)
  {
    this->error_y = _arg;
    return *this;
  }

  // constant declarations
  static constexpr int8_t DOWN =
    -1;
  static constexpr int8_t CENTER =
    0;
  static constexpr int8_t UP =
    1;

  // pointer types
  using RawPtr =
    antidrone_turret::msg::GimbalCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const antidrone_turret::msg::GimbalCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<antidrone_turret::msg::GimbalCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<antidrone_turret::msg::GimbalCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      antidrone_turret::msg::GimbalCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<antidrone_turret::msg::GimbalCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      antidrone_turret::msg::GimbalCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<antidrone_turret::msg::GimbalCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<antidrone_turret::msg::GimbalCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<antidrone_turret::msg::GimbalCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__antidrone_turret__msg__GimbalCommand
    std::shared_ptr<antidrone_turret::msg::GimbalCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__antidrone_turret__msg__GimbalCommand
    std::shared_ptr<antidrone_turret::msg::GimbalCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GimbalCommand_ & other) const
  {
    if (this->direction != other.direction) {
      return false;
    }
    if (this->target_y != other.target_y) {
      return false;
    }
    if (this->error_y != other.error_y) {
      return false;
    }
    return true;
  }
  bool operator!=(const GimbalCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GimbalCommand_

// alias to use template instance with default allocator
using GimbalCommand =
  antidrone_turret::msg::GimbalCommand_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t GimbalCommand_<ContainerAllocator>::DOWN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t GimbalCommand_<ContainerAllocator>::CENTER;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t GimbalCommand_<ContainerAllocator>::UP;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace antidrone_turret

#endif  // ANTIDRONE_TURRET__MSG__DETAIL__GIMBAL_COMMAND__STRUCT_HPP_
