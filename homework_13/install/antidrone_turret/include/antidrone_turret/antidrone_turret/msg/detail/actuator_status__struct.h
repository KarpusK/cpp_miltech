// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from antidrone_turret:msg/ActuatorStatus.idl
// generated code does not contain a copyright notice

#ifndef ANTIDRONE_TURRET__MSG__DETAIL__ACTUATOR_STATUS__STRUCT_H_
#define ANTIDRONE_TURRET__MSG__DETAIL__ACTUATOR_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'READY'.
enum
{
  antidrone_turret__msg__ActuatorStatus__READY = 0
};

/// Constant 'RELOADING'.
enum
{
  antidrone_turret__msg__ActuatorStatus__RELOADING = 1
};

/// Struct defined in msg/ActuatorStatus in the package antidrone_turret.
typedef struct antidrone_turret__msg__ActuatorStatus
{
  uint8_t state;
  uint32_t trigger_count;
} antidrone_turret__msg__ActuatorStatus;

// Struct for a sequence of antidrone_turret__msg__ActuatorStatus.
typedef struct antidrone_turret__msg__ActuatorStatus__Sequence
{
  antidrone_turret__msg__ActuatorStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} antidrone_turret__msg__ActuatorStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ANTIDRONE_TURRET__MSG__DETAIL__ACTUATOR_STATUS__STRUCT_H_
