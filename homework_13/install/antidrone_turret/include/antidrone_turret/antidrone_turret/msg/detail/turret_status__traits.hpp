// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from antidrone_turret:msg/TurretStatus.idl
// generated code does not contain a copyright notice

#ifndef ANTIDRONE_TURRET__MSG__DETAIL__TURRET_STATUS__TRAITS_HPP_
#define ANTIDRONE_TURRET__MSG__DETAIL__TURRET_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "antidrone_turret/msg/detail/turret_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace antidrone_turret
{

namespace msg
{

inline void to_flow_style_yaml(
  const TurretStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: target_state
  {
    out << "target_state: ";
    rosidl_generator_traits::value_to_yaml(msg.target_state, out);
    out << ", ";
  }

  // member: action
  {
    out << "action: ";
    rosidl_generator_traits::value_to_yaml(msg.action, out);
    out << ", ";
  }

  // member: trigger_state
  {
    out << "trigger_state: ";
    rosidl_generator_traits::value_to_yaml(msg.trigger_state, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << ", ";
  }

  // member: distance_m
  {
    out << "distance_m: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_m, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TurretStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: target_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_state: ";
    rosidl_generator_traits::value_to_yaml(msg.target_state, out);
    out << "\n";
  }

  // member: action
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "action: ";
    rosidl_generator_traits::value_to_yaml(msg.action, out);
    out << "\n";
  }

  // member: trigger_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "trigger_state: ";
    rosidl_generator_traits::value_to_yaml(msg.trigger_state, out);
    out << "\n";
  }

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << "\n";
  }

  // member: distance_m
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance_m: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_m, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TurretStatus & msg, bool use_flow_style = false)
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
  const antidrone_turret::msg::TurretStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  antidrone_turret::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use antidrone_turret::msg::to_yaml() instead")]]
inline std::string to_yaml(const antidrone_turret::msg::TurretStatus & msg)
{
  return antidrone_turret::msg::to_yaml(msg);
}

template<>
inline const char * data_type<antidrone_turret::msg::TurretStatus>()
{
  return "antidrone_turret::msg::TurretStatus";
}

template<>
inline const char * name<antidrone_turret::msg::TurretStatus>()
{
  return "antidrone_turret/msg/TurretStatus";
}

template<>
struct has_fixed_size<antidrone_turret::msg::TurretStatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<antidrone_turret::msg::TurretStatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<antidrone_turret::msg::TurretStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ANTIDRONE_TURRET__MSG__DETAIL__TURRET_STATUS__TRAITS_HPP_
