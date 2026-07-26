// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from antidrone_turret:srv/TriggerActuator.idl
// generated code does not contain a copyright notice

#ifndef ANTIDRONE_TURRET__SRV__DETAIL__TRIGGER_ACTUATOR__TRAITS_HPP_
#define ANTIDRONE_TURRET__SRV__DETAIL__TRIGGER_ACTUATOR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "antidrone_turret/srv/detail/trigger_actuator__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace antidrone_turret
{

namespace srv
{

inline void to_flow_style_yaml(
  const TriggerActuator_Request & msg,
  std::ostream & out)
{
  out << "{";
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
  const TriggerActuator_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
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

inline std::string to_yaml(const TriggerActuator_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace antidrone_turret

namespace rosidl_generator_traits
{

[[deprecated("use antidrone_turret::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const antidrone_turret::srv::TriggerActuator_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  antidrone_turret::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use antidrone_turret::srv::to_yaml() instead")]]
inline std::string to_yaml(const antidrone_turret::srv::TriggerActuator_Request & msg)
{
  return antidrone_turret::srv::to_yaml(msg);
}

template<>
inline const char * data_type<antidrone_turret::srv::TriggerActuator_Request>()
{
  return "antidrone_turret::srv::TriggerActuator_Request";
}

template<>
inline const char * name<antidrone_turret::srv::TriggerActuator_Request>()
{
  return "antidrone_turret/srv/TriggerActuator_Request";
}

template<>
struct has_fixed_size<antidrone_turret::srv::TriggerActuator_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<antidrone_turret::srv::TriggerActuator_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<antidrone_turret::srv::TriggerActuator_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace antidrone_turret
{

namespace srv
{

inline void to_flow_style_yaml(
  const TriggerActuator_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
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
  const TriggerActuator_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
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

inline std::string to_yaml(const TriggerActuator_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace antidrone_turret

namespace rosidl_generator_traits
{

[[deprecated("use antidrone_turret::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const antidrone_turret::srv::TriggerActuator_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  antidrone_turret::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use antidrone_turret::srv::to_yaml() instead")]]
inline std::string to_yaml(const antidrone_turret::srv::TriggerActuator_Response & msg)
{
  return antidrone_turret::srv::to_yaml(msg);
}

template<>
inline const char * data_type<antidrone_turret::srv::TriggerActuator_Response>()
{
  return "antidrone_turret::srv::TriggerActuator_Response";
}

template<>
inline const char * name<antidrone_turret::srv::TriggerActuator_Response>()
{
  return "antidrone_turret/srv/TriggerActuator_Response";
}

template<>
struct has_fixed_size<antidrone_turret::srv::TriggerActuator_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<antidrone_turret::srv::TriggerActuator_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<antidrone_turret::srv::TriggerActuator_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<antidrone_turret::srv::TriggerActuator>()
{
  return "antidrone_turret::srv::TriggerActuator";
}

template<>
inline const char * name<antidrone_turret::srv::TriggerActuator>()
{
  return "antidrone_turret/srv/TriggerActuator";
}

template<>
struct has_fixed_size<antidrone_turret::srv::TriggerActuator>
  : std::integral_constant<
    bool,
    has_fixed_size<antidrone_turret::srv::TriggerActuator_Request>::value &&
    has_fixed_size<antidrone_turret::srv::TriggerActuator_Response>::value
  >
{
};

template<>
struct has_bounded_size<antidrone_turret::srv::TriggerActuator>
  : std::integral_constant<
    bool,
    has_bounded_size<antidrone_turret::srv::TriggerActuator_Request>::value &&
    has_bounded_size<antidrone_turret::srv::TriggerActuator_Response>::value
  >
{
};

template<>
struct is_service<antidrone_turret::srv::TriggerActuator>
  : std::true_type
{
};

template<>
struct is_service_request<antidrone_turret::srv::TriggerActuator_Request>
  : std::true_type
{
};

template<>
struct is_service_response<antidrone_turret::srv::TriggerActuator_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ANTIDRONE_TURRET__SRV__DETAIL__TRIGGER_ACTUATOR__TRAITS_HPP_
