// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from antidrone_turret:srv/TriggerActuator.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "antidrone_turret/srv/detail/trigger_actuator__rosidl_typesupport_introspection_c.h"
#include "antidrone_turret/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "antidrone_turret/srv/detail/trigger_actuator__functions.h"
#include "antidrone_turret/srv/detail/trigger_actuator__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void antidrone_turret__srv__TriggerActuator_Request__rosidl_typesupport_introspection_c__TriggerActuator_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  antidrone_turret__srv__TriggerActuator_Request__init(message_memory);
}

void antidrone_turret__srv__TriggerActuator_Request__rosidl_typesupport_introspection_c__TriggerActuator_Request_fini_function(void * message_memory)
{
  antidrone_turret__srv__TriggerActuator_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember antidrone_turret__srv__TriggerActuator_Request__rosidl_typesupport_introspection_c__TriggerActuator_Request_message_member_array[2] = {
  {
    "confidence",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(antidrone_turret__srv__TriggerActuator_Request, confidence),  // bytes offset in struct
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
    offsetof(antidrone_turret__srv__TriggerActuator_Request, distance_m),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers antidrone_turret__srv__TriggerActuator_Request__rosidl_typesupport_introspection_c__TriggerActuator_Request_message_members = {
  "antidrone_turret__srv",  // message namespace
  "TriggerActuator_Request",  // message name
  2,  // number of fields
  sizeof(antidrone_turret__srv__TriggerActuator_Request),
  antidrone_turret__srv__TriggerActuator_Request__rosidl_typesupport_introspection_c__TriggerActuator_Request_message_member_array,  // message members
  antidrone_turret__srv__TriggerActuator_Request__rosidl_typesupport_introspection_c__TriggerActuator_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  antidrone_turret__srv__TriggerActuator_Request__rosidl_typesupport_introspection_c__TriggerActuator_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t antidrone_turret__srv__TriggerActuator_Request__rosidl_typesupport_introspection_c__TriggerActuator_Request_message_type_support_handle = {
  0,
  &antidrone_turret__srv__TriggerActuator_Request__rosidl_typesupport_introspection_c__TriggerActuator_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_antidrone_turret
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, antidrone_turret, srv, TriggerActuator_Request)() {
  if (!antidrone_turret__srv__TriggerActuator_Request__rosidl_typesupport_introspection_c__TriggerActuator_Request_message_type_support_handle.typesupport_identifier) {
    antidrone_turret__srv__TriggerActuator_Request__rosidl_typesupport_introspection_c__TriggerActuator_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &antidrone_turret__srv__TriggerActuator_Request__rosidl_typesupport_introspection_c__TriggerActuator_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "antidrone_turret/srv/detail/trigger_actuator__rosidl_typesupport_introspection_c.h"
// already included above
// #include "antidrone_turret/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "antidrone_turret/srv/detail/trigger_actuator__functions.h"
// already included above
// #include "antidrone_turret/srv/detail/trigger_actuator__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void antidrone_turret__srv__TriggerActuator_Response__rosidl_typesupport_introspection_c__TriggerActuator_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  antidrone_turret__srv__TriggerActuator_Response__init(message_memory);
}

void antidrone_turret__srv__TriggerActuator_Response__rosidl_typesupport_introspection_c__TriggerActuator_Response_fini_function(void * message_memory)
{
  antidrone_turret__srv__TriggerActuator_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember antidrone_turret__srv__TriggerActuator_Response__rosidl_typesupport_introspection_c__TriggerActuator_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(antidrone_turret__srv__TriggerActuator_Response, accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "trigger_count",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(antidrone_turret__srv__TriggerActuator_Response, trigger_count),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers antidrone_turret__srv__TriggerActuator_Response__rosidl_typesupport_introspection_c__TriggerActuator_Response_message_members = {
  "antidrone_turret__srv",  // message namespace
  "TriggerActuator_Response",  // message name
  2,  // number of fields
  sizeof(antidrone_turret__srv__TriggerActuator_Response),
  antidrone_turret__srv__TriggerActuator_Response__rosidl_typesupport_introspection_c__TriggerActuator_Response_message_member_array,  // message members
  antidrone_turret__srv__TriggerActuator_Response__rosidl_typesupport_introspection_c__TriggerActuator_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  antidrone_turret__srv__TriggerActuator_Response__rosidl_typesupport_introspection_c__TriggerActuator_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t antidrone_turret__srv__TriggerActuator_Response__rosidl_typesupport_introspection_c__TriggerActuator_Response_message_type_support_handle = {
  0,
  &antidrone_turret__srv__TriggerActuator_Response__rosidl_typesupport_introspection_c__TriggerActuator_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_antidrone_turret
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, antidrone_turret, srv, TriggerActuator_Response)() {
  if (!antidrone_turret__srv__TriggerActuator_Response__rosidl_typesupport_introspection_c__TriggerActuator_Response_message_type_support_handle.typesupport_identifier) {
    antidrone_turret__srv__TriggerActuator_Response__rosidl_typesupport_introspection_c__TriggerActuator_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &antidrone_turret__srv__TriggerActuator_Response__rosidl_typesupport_introspection_c__TriggerActuator_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "antidrone_turret/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "antidrone_turret/srv/detail/trigger_actuator__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers antidrone_turret__srv__detail__trigger_actuator__rosidl_typesupport_introspection_c__TriggerActuator_service_members = {
  "antidrone_turret__srv",  // service namespace
  "TriggerActuator",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // antidrone_turret__srv__detail__trigger_actuator__rosidl_typesupport_introspection_c__TriggerActuator_Request_message_type_support_handle,
  NULL  // response message
  // antidrone_turret__srv__detail__trigger_actuator__rosidl_typesupport_introspection_c__TriggerActuator_Response_message_type_support_handle
};

static rosidl_service_type_support_t antidrone_turret__srv__detail__trigger_actuator__rosidl_typesupport_introspection_c__TriggerActuator_service_type_support_handle = {
  0,
  &antidrone_turret__srv__detail__trigger_actuator__rosidl_typesupport_introspection_c__TriggerActuator_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, antidrone_turret, srv, TriggerActuator_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, antidrone_turret, srv, TriggerActuator_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_antidrone_turret
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, antidrone_turret, srv, TriggerActuator)() {
  if (!antidrone_turret__srv__detail__trigger_actuator__rosidl_typesupport_introspection_c__TriggerActuator_service_type_support_handle.typesupport_identifier) {
    antidrone_turret__srv__detail__trigger_actuator__rosidl_typesupport_introspection_c__TriggerActuator_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)antidrone_turret__srv__detail__trigger_actuator__rosidl_typesupport_introspection_c__TriggerActuator_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, antidrone_turret, srv, TriggerActuator_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, antidrone_turret, srv, TriggerActuator_Response)()->data;
  }

  return &antidrone_turret__srv__detail__trigger_actuator__rosidl_typesupport_introspection_c__TriggerActuator_service_type_support_handle;
}
