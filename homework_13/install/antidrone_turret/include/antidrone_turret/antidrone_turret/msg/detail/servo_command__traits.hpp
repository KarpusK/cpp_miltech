// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from antidrone_turret:msg/ServoCommand.idl
// generated code does not contain a copyright notice

#ifndef ANTIDRONE_TURRET__MSG__DETAIL__SERVO_COMMAND__TRAITS_HPP_
#define ANTIDRONE_TURRET__MSG__DETAIL__SERVO_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "antidrone_turret/msg/detail/servo_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace antidrone_turret
{

namespace msg
{

inline void to_flow_style_yaml(
  const ServoCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: direction
  {
    out << "direction: ";
    rosidl_generator_traits::value_to_yaml(msg.direction, out);
    out << ", ";
  }

  // member: target_x
  {
    out << "target_x: ";
    rosidl_generator_traits::value_to_yaml(msg.target_x, out);
    out << ", ";
  }

  // member: error_x
  {
    out << "error_x: ";
    rosidl_generator_traits::value_to_yaml(msg.error_x, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ServoCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: direction
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "direction: ";
    rosidl_generator_traits::value_to_yaml(msg.direction, out);
    out << "\n";
  }

  // member: target_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_x: ";
    rosidl_generator_traits::value_to_yaml(msg.target_x, out);
    out << "\n";
  }

  // member: error_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_x: ";
    rosidl_generator_traits::value_to_yaml(msg.error_x, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ServoCommand & msg, bool use_flow_style = false)
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
  const antidrone_turret::msg::ServoCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  antidrone_turret::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use antidrone_turret::msg::to_yaml() instead")]]
inline std::string to_yaml(const antidrone_turret::msg::ServoCommand & msg)
{
  return antidrone_turret::msg::to_yaml(msg);
}

template<>
inline const char * data_type<antidrone_turret::msg::ServoCommand>()
{
  return "antidrone_turret::msg::ServoCommand";
}

template<>
inline const char * name<antidrone_turret::msg::ServoCommand>()
{
  return "antidrone_turret/msg/ServoCommand";
}

template<>
struct has_fixed_size<antidrone_turret::msg::ServoCommand>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<antidrone_turret::msg::ServoCommand>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<antidrone_turret::msg::ServoCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ANTIDRONE_TURRET__MSG__DETAIL__SERVO_COMMAND__TRAITS_HPP_
