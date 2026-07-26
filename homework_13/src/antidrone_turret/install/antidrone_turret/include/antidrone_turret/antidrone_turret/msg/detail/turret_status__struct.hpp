// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from antidrone_turret:msg/TurretStatus.idl
// generated code does not contain a copyright notice

#ifndef ANTIDRONE_TURRET__MSG__DETAIL__TURRET_STATUS__STRUCT_HPP_
#define ANTIDRONE_TURRET__MSG__DETAIL__TURRET_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__antidrone_turret__msg__TurretStatus __attribute__((deprecated))
#else
# define DEPRECATED__antidrone_turret__msg__TurretStatus __declspec(deprecated)
#endif

namespace antidrone_turret
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TurretStatus_
{
  using Type = TurretStatus_<ContainerAllocator>;

  explicit TurretStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target_state = 0;
      this->action = 0;
      this->trigger_state = 0;
      this->confidence = 0.0f;
      this->distance_m = 0.0f;
    }
  }

  explicit TurretStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target_state = 0;
      this->action = 0;
      this->trigger_state = 0;
      this->confidence = 0.0f;
      this->distance_m = 0.0f;
    }
  }

  // field types and members
  using _target_state_type =
    uint8_t;
  _target_state_type target_state;
  using _action_type =
    uint8_t;
  _action_type action;
  using _trigger_state_type =
    uint8_t;
  _trigger_state_type trigger_state;
  using _confidence_type =
    float;
  _confidence_type confidence;
  using _distance_m_type =
    float;
  _distance_m_type distance_m;

  // setters for named parameter idiom
  Type & set__target_state(
    const uint8_t & _arg)
  {
    this->target_state = _arg;
    return *this;
  }
  Type & set__action(
    const uint8_t & _arg)
  {
    this->action = _arg;
    return *this;
  }
  Type & set__trigger_state(
    const uint8_t & _arg)
  {
    this->trigger_state = _arg;
    return *this;
  }
  Type & set__confidence(
    const float & _arg)
  {
    this->confidence = _arg;
    return *this;
  }
  Type & set__distance_m(
    const float & _arg)
  {
    this->distance_m = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t TARGET_NONE =
    0u;
  static constexpr uint8_t TARGET_LOW_CONFIDENCE =
    1u;
  static constexpr uint8_t TARGET_LOCKED =
    2u;
  static constexpr uint8_t ACTION_IDLE =
    0u;
  static constexpr uint8_t ACTION_TRACK =
    1u;
  static constexpr uint8_t TRIGGER_SKIP =
    0u;
  static constexpr uint8_t TRIGGER_REQUESTED =
    1u;
  static constexpr uint8_t TRIGGER_RELOADING =
    2u;

  // pointer types
  using RawPtr =
    antidrone_turret::msg::TurretStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const antidrone_turret::msg::TurretStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<antidrone_turret::msg::TurretStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<antidrone_turret::msg::TurretStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      antidrone_turret::msg::TurretStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<antidrone_turret::msg::TurretStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      antidrone_turret::msg::TurretStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<antidrone_turret::msg::TurretStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<antidrone_turret::msg::TurretStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<antidrone_turret::msg::TurretStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__antidrone_turret__msg__TurretStatus
    std::shared_ptr<antidrone_turret::msg::TurretStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__antidrone_turret__msg__TurretStatus
    std::shared_ptr<antidrone_turret::msg::TurretStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TurretStatus_ & other) const
  {
    if (this->target_state != other.target_state) {
      return false;
    }
    if (this->action != other.action) {
      return false;
    }
    if (this->trigger_state != other.trigger_state) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    if (this->distance_m != other.distance_m) {
      return false;
    }
    return true;
  }
  bool operator!=(const TurretStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TurretStatus_

// alias to use template instance with default allocator
using TurretStatus =
  antidrone_turret::msg::TurretStatus_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TurretStatus_<ContainerAllocator>::TARGET_NONE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TurretStatus_<ContainerAllocator>::TARGET_LOW_CONFIDENCE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TurretStatus_<ContainerAllocator>::TARGET_LOCKED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TurretStatus_<ContainerAllocator>::ACTION_IDLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TurretStatus_<ContainerAllocator>::ACTION_TRACK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TurretStatus_<ContainerAllocator>::TRIGGER_SKIP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TurretStatus_<ContainerAllocator>::TRIGGER_REQUESTED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TurretStatus_<ContainerAllocator>::TRIGGER_RELOADING;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace antidrone_turret

#endif  // ANTIDRONE_TURRET__MSG__DETAIL__TURRET_STATUS__STRUCT_HPP_
