// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from antidrone_turret:srv/TriggerActuator.idl
// generated code does not contain a copyright notice

#ifndef ANTIDRONE_TURRET__SRV__DETAIL__TRIGGER_ACTUATOR__STRUCT_HPP_
#define ANTIDRONE_TURRET__SRV__DETAIL__TRIGGER_ACTUATOR__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__antidrone_turret__srv__TriggerActuator_Request __attribute__((deprecated))
#else
# define DEPRECATED__antidrone_turret__srv__TriggerActuator_Request __declspec(deprecated)
#endif

namespace antidrone_turret
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TriggerActuator_Request_
{
  using Type = TriggerActuator_Request_<ContainerAllocator>;

  explicit TriggerActuator_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->confidence = 0.0f;
      this->distance_m = 0.0f;
    }
  }

  explicit TriggerActuator_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->confidence = 0.0f;
      this->distance_m = 0.0f;
    }
  }

  // field types and members
  using _confidence_type =
    float;
  _confidence_type confidence;
  using _distance_m_type =
    float;
  _distance_m_type distance_m;

  // setters for named parameter idiom
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

  // pointer types
  using RawPtr =
    antidrone_turret::srv::TriggerActuator_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const antidrone_turret::srv::TriggerActuator_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<antidrone_turret::srv::TriggerActuator_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<antidrone_turret::srv::TriggerActuator_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      antidrone_turret::srv::TriggerActuator_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<antidrone_turret::srv::TriggerActuator_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      antidrone_turret::srv::TriggerActuator_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<antidrone_turret::srv::TriggerActuator_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<antidrone_turret::srv::TriggerActuator_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<antidrone_turret::srv::TriggerActuator_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__antidrone_turret__srv__TriggerActuator_Request
    std::shared_ptr<antidrone_turret::srv::TriggerActuator_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__antidrone_turret__srv__TriggerActuator_Request
    std::shared_ptr<antidrone_turret::srv::TriggerActuator_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TriggerActuator_Request_ & other) const
  {
    if (this->confidence != other.confidence) {
      return false;
    }
    if (this->distance_m != other.distance_m) {
      return false;
    }
    return true;
  }
  bool operator!=(const TriggerActuator_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TriggerActuator_Request_

// alias to use template instance with default allocator
using TriggerActuator_Request =
  antidrone_turret::srv::TriggerActuator_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace antidrone_turret


#ifndef _WIN32
# define DEPRECATED__antidrone_turret__srv__TriggerActuator_Response __attribute__((deprecated))
#else
# define DEPRECATED__antidrone_turret__srv__TriggerActuator_Response __declspec(deprecated)
#endif

namespace antidrone_turret
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TriggerActuator_Response_
{
  using Type = TriggerActuator_Response_<ContainerAllocator>;

  explicit TriggerActuator_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
      this->trigger_count = 0ul;
    }
  }

  explicit TriggerActuator_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
      this->trigger_count = 0ul;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _trigger_count_type =
    uint32_t;
  _trigger_count_type trigger_count;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__trigger_count(
    const uint32_t & _arg)
  {
    this->trigger_count = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    antidrone_turret::srv::TriggerActuator_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const antidrone_turret::srv::TriggerActuator_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<antidrone_turret::srv::TriggerActuator_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<antidrone_turret::srv::TriggerActuator_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      antidrone_turret::srv::TriggerActuator_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<antidrone_turret::srv::TriggerActuator_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      antidrone_turret::srv::TriggerActuator_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<antidrone_turret::srv::TriggerActuator_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<antidrone_turret::srv::TriggerActuator_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<antidrone_turret::srv::TriggerActuator_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__antidrone_turret__srv__TriggerActuator_Response
    std::shared_ptr<antidrone_turret::srv::TriggerActuator_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__antidrone_turret__srv__TriggerActuator_Response
    std::shared_ptr<antidrone_turret::srv::TriggerActuator_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TriggerActuator_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->trigger_count != other.trigger_count) {
      return false;
    }
    return true;
  }
  bool operator!=(const TriggerActuator_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TriggerActuator_Response_

// alias to use template instance with default allocator
using TriggerActuator_Response =
  antidrone_turret::srv::TriggerActuator_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace antidrone_turret

namespace antidrone_turret
{

namespace srv
{

struct TriggerActuator
{
  using Request = antidrone_turret::srv::TriggerActuator_Request;
  using Response = antidrone_turret::srv::TriggerActuator_Response;
};

}  // namespace srv

}  // namespace antidrone_turret

#endif  // ANTIDRONE_TURRET__SRV__DETAIL__TRIGGER_ACTUATOR__STRUCT_HPP_
