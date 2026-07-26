// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from antidrone_turret:msg/ServoCommand.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "antidrone_turret/msg/detail/servo_command__rosidl_typesupport_introspection_c.h"
#include "antidrone_turret/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "antidrone_turret/msg/detail/servo_command__functions.h"
#include "antidrone_turret/msg/detail/servo_command__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void antidrone_turret__msg__ServoCommand__rosidl_typesupport_introspection_c__ServoCommand_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  antidrone_turret__msg__ServoCommand__init(message_memory);
}

void antidrone_turret__msg__ServoCommand__rosidl_typesupport_introspection_c__ServoCommand_fini_function(void * message_memory)
{
  antidrone_turret__msg__ServoCommand__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember antidrone_turret__msg__ServoCommand__rosidl_typesupport_introspection_c__ServoCommand_message_member_array[3] = {
  {
    "direction",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(antidrone_turret__msg__ServoCommand, direction),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "target_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(antidrone_turret__msg__ServoCommand, target_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "error_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(antidrone_turret__msg__ServoCommand, error_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers antidrone_turret__msg__ServoCommand__rosidl_typesupport_introspection_c__ServoCommand_message_members = {
  "antidrone_turret__msg",  // message namespace
  "ServoCommand",  // message name
  3,  // number of fields
  sizeof(antidrone_turret__msg__ServoCommand),
  antidrone_turret__msg__ServoCommand__rosidl_typesupport_introspection_c__ServoCommand_message_member_array,  // message members
  antidrone_turret__msg__ServoCommand__rosidl_typesupport_introspection_c__ServoCommand_init_function,  // function to initialize message memory (memory has to be allocated)
  antidrone_turret__msg__ServoCommand__rosidl_typesupport_introspection_c__ServoCommand_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t antidrone_turret__msg__ServoCommand__rosidl_typesupport_introspection_c__ServoCommand_message_type_support_handle = {
  0,
  &antidrone_turret__msg__ServoCommand__rosidl_typesupport_introspection_c__ServoCommand_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_antidrone_turret
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, antidrone_turret, msg, ServoCommand)() {
  if (!antidrone_turret__msg__ServoCommand__rosidl_typesupport_introspection_c__ServoCommand_message_type_support_handle.typesupport_identifier) {
    antidrone_turret__msg__ServoCommand__rosidl_typesupport_introspection_c__ServoCommand_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &antidrone_turret__msg__ServoCommand__rosidl_typesupport_introspection_c__ServoCommand_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
