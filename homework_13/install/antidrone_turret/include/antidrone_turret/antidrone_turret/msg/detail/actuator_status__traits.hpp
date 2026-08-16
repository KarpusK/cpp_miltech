// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from antidrone_turret:msg/ActuatorStatus.idl
// generated code does not contain a copyright notice

#ifndef ANTIDRONE_TURRET__MSG__DETAIL__ACTUATOR_STATUS__TRAITS_HPP_
#define ANTIDRONE_TURRET__MSG__DETAIL__ACTUATOR_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "antidrone_turret/msg/detail/actuator_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace antidrone_turret
{

namespace msg
{

inline void to_flow_style_yaml(
  const ActuatorStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: state
  {
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << ", ";
  }

  // member: trigger_count
  {
    out << "trigger_count: ";
    rosidl_generator_traits::value_to_yaml(msg.trigger_count, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ActuatorStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << "\n";
  }

  // member: trigger_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "trigger_count: ";
    rosidl_generator_traits::value_to_yaml(msg.trigger_count, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ActuatorStatus & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace antidrone_turret

namespace rosidl_generator_traits
{

[[deprecated("use antidrone_turret::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const antidrone_turret::msg::ActuatorStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  antidrone_turret::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use antidrone_turret::msg::to_yaml() instead")]]
inline std::string to_yaml(const antidrone_turret::msg::ActuatorStatus & msg)
{
  return antidrone_turret::msg::to_yaml(msg);
}

template<>
inline const char * data_type<antidrone_turret::msg::ActuatorStatus>()
{
  return "antidrone_turret::msg::ActuatorStatus";
}

template<>
inline const char * name<antidrone_turret::msg::ActuatorStatus>()
{
  return "antidrone_turret/msg/ActuatorStatus";
}

template<>
struct has_fixed_size<antidrone_turret::msg::ActuatorStatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<antidrone_turret::msg::ActuatorStatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<antidrone_turret::msg::ActuatorStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ANTIDRONE_TURRET__MSG__DETAIL__ACTUATOR_STATUS__TRAITS_HPP_
