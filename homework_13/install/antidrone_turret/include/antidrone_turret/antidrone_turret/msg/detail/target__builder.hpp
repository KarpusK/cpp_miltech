// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from antidrone_turret:msg/Target.idl
// generated code does not contain a copyright notice

#ifndef ANTIDRONE_TURRET__MSG__DETAIL__TARGET__BUILDER_HPP_
#define ANTIDRONE_TURRET__MSG__DETAIL__TARGET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "antidrone_turret/msg/detail/target__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace antidrone_turret
{

namespace msg
{

namespace builder
{

class Init_Target_confidence
{
public:
  explicit Init_Target_confidence(::antidrone_turret::msg::Target & msg)
  : msg_(msg)
  {}
  ::antidrone_turret::msg::Target confidence(::antidrone_turret::msg::Target::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return std::move(msg_);
  }

private:
  ::antidrone_turret::msg::Target msg_;
};

class Init_Target_distance_m
{
public:
  explicit Init_Target_distance_m(::antidrone_turret::msg::Target & msg)
  : msg_(msg)
  {}
  Init_Target_confidence distance_m(::antidrone_turret::msg::Target::_distance_m_type arg)
  {
    msg_.distance_m = std::move(arg);
    return Init_Target_confidence(msg_);
  }

private:
  ::antidrone_turret::msg::Target msg_;
};

class Init_Target_y
{
public:
  explicit Init_Target_y(::antidrone_turret::msg::Target & msg)
  : msg_(msg)
  {}
  Init_Target_distance_m y(::antidrone_turret::msg::Target::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Target_distance_m(msg_);
  }

private:
  ::antidrone_turret::msg::Target msg_;
};

class Init_Target_x
{
public:
  explicit Init_Target_x(::antidrone_turret::msg::Target & msg)
  : msg_(msg)
  {}
  Init_Target_y x(::antidrone_turret::msg::Target::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Target_y(msg_);
  }

private:
  ::antidrone_turret::msg::Target msg_;
};

class Init_Target_visible
{
public:
  Init_Target_visible()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Target_x visible(::antidrone_turret::msg::Target::_visible_type arg)
  {
    msg_.visible = std::move(arg);
    return Init_Target_x(msg_);
  }

private:
  ::antidrone_turret::msg::Target msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::antidrone_turret::msg::Target>()
{
  return antidrone_turret::msg::builder::Init_Target_visible();
}

}  // namespace antidrone_turret

#endif  // ANTIDRONE_TURRET__MSG__DETAIL__TARGET__BUILDER_HPP_
