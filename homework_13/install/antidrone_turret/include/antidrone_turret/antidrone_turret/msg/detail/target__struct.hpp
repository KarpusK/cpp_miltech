// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from antidrone_turret:msg/Target.idl
// generated code does not contain a copyright notice

#ifndef ANTIDRONE_TURRET__MSG__DETAIL__TARGET__STRUCT_HPP_
#define ANTIDRONE_TURRET__MSG__DETAIL__TARGET__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__antidrone_turret__msg__Target __attribute__((deprecated))
#else
# define DEPRECATED__antidrone_turret__msg__Target __declspec(deprecated)
#endif

namespace antidrone_turret
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Target_
{
  using Type = Target_<ContainerAllocator>;

  explicit Target_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->visible = false;
      this->x = 0.0f;
      this->y = 0.0f;
      this->distance_m = 0.0f;
      this->confidence = 0.0f;
    }
  }

  explicit Target_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->visible = false;
      this->x = 0.0f;
      this->y = 0.0f;
      this->distance_m = 0.0f;
      this->confidence = 0.0f;
    }
  }

  // field types and members
  using _visible_type =
    bool;
  _visible_type visible;
  using _x_type =
    float;
  _x_type x;
  using _y_type =
    float;
  _y_type y;
  using _distance_m_type =
    float;
  _distance_m_type distance_m;
  using _confidence_type =
    float;
  _confidence_type confidence;

  // setters for named parameter idiom
  Type & set__visible(
    const bool & _arg)
  {
    this->visible = _arg;
    return *this;
  }
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const float & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__distance_m(
    const float & _arg)
  {
    this->distance_m = _arg;
    return *this;
  }
  Type & set__confidence(
    const float & _arg)
  {
    this->confidence = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    antidrone_turret::msg::Target_<ContainerAllocator> *;
  using ConstRawPtr =
    const antidrone_turret::msg::Target_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<antidrone_turret::msg::Target_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<antidrone_turret::msg::Target_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      antidrone_turret::msg::Target_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<antidrone_turret::msg::Target_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      antidrone_turret::msg::Target_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<antidrone_turret::msg::Target_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<antidrone_turret::msg::Target_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<antidrone_turret::msg::Target_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__antidrone_turret__msg__Target
    std::shared_ptr<antidrone_turret::msg::Target_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__antidrone_turret__msg__Target
    std::shared_ptr<antidrone_turret::msg::Target_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Target_ & other) const
  {
    if (this->visible != other.visible) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->distance_m != other.distance_m) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    return true;
  }
  bool operator!=(const Target_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Target_

// alias to use template instance with default allocator
using Target =
  antidrone_turret::msg::Target_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace antidrone_turret

#endif  // ANTIDRONE_TURRET__MSG__DETAIL__TARGET__STRUCT_HPP_
