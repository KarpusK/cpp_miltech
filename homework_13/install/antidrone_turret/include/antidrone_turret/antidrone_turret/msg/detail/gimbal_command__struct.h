// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from antidrone_turret:msg/GimbalCommand.idl
// generated code does not contain a copyright notice

#ifndef ANTIDRONE_TURRET__MSG__DETAIL__GIMBAL_COMMAND__STRUCT_H_
#define ANTIDRONE_TURRET__MSG__DETAIL__GIMBAL_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'DOWN'.
enum
{
  antidrone_turret__msg__GimbalCommand__DOWN = -1
};

/// Constant 'CENTER'.
enum
{
  antidrone_turret__msg__GimbalCommand__CENTER = 0
};

/// Constant 'UP'.
enum
{
  antidrone_turret__msg__GimbalCommand__UP = 1
};

/// Struct defined in msg/GimbalCommand in the package antidrone_turret.
typedef struct antidrone_turret__msg__GimbalCommand
{
  int8_t direction;
  float target_y;
  float error_y;
} antidrone_turret__msg__GimbalCommand;

// Struct for a sequence of antidrone_turret__msg__GimbalCommand.
typedef struct antidrone_turret__msg__GimbalCommand__Sequence
{
  antidrone_turret__msg__GimbalCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} antidrone_turret__msg__GimbalCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ANTIDRONE_TURRET__MSG__DETAIL__GIMBAL_COMMAND__STRUCT_H_
