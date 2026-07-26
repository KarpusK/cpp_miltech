// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from antidrone_turret:srv/TriggerActuator.idl
// generated code does not contain a copyright notice

#ifndef ANTIDRONE_TURRET__SRV__DETAIL__TRIGGER_ACTUATOR__BUILDER_HPP_
#define ANTIDRONE_TURRET__SRV__DETAIL__TRIGGER_ACTUATOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "antidrone_turret/srv/detail/trigger_actuator__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace antidrone_turret
{

namespace srv
{

namespace builder
{

class Init_TriggerActuator_Request_distance_m
{
public:
  explicit Init_TriggerActuator_Request_distance_m(::antidrone_turret::srv::TriggerActuator_Request & msg)
  : msg_(msg)
  {}
  ::antidrone_turret::srv::TriggerActuator_Request distance_m(::antidrone_turret::srv::TriggerActuator_Request::_distance_m_type arg)
  {
    msg_.distance_m = std::move(arg);
    return std::move(msg_);
  }

private:
  ::antidrone_turret::srv::TriggerActuator_Request msg_;
};

class Init_TriggerActuator_Request_confidence
{
public:
  Init_TriggerActuator_Request_confidence()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TriggerActuator_Request_distance_m confidence(::antidrone_turret::srv::TriggerActuator_Request::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_TriggerActuator_Request_distance_m(msg_);
  }

private:
  ::antidrone_turret::srv::TriggerActuator_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::antidrone_turret::srv::TriggerActuator_Request>()
{
  return antidrone_turret::srv::builder::Init_TriggerActuator_Request_confidence();
}

}  // namespace antidrone_turret


namespace antidrone_turret
{

namespace srv
{

namespace builder
{

class Init_TriggerActuator_Response_trigger_count
{
public:
  explicit Init_TriggerActuator_Response_trigger_count(::antidrone_turret::srv::TriggerActuator_Response & msg)
  : msg_(msg)
  {}
  ::antidrone_turret::srv::TriggerActuator_Response trigger_count(::antidrone_turret::srv::TriggerActuator_Response::_trigger_count_type arg)
  {
    msg_.trigger_count = std::move(arg);
    return std::move(msg_);
  }

private:
  ::antidrone_turret::srv::TriggerActuator_Response msg_;
};

class Init_TriggerActuator_Response_accepted
{
public:
  Init_TriggerActuator_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TriggerActuator_Response_trigger_count accepted(::antidrone_turret::srv::TriggerActuator_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_TriggerActuator_Response_trigger_count(msg_);
  }

private:
  ::antidrone_turret::srv::TriggerActuator_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::antidrone_turret::srv::TriggerActuator_Response>()
{
  return antidrone_turret::srv::builder::Init_TriggerActuator_Response_accepted();
}

}  // namespace antidrone_turret

#endif  // ANTIDRONE_TURRET__SRV__DETAIL__TRIGGER_ACTUATOR__BUILDER_HPP_
