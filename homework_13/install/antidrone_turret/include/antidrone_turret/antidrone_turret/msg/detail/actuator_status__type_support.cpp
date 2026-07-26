// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from antidrone_turret:msg/ActuatorStatus.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "antidrone_turret/msg/detail/actuator_status__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace antidrone_turret
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ActuatorStatus_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) antidrone_turret::msg::ActuatorStatus(_init);
}

void ActuatorStatus_fini_function(void * message_memory)
{
  auto typed_message = static_cast<antidrone_turret::msg::ActuatorStatus *>(message_memory);
  typed_message->~ActuatorStatus();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ActuatorStatus_message_member_array[2] = {
  {
    "state",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(antidrone_turret::msg::ActuatorStatus, state),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "trigger_count",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(antidrone_turret::msg::ActuatorStatus, trigger_count),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ActuatorStatus_message_members = {
  "antidrone_turret::msg",  // message namespace
  "ActuatorStatus",  // message name
  2,  // number of fields
  sizeof(antidrone_turret::msg::ActuatorStatus),
  ActuatorStatus_message_member_array,  // message members
  ActuatorStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  ActuatorStatus_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ActuatorStatus_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ActuatorStatus_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace antidrone_turret


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<antidrone_turret::msg::ActuatorStatus>()
{
  return &::antidrone_turret::msg::rosidl_typesupport_introspection_cpp::ActuatorStatus_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, antidrone_turret, msg, ActuatorStatus)() {
  return &::antidrone_turret::msg::rosidl_typesupport_introspection_cpp::ActuatorStatus_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
