// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from antidrone_turret:msg/ServoCommand.idl
// generated code does not contain a copyright notice

#ifndef ANTIDRONE_TURRET__MSG__DETAIL__SERVO_COMMAND__BUILDER_HPP_
#define ANTIDRONE_TURRET__MSG__DETAIL__SERVO_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "antidrone_turret/msg/detail/servo_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace antidrone_turret
{

namespace msg
{

namespace builder
{

class Init_ServoCommand_error_x
{
public:
  explicit Init_ServoCommand_error_x(::antidrone_turret::msg::ServoCommand & msg)
  : msg_(msg)
  {}
  ::antidrone_turret::msg::ServoCommand error_x(::antidrone_turret::msg::ServoCommand::_error_x_type arg)
  {
    msg_.error_x = std::move(arg);
    return std::move(msg_);
  }

private:
  ::antidrone_turret::msg::ServoCommand msg_;
};

class Init_ServoCommand_target_x
{
public:
  explicit Init_ServoCommand_target_x(::antidrone_turret::msg::ServoCommand & msg)
  : msg_(msg)
  {}
  Init_ServoCommand_error_x target_x(::antidrone_turret::msg::ServoCommand::_target_x_type arg)
  {
    msg_.target_x = std::move(arg);
    return Init_ServoCommand_error_x(msg_);
  }

private:
  ::antidrone_turret::msg::ServoCommand msg_;
};

class Init_ServoCommand_direction
{
public:
  Init_ServoCommand_direction()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ServoCommand_target_x direction(::antidrone_turret::msg::ServoCommand::_direction_type arg)
  {
    msg_.direction = std::move(arg);
    return Init_ServoCommand_target_x(msg_);
  }

private:
  ::antidrone_turret::msg::ServoCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::antidrone_turret::msg::ServoCommand>()
{
  return antidrone_turret::msg::builder::Init_ServoCommand_direction();
}

}  // namespace antidrone_turret

#endif  // ANTIDRONE_TURRET__MSG__DETAIL__SERVO_COMMAND__BUILDER_HPP_
