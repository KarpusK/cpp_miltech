// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from antidrone_turret:msg/Target.idl
// generated code does not contain a copyright notice

#ifndef ANTIDRONE_TURRET__MSG__DETAIL__TARGET__STRUCT_H_
#define ANTIDRONE_TURRET__MSG__DETAIL__TARGET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Target in the package antidrone_turret.
typedef struct antidrone_turret__msg__Target
{
  bool visible;
  float x;
  float y;
  float distance_m;
  float confidence;
} antidrone_turret__msg__Target;

// Struct for a sequence of antidrone_turret__msg__Target.
typedef struct antidrone_turret__msg__Target__Sequence
{
  antidrone_turret__msg__Target * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} antidrone_turret__msg__Target__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ANTIDRONE_TURRET__MSG__DETAIL__TARGET__STRUCT_H_
