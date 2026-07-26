// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from antidrone_turret:msg/TurretStatus.idl
// generated code does not contain a copyright notice

#ifndef ANTIDRONE_TURRET__MSG__DETAIL__TURRET_STATUS__STRUCT_H_
#define ANTIDRONE_TURRET__MSG__DETAIL__TURRET_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'TARGET_NONE'.
enum
{
  antidrone_turret__msg__TurretStatus__TARGET_NONE = 0
};

/// Constant 'TARGET_LOW_CONFIDENCE'.
enum
{
  antidrone_turret__msg__TurretStatus__TARGET_LOW_CONFIDENCE = 1
};

/// Constant 'TARGET_LOCKED'.
enum
{
  antidrone_turret__msg__TurretStatus__TARGET_LOCKED = 2
};

/// Constant 'ACTION_IDLE'.
enum
{
  antidrone_turret__msg__TurretStatus__ACTION_IDLE = 0
};

/// Constant 'ACTION_TRACK'.
enum
{
  antidrone_turret__msg__TurretStatus__ACTION_TRACK = 1
};

/// Constant 'TRIGGER_SKIP'.
enum
{
  antidrone_turret__msg__TurretStatus__TRIGGER_SKIP = 0
};

/// Constant 'TRIGGER_REQUESTED'.
enum
{
  antidrone_turret__msg__TurretStatus__TRIGGER_REQUESTED = 1
};

/// Constant 'TRIGGER_RELOADING'.
enum
{
  antidrone_turret__msg__TurretStatus__TRIGGER_RELOADING = 2
};

/// Struct defined in msg/TurretStatus in the package antidrone_turret.
typedef struct antidrone_turret__msg__TurretStatus
{
  uint8_t target_state;
  uint8_t action;
  uint8_t trigger_state;
  float confidence;
  float distance_m;
} antidrone_turret__msg__TurretStatus;

// Struct for a sequence of antidrone_turret__msg__TurretStatus.
typedef struct antidrone_turret__msg__TurretStatus__Sequence
{
  antidrone_turret__msg__TurretStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} antidrone_turret__msg__TurretStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ANTIDRONE_TURRET__MSG__DETAIL__TURRET_STATUS__STRUCT_H_
