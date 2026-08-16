// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from antidrone_turret:msg/GimbalCommand.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "antidrone_turret/msg/detail/gimbal_command__struct.hpp"
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

void GimbalCommand_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) antidrone_turret::msg::GimbalCommand(_init);
}

void GimbalCommand_fini_function(void * message_memory)
{
  auto typed_message = static_cast<antidrone_turret::msg::GimbalCommand *>(message_memory);
  typed_message->~GimbalCommand();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GimbalCommand_message_member_array[3] = {
  {
    "direction",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(antidrone_turret::msg::GimbalCommand, direction),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "target_y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(antidrone_turret::msg::GimbalCommand, target_y),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "error_y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(antidrone_turret::msg::GimbalCommand, error_y),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GimbalCommand_message_members = {
  "antidrone_turret::msg",  // message namespace
  "GimbalCommand",  // message name
  3,  // number of fields
  sizeof(antidrone_turret::msg::GimbalCommand),
  GimbalCommand_message_member_array,  // message members
  GimbalCommand_init_function,  // function to initialize message memory (memory has to be allocated)
  GimbalCommand_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GimbalCommand_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GimbalCommand_message_members,
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
get_message_type_support_handle<antidrone_turret::msg::GimbalCommand>()
{
  return &::antidrone_turret::msg::rosidl_typesupport_introspection_cpp::GimbalCommand_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, antidrone_turret, msg, GimbalCommand)() {
  return &::antidrone_turret::msg::rosidl_typesupport_introspection_cpp::GimbalCommand_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
