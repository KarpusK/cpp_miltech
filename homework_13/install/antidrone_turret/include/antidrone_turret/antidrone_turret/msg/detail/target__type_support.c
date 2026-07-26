// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from antidrone_turret:msg/Target.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "antidrone_turret/msg/detail/target__rosidl_typesupport_introspection_c.h"
#include "antidrone_turret/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "antidrone_turret/msg/detail/target__functions.h"
#include "antidrone_turret/msg/detail/target__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void antidrone_turret__msg__Target__rosidl_typesupport_introspection_c__Target_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  antidrone_turret__msg__Target__init(message_memory);
}

void antidrone_turret__msg__Target__rosidl_typesupport_introspection_c__Target_fini_function(void * message_memory)
{
  antidrone_turret__msg__Target__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember antidrone_turret__msg__Target__rosidl_typesupport_introspection_c__Target_message_member_array[5] = {
  {
    "visible",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(antidrone_turret__msg__Target, visible),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(antidrone_turret__msg__Target, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(antidrone_turret__msg__Target, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "distance_m",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(antidrone_turret__msg__Target, distance_m),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "confidence",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(antidrone_turret__msg__Target, confidence),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers antidrone_turret__msg__Target__rosidl_typesupport_introspection_c__Target_message_members = {
  "antidrone_turret__msg",  // message namespace
  "Target",  // message name
  5,  // number of fields
  sizeof(antidrone_turret__msg__Target),
  antidrone_turret__msg__Target__rosidl_typesupport_introspection_c__Target_message_member_array,  // message members
  antidrone_turret__msg__Target__rosidl_typesupport_introspection_c__Target_init_function,  // function to initialize message memory (memory has to be allocated)
  antidrone_turret__msg__Target__rosidl_typesupport_introspection_c__Target_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t antidrone_turret__msg__Target__rosidl_typesupport_introspection_c__Target_message_type_support_handle = {
  0,
  &antidrone_turret__msg__Target__rosidl_typesupport_introspection_c__Target_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_antidrone_turret
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, antidrone_turret, msg, Target)() {
  if (!antidrone_turret__msg__Target__rosidl_typesupport_introspection_c__Target_message_type_support_handle.typesupport_identifier) {
    antidrone_turret__msg__Target__rosidl_typesupport_introspection_c__Target_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &antidrone_turret__msg__Target__rosidl_typesupport_introspection_c__Target_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
