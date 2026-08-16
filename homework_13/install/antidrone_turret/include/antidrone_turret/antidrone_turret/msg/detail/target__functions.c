// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from antidrone_turret:msg/Target.idl
// generated code does not contain a copyright notice
#include "antidrone_turret/msg/detail/target__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
antidrone_turret__msg__Target__init(antidrone_turret__msg__Target * msg)
{
  if (!msg) {
    return false;
  }
  // visible
  // x
  // y
  // distance_m
  // confidence
  return true;
}

void
antidrone_turret__msg__Target__fini(antidrone_turret__msg__Target * msg)
{
  if (!msg) {
    return;
  }
  // visible
  // x
  // y
  // distance_m
  // confidence
}

bool
antidrone_turret__msg__Target__are_equal(const antidrone_turret__msg__Target * lhs, const antidrone_turret__msg__Target * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // visible
  if (lhs->visible != rhs->visible) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // distance_m
  if (lhs->distance_m != rhs->distance_m) {
    return false;
  }
  // confidence
  if (lhs->confidence != rhs->confidence) {
    return false;
  }
  return true;
}

bool
antidrone_turret__msg__Target__copy(
  const antidrone_turret__msg__Target * input,
  antidrone_turret__msg__Target * output)
{
  if (!input || !output) {
    return false;
  }
  // visible
  output->visible = input->visible;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // distance_m
  output->distance_m = input->distance_m;
  // confidence
  output->confidence = input->confidence;
  return true;
}

antidrone_turret__msg__Target *
antidrone_turret__msg__Target__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  antidrone_turret__msg__Target * msg = (antidrone_turret__msg__Target *)allocator.allocate(sizeof(antidrone_turret__msg__Target), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(antidrone_turret__msg__Target));
  bool success = antidrone_turret__msg__Target__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
antidrone_turret__msg__Target__destroy(antidrone_turret__msg__Target * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    antidrone_turret__msg__Target__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
antidrone_turret__msg__Target__Sequence__init(antidrone_turret__msg__Target__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  antidrone_turret__msg__Target * data = NULL;

  if (size) {
    data = (antidrone_turret__msg__Target *)allocator.zero_allocate(size, sizeof(antidrone_turret__msg__Target), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = antidrone_turret__msg__Target__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        antidrone_turret__msg__Target__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
antidrone_turret__msg__Target__Sequence__fini(antidrone_turret__msg__Target__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      antidrone_turret__msg__Target__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

antidrone_turret__msg__Target__Sequence *
antidrone_turret__msg__Target__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  antidrone_turret__msg__Target__Sequence * array = (antidrone_turret__msg__Target__Sequence *)allocator.allocate(sizeof(antidrone_turret__msg__Target__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = antidrone_turret__msg__Target__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
antidrone_turret__msg__Target__Sequence__destroy(antidrone_turret__msg__Target__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    antidrone_turret__msg__Target__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
antidrone_turret__msg__Target__Sequence__are_equal(const antidrone_turret__msg__Target__Sequence * lhs, const antidrone_turret__msg__Target__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!antidrone_turret__msg__Target__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
antidrone_turret__msg__Target__Sequence__copy(
  const antidrone_turret__msg__Target__Sequence * input,
  antidrone_turret__msg__Target__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(antidrone_turret__msg__Target);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    antidrone_turret__msg__Target * data =
      (antidrone_turret__msg__Target *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!antidrone_turret__msg__Target__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          antidrone_turret__msg__Target__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!antidrone_turret__msg__Target__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
