// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from antidrone_turret:srv/TriggerActuator.idl
// generated code does not contain a copyright notice
#include "antidrone_turret/srv/detail/trigger_actuator__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
antidrone_turret__srv__TriggerActuator_Request__init(antidrone_turret__srv__TriggerActuator_Request * msg)
{
  if (!msg) {
    return false;
  }
  // confidence
  // distance_m
  return true;
}

void
antidrone_turret__srv__TriggerActuator_Request__fini(antidrone_turret__srv__TriggerActuator_Request * msg)
{
  if (!msg) {
    return;
  }
  // confidence
  // distance_m
}

bool
antidrone_turret__srv__TriggerActuator_Request__are_equal(const antidrone_turret__srv__TriggerActuator_Request * lhs, const antidrone_turret__srv__TriggerActuator_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // confidence
  if (lhs->confidence != rhs->confidence) {
    return false;
  }
  // distance_m
  if (lhs->distance_m != rhs->distance_m) {
    return false;
  }
  return true;
}

bool
antidrone_turret__srv__TriggerActuator_Request__copy(
  const antidrone_turret__srv__TriggerActuator_Request * input,
  antidrone_turret__srv__TriggerActuator_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // confidence
  output->confidence = input->confidence;
  // distance_m
  output->distance_m = input->distance_m;
  return true;
}

antidrone_turret__srv__TriggerActuator_Request *
antidrone_turret__srv__TriggerActuator_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  antidrone_turret__srv__TriggerActuator_Request * msg = (antidrone_turret__srv__TriggerActuator_Request *)allocator.allocate(sizeof(antidrone_turret__srv__TriggerActuator_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(antidrone_turret__srv__TriggerActuator_Request));
  bool success = antidrone_turret__srv__TriggerActuator_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
antidrone_turret__srv__TriggerActuator_Request__destroy(antidrone_turret__srv__TriggerActuator_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    antidrone_turret__srv__TriggerActuator_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
antidrone_turret__srv__TriggerActuator_Request__Sequence__init(antidrone_turret__srv__TriggerActuator_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  antidrone_turret__srv__TriggerActuator_Request * data = NULL;

  if (size) {
    data = (antidrone_turret__srv__TriggerActuator_Request *)allocator.zero_allocate(size, sizeof(antidrone_turret__srv__TriggerActuator_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = antidrone_turret__srv__TriggerActuator_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        antidrone_turret__srv__TriggerActuator_Request__fini(&data[i - 1]);
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
antidrone_turret__srv__TriggerActuator_Request__Sequence__fini(antidrone_turret__srv__TriggerActuator_Request__Sequence * array)
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
      antidrone_turret__srv__TriggerActuator_Request__fini(&array->data[i]);
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

antidrone_turret__srv__TriggerActuator_Request__Sequence *
antidrone_turret__srv__TriggerActuator_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  antidrone_turret__srv__TriggerActuator_Request__Sequence * array = (antidrone_turret__srv__TriggerActuator_Request__Sequence *)allocator.allocate(sizeof(antidrone_turret__srv__TriggerActuator_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = antidrone_turret__srv__TriggerActuator_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
antidrone_turret__srv__TriggerActuator_Request__Sequence__destroy(antidrone_turret__srv__TriggerActuator_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    antidrone_turret__srv__TriggerActuator_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
antidrone_turret__srv__TriggerActuator_Request__Sequence__are_equal(const antidrone_turret__srv__TriggerActuator_Request__Sequence * lhs, const antidrone_turret__srv__TriggerActuator_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!antidrone_turret__srv__TriggerActuator_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
antidrone_turret__srv__TriggerActuator_Request__Sequence__copy(
  const antidrone_turret__srv__TriggerActuator_Request__Sequence * input,
  antidrone_turret__srv__TriggerActuator_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(antidrone_turret__srv__TriggerActuator_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    antidrone_turret__srv__TriggerActuator_Request * data =
      (antidrone_turret__srv__TriggerActuator_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!antidrone_turret__srv__TriggerActuator_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          antidrone_turret__srv__TriggerActuator_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!antidrone_turret__srv__TriggerActuator_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
antidrone_turret__srv__TriggerActuator_Response__init(antidrone_turret__srv__TriggerActuator_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // trigger_count
  return true;
}

void
antidrone_turret__srv__TriggerActuator_Response__fini(antidrone_turret__srv__TriggerActuator_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // trigger_count
}

bool
antidrone_turret__srv__TriggerActuator_Response__are_equal(const antidrone_turret__srv__TriggerActuator_Response * lhs, const antidrone_turret__srv__TriggerActuator_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // trigger_count
  if (lhs->trigger_count != rhs->trigger_count) {
    return false;
  }
  return true;
}

bool
antidrone_turret__srv__TriggerActuator_Response__copy(
  const antidrone_turret__srv__TriggerActuator_Response * input,
  antidrone_turret__srv__TriggerActuator_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // trigger_count
  output->trigger_count = input->trigger_count;
  return true;
}

antidrone_turret__srv__TriggerActuator_Response *
antidrone_turret__srv__TriggerActuator_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  antidrone_turret__srv__TriggerActuator_Response * msg = (antidrone_turret__srv__TriggerActuator_Response *)allocator.allocate(sizeof(antidrone_turret__srv__TriggerActuator_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(antidrone_turret__srv__TriggerActuator_Response));
  bool success = antidrone_turret__srv__TriggerActuator_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
antidrone_turret__srv__TriggerActuator_Response__destroy(antidrone_turret__srv__TriggerActuator_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    antidrone_turret__srv__TriggerActuator_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
antidrone_turret__srv__TriggerActuator_Response__Sequence__init(antidrone_turret__srv__TriggerActuator_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  antidrone_turret__srv__TriggerActuator_Response * data = NULL;

  if (size) {
    data = (antidrone_turret__srv__TriggerActuator_Response *)allocator.zero_allocate(size, sizeof(antidrone_turret__srv__TriggerActuator_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = antidrone_turret__srv__TriggerActuator_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        antidrone_turret__srv__TriggerActuator_Response__fini(&data[i - 1]);
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
antidrone_turret__srv__TriggerActuator_Response__Sequence__fini(antidrone_turret__srv__TriggerActuator_Response__Sequence * array)
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
      antidrone_turret__srv__TriggerActuator_Response__fini(&array->data[i]);
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

antidrone_turret__srv__TriggerActuator_Response__Sequence *
antidrone_turret__srv__TriggerActuator_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  antidrone_turret__srv__TriggerActuator_Response__Sequence * array = (antidrone_turret__srv__TriggerActuator_Response__Sequence *)allocator.allocate(sizeof(antidrone_turret__srv__TriggerActuator_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = antidrone_turret__srv__TriggerActuator_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
antidrone_turret__srv__TriggerActuator_Response__Sequence__destroy(antidrone_turret__srv__TriggerActuator_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    antidrone_turret__srv__TriggerActuator_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
antidrone_turret__srv__TriggerActuator_Response__Sequence__are_equal(const antidrone_turret__srv__TriggerActuator_Response__Sequence * lhs, const antidrone_turret__srv__TriggerActuator_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!antidrone_turret__srv__TriggerActuator_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
antidrone_turret__srv__TriggerActuator_Response__Sequence__copy(
  const antidrone_turret__srv__TriggerActuator_Response__Sequence * input,
  antidrone_turret__srv__TriggerActuator_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(antidrone_turret__srv__TriggerActuator_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    antidrone_turret__srv__TriggerActuator_Response * data =
      (antidrone_turret__srv__TriggerActuator_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!antidrone_turret__srv__TriggerActuator_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          antidrone_turret__srv__TriggerActuator_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!antidrone_turret__srv__TriggerActuator_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
