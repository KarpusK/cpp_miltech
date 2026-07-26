// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from antidrone_turret:msg/ActuatorStatus.idl
// generated code does not contain a copyright notice

#ifndef ANTIDRONE_TURRET__MSG__DETAIL__ACTUATOR_STATUS__STRUCT_HPP_
#define ANTIDRONE_TURRET__MSG__DETAIL__ACTUATOR_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__antidrone_turret__msg__ActuatorStatus __attribute__((deprecated))
#else
# define DEPRECATED__antidrone_turret__msg__ActuatorStatus __declspec(deprecated)
#endif

namespace antidrone_turret
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ActuatorStatus_
{
  using Type = ActuatorStatus_<ContainerAllocator>;

  explicit ActuatorStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = 0;
      this->trigger_count = 0ul;
    }
  }

  explicit ActuatorStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = 0;
      this->trigger_count = 0ul;
    }
  }

  // field types and members
  using _state_type =
    uint8_t;
  _state_type state;
  using _trigger_count_type =
    uint32_t;
  _trigger_count_type trigger_count;

  // setters for named parameter idiom
  Type & set__state(
    const uint8_t & _arg)
  {
    this->state = _arg;
    return *this;
  }
  Type & set__trigger_count(
    const uint32_t & _arg)
  {
    this->trigger_count = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t READY =
    0u;
  static constexpr uint8_t RELOADING =
    1u;

  // pointer types
  using RawPtr =
    antidrone_turret::msg::ActuatorStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const antidrone_turret::msg::ActuatorStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<antidrone_turret::msg::ActuatorStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<antidrone_turret::msg::ActuatorStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      antidrone_turret::msg::ActuatorStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<antidrone_turret::msg::ActuatorStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      antidrone_turret::msg::ActuatorStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<antidrone_turret::msg::ActuatorStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<antidrone_turret::msg::ActuatorStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<antidrone_turret::msg::ActuatorStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__antidrone_turret__msg__ActuatorStatus
    std::shared_ptr<antidrone_turret::msg::ActuatorStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__antidrone_turret__msg__ActuatorStatus
    std::shared_ptr<antidrone_turret::msg::ActuatorStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ActuatorStatus_ & other) const
  {
    if (this->state != other.state) {
      return false;
    }
    if (this->trigger_count != other.trigger_count) {
      return false;
    }
    return true;
  }
  bool operator!=(const ActuatorStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ActuatorStatus_

// alias to use template instance with default allocator
using ActuatorStatus =
  antidrone_turret::msg::ActuatorStatus_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ActuatorStatus_<ContainerAllocator>::READY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ActuatorStatus_<ContainerAllocator>::RELOADING;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace antidrone_turret

#endif  // ANTIDRONE_TURRET__MSG__DETAIL__ACTUATOR_STATUS__STRUCT_HPP_
