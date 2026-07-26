// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from antidrone_turret:msg/TurretStatus.idl
// generated code does not contain a copyright notice

#ifndef ANTIDRONE_TURRET__MSG__DETAIL__TURRET_STATUS__BUILDER_HPP_
#define ANTIDRONE_TURRET__MSG__DETAIL__TURRET_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "antidrone_turret/msg/detail/turret_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace antidrone_turret
{

namespace msg
{

namespace builder
{

class Init_TurretStatus_distance_m
{
public:
  explicit Init_TurretStatus_distance_m(::antidrone_turret::msg::TurretStatus & msg)
  : msg_(msg)
  {}
  ::antidrone_turret::msg::TurretStatus distance_m(::antidrone_turret::msg::TurretStatus::_distance_m_type arg)
  {
    msg_.distance_m = std::move(arg);
    return std::move(msg_);
  }

private:
  ::antidrone_turret::msg::TurretStatus msg_;
};

class Init_TurretStatus_confidence
{
public:
  explicit Init_TurretStatus_confidence(::antidrone_turret::msg::TurretStatus & msg)
  : msg_(msg)
  {}
  Init_TurretStatus_distance_m confidence(::antidrone_turret::msg::TurretStatus::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_TurretStatus_distance_m(msg_);
  }

private:
  ::antidrone_turret::msg::TurretStatus msg_;
};

class Init_TurretStatus_trigger_state
{
public:
  explicit Init_TurretStatus_trigger_state(::antidrone_turret::msg::TurretStatus & msg)
  : msg_(msg)
  {}
  Init_TurretStatus_confidence trigger_state(::antidrone_turret::msg::TurretStatus::_trigger_state_type arg)
  {
    msg_.trigger_state = std::move(arg);
    return Init_TurretStatus_confidence(msg_);
  }

private:
  ::antidrone_turret::msg::TurretStatus msg_;
};

class Init_TurretStatus_action
{
public:
  explicit Init_TurretStatus_action(::antidrone_turret::msg::TurretStatus & msg)
  : msg_(msg)
  {}
  Init_TurretStatus_trigger_state action(::antidrone_turret::msg::TurretStatus::_action_type arg)
  {
    msg_.action = std::move(arg);
    return Init_TurretStatus_trigger_state(msg_);
  }

private:
  ::antidrone_turret::msg::TurretStatus msg_;
};

class Init_TurretStatus_target_state
{
public:
  Init_TurretStatus_target_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TurretStatus_action target_state(::antidrone_turret::msg::TurretStatus::_target_state_type arg)
  {
    msg_.target_state = std::move(arg);
    return Init_TurretStatus_action(msg_);
  }

private:
  ::antidrone_turret::msg::TurretStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::antidrone_turret::msg::TurretStatus>()
{
  return antidrone_turret::msg::builder::Init_TurretStatus_target_state();
}

}  // namespace antidrone_turret

#endif  // ANTIDRONE_TURRET__MSG__DETAIL__TURRET_STATUS__BUILDER_HPP_
