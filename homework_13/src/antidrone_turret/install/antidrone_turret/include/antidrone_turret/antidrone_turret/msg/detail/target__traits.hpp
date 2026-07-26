// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from antidrone_turret:msg/Target.idl
// generated code does not contain a copyright notice

#ifndef ANTIDRONE_TURRET__MSG__DETAIL__TARGET__TRAITS_HPP_
#define ANTIDRONE_TURRET__MSG__DETAIL__TARGET__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "antidrone_turret/msg/detail/target__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace antidrone_turret
{

namespace msg
{

inline void to_flow_style_yaml(
  const Target & msg,
  std::ostream & out)
{
  out << "{";
  // member: visible
  {
    out << "visible: ";
    rosidl_generator_traits::value_to_yaml(msg.visible, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: distance_m
  {
    out << "distance_m: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_m, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Target & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: visible
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "visible: ";
    rosidl_generator_traits::value_to_yaml(msg.visible, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
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

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Target & msg, bool use_flow_style = false)
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
  const antidrone_turret::msg::Target & msg,
  std::ostream & out, size_t indentation = 0)
{
  antidrone_turret::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use antidrone_turret::msg::to_yaml() instead")]]
inline std::string to_yaml(const antidrone_turret::msg::Target & msg)
{
  return antidrone_turret::msg::to_yaml(msg);
}

template<>
inline const char * data_type<antidrone_turret::msg::Target>()
{
  return "antidrone_turret::msg::Target";
}

template<>
inline const char * name<antidrone_turret::msg::Target>()
{
  return "antidrone_turret/msg/Target";
}

template<>
struct has_fixed_size<antidrone_turret::msg::Target>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<antidrone_turret::msg::Target>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<antidrone_turret::msg::Target>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ANTIDRONE_TURRET__MSG__DETAIL__TARGET__TRAITS_HPP_
