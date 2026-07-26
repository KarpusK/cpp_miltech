// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from antidrone_turret:srv/TriggerActuator.idl
// generated code does not contain a copyright notice

#ifndef ANTIDRONE_TURRET__SRV__DETAIL__TRIGGER_ACTUATOR__STRUCT_H_
#define ANTIDRONE_TURRET__SRV__DETAIL__TRIGGER_ACTUATOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/TriggerActuator in the package antidrone_turret.
typedef struct antidrone_turret__srv__TriggerActuator_Request
{
  float confidence;
  float distance_m;
} antidrone_turret__srv__TriggerActuator_Request;

// Struct for a sequence of antidrone_turret__srv__TriggerActuator_Request.
typedef struct antidrone_turret__srv__TriggerActuator_Request__Sequence
{
  antidrone_turret__srv__TriggerActuator_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} antidrone_turret__srv__TriggerActuator_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/TriggerActuator in the package antidrone_turret.
typedef struct antidrone_turret__srv__TriggerActuator_Response
{
  bool accepted;
  uint32_t trigger_count;
} antidrone_turret__srv__TriggerActuator_Response;

// Struct for a sequence of antidrone_turret__srv__TriggerActuator_Response.
typedef struct antidrone_turret__srv__TriggerActuator_Response__Sequence
{
  antidrone_turret__srv__TriggerActuator_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} antidrone_turret__srv__TriggerActuator_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ANTIDRONE_TURRET__SRV__DETAIL__TRIGGER_ACTUATOR__STRUCT_H_
