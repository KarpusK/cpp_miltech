// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from antidrone_turret:msg/ActuatorStatus.idl
// generated code does not contain a copyright notice

#ifndef ANTIDRONE_TURRET__MSG__DETAIL__ACTUATOR_STATUS__BUILDER_HPP_
#define ANTIDRONE_TURRET__MSG__DETAIL__ACTUATOR_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "antidrone_turret/msg/detail/actuator_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace antidrone_turret
{

namespace msg
{

namespace builder
{

class Init_ActuatorStatus_trigger_count
{
public:
  explicit Init_ActuatorStatus_trigger_count(::antidrone_turret::msg::ActuatorStatus & msg)
  : msg_(msg)
  {}
  ::antidrone_turret::msg::ActuatorStatus trigger_count(::antidrone_turret::msg::ActuatorStatus::_trigger_count_type arg)
  {
    msg_.trigger_count = std::move(arg);
    return std::move(msg_);
  }

private:
  ::antidrone_turret::msg::ActuatorStatus msg_;
};

class Init_ActuatorStatus_state
{
public:
  Init_ActuatorStatus_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ActuatorStatus_trigger_count state(::antidrone_turret::msg::ActuatorStatus::_state_type arg)
  {
    msg_.state = std::move(arg);
    return Init_ActuatorStatus_trigger_count(msg_);
  }

private:
  ::antidrone_turret::msg::ActuatorStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::antidrone_turret::msg::ActuatorStatus>()
{
  return antidrone_turret::msg::builder::Init_ActuatorStatus_state();
}

}  // namespace antidrone_turret

#endif  // ANTIDRONE_TURRET__MSG__DETAIL__ACTUATOR_STATUS__BUILDER_HPP_
