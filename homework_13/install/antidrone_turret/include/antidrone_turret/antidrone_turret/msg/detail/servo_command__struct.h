// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from antidrone_turret:msg/ServoCommand.idl
// generated code does not contain a copyright notice

#ifndef ANTIDRONE_TURRET__MSG__DETAIL__SERVO_COMMAND__STRUCT_H_
#define ANTIDRONE_TURRET__MSG__DETAIL__SERVO_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'LEFT'.
enum
{
  antidrone_turret__msg__ServoCommand__LEFT = -1
};

/// Constant 'CENTER'.
enum
{
  antidrone_turret__msg__ServoCommand__CENTER = 0
};

/// Constant 'RIGHT'.
enum
{
  antidrone_turret__msg__ServoCommand__RIGHT = 1
};

/// Struct defined in msg/ServoCommand in the package antidrone_turret.
typedef struct antidrone_turret__msg__ServoCommand
{
  int8_t direction;
  float target_x;
  float error_x;
} antidrone_turret__msg__ServoCommand;

// Struct for a sequence of antidrone_turret__msg__ServoCommand.
typedef struct antidrone_turret__msg__ServoCommand__Sequence
{
  antidrone_turret__msg__ServoCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} antidrone_turret__msg__ServoCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ANTIDRONE_TURRET__MSG__DETAIL__SERVO_COMMAND__STRUCT_H_
