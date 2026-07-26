// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from antidrone_turret:msg/GimbalCommand.idl
// generated code does not contain a copyright notice

#ifndef ANTIDRONE_TURRET__MSG__DETAIL__GIMBAL_COMMAND__BUILDER_HPP_
#define ANTIDRONE_TURRET__MSG__DETAIL__GIMBAL_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "antidrone_turret/msg/detail/gimbal_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace antidrone_turret
{

namespace msg
{

namespace builder
{

class Init_GimbalCommand_error_y
{
public:
  explicit Init_GimbalCommand_error_y(::antidrone_turret::msg::GimbalCommand & msg)
  : msg_(msg)
  {}
  ::antidrone_turret::msg::GimbalCommand error_y(::antidrone_turret::msg::GimbalCommand::_error_y_type arg)
  {
    msg_.error_y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::antidrone_turret::msg::GimbalCommand msg_;
};

class Init_GimbalCommand_target_y
{
public:
  explicit Init_GimbalCommand_target_y(::antidrone_turret::msg::GimbalCommand & msg)
  : msg_(msg)
  {}
  Init_GimbalCommand_error_y target_y(::antidrone_turret::msg::GimbalCommand::_target_y_type arg)
  {
    msg_.target_y = std::move(arg);
    return Init_GimbalCommand_error_y(msg_);
  }

private:
  ::antidrone_turret::msg::GimbalCommand msg_;
};

class Init_GimbalCommand_direction
{
public:
  Init_GimbalCommand_direction()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GimbalCommand_target_y direction(::antidrone_turret::msg::GimbalCommand::_direction_type arg)
  {
    msg_.direction = std::move(arg);
    return Init_GimbalCommand_target_y(msg_);
  }

private:
  ::antidrone_turret::msg::GimbalCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::antidrone_turret::msg::GimbalCommand>()
{
  return antidrone_turret::msg::builder::Init_GimbalCommand_direction();
}

}  // namespace antidrone_turret

#endif  // ANTIDRONE_TURRET__MSG__DETAIL__GIMBAL_COMMAND__BUILDER_HPP_
