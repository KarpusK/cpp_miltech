// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from antidrone_turret:srv/TriggerActuator.idl
// generated code does not contain a copyright notice

#ifndef ANTIDRONE_TURRET__SRV__DETAIL__TRIGGER_ACTUATOR__FUNCTIONS_H_
#define ANTIDRONE_TURRET__SRV__DETAIL__TRIGGER_ACTUATOR__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "antidrone_turret/msg/rosidl_generator_c__visibility_control.h"

#include "antidrone_turret/srv/detail/trigger_actuator__struct.h"

/// Initialize srv/TriggerActuator message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * antidrone_turret__srv__TriggerActuator_Request
 * )) before or use
 * antidrone_turret__srv__TriggerActuator_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_antidrone_turret
bool
antidrone_turret__srv__TriggerActuator_Request__init(antidrone_turret__srv__TriggerActuator_Request * msg);

/// Finalize srv/TriggerActuator message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_antidrone_turret
void
antidrone_turret__srv__TriggerActuator_Request__fini(antidrone_turret__srv__TriggerActuator_Request * msg);

/// Create srv/TriggerActuator message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * antidrone_turret__srv__TriggerActuator_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_antidrone_turret
antidrone_turret__srv__TriggerActuator_Request *
antidrone_turret__srv__TriggerActuator_Request__create();

/// Destroy srv/TriggerActuator message.
/**
 * It calls
 * antidrone_turret__srv__TriggerActuator_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_antidrone_turret
void
antidrone_turret__srv__TriggerActuator_Request__destroy(antidrone_turret__srv__TriggerActuator_Request * msg);

/// Check for srv/TriggerActuator message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_antidrone_turret
bool
antidrone_turret__srv__TriggerActuator_Request__are_equal(const antidrone_turret__srv__TriggerActuator_Request * lhs, const antidrone_turret__srv__TriggerActuator_Request * rhs);

/// Copy a srv/TriggerActuator message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_antidrone_turret
bool
antidrone_turret__srv__TriggerActuator_Request__copy(
  const antidrone_turret__srv__TriggerActuator_Request * input,
  antidrone_turret__srv__TriggerActuator_Request * output);

/// Initialize array of srv/TriggerActuator messages.
/**
 * It allocates the memory for the number of elements and calls
 * antidrone_turret__srv__TriggerActuator_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_antidrone_turret
bool
antidrone_turret__srv__TriggerActuator_Request__Sequence__init(antidrone_turret__srv__TriggerActuator_Request__Sequence * array, size_t size);

/// Finalize array of srv/TriggerActuator messages.
/**
 * It calls
 * antidrone_turret__srv__TriggerActuator_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_antidrone_turret
void
antidrone_turret__srv__TriggerActuator_Request__Sequence__fini(antidrone_turret__srv__TriggerActuator_Request__Sequence * array);

/// Create array of srv/TriggerActuator messages.
/**
 * It allocates the memory for the array and calls
 * antidrone_turret__srv__TriggerActuator_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_antidrone_turret
antidrone_turret__srv__TriggerActuator_Request__Sequence *
antidrone_turret__srv__TriggerActuator_Request__Sequence__create(size_t size);

/// Destroy array of srv/TriggerActuator messages.
/**
 * It calls
 * antidrone_turret__srv__TriggerActuator_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_antidrone_turret
void
antidrone_turret__srv__TriggerActuator_Request__Sequence__destroy(antidrone_turret__srv__TriggerActuator_Request__Sequence * array);

/// Check for srv/TriggerActuator message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_antidrone_turret
bool
antidrone_turret__srv__TriggerActuator_Request__Sequence__are_equal(const antidrone_turret__srv__TriggerActuator_Request__Sequence * lhs, const antidrone_turret__srv__TriggerActuator_Request__Sequence * rhs);

/// Copy an array of srv/TriggerActuator messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_antidrone_turret
bool
antidrone_turret__srv__TriggerActuator_Request__Sequence__copy(
  const antidrone_turret__srv__TriggerActuator_Request__Sequence * input,
  antidrone_turret__srv__TriggerActuator_Request__Sequence * output);

/// Initialize srv/TriggerActuator message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * antidrone_turret__srv__TriggerActuator_Response
 * )) before or use
 * antidrone_turret__srv__TriggerActuator_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_antidrone_turret
bool
antidrone_turret__srv__TriggerActuator_Response__init(antidrone_turret__srv__TriggerActuator_Response * msg);

/// Finalize srv/TriggerActuator message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_antidrone_turret
void
antidrone_turret__srv__TriggerActuator_Response__fini(antidrone_turret__srv__TriggerActuator_Response * msg);

/// Create srv/TriggerActuator message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * antidrone_turret__srv__TriggerActuator_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_antidrone_turret
antidrone_turret__srv__TriggerActuator_Response *
antidrone_turret__srv__TriggerActuator_Response__create();

/// Destroy srv/TriggerActuator message.
/**
 * It calls
 * antidrone_turret__srv__TriggerActuator_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_antidrone_turret
void
antidrone_turret__srv__TriggerActuator_Response__destroy(antidrone_turret__srv__TriggerActuator_Response * msg);

/// Check for srv/TriggerActuator message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_antidrone_turret
bool
antidrone_turret__srv__TriggerActuator_Response__are_equal(const antidrone_turret__srv__TriggerActuator_Response * lhs, const antidrone_turret__srv__TriggerActuator_Response * rhs);

/// Copy a srv/TriggerActuator message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_antidrone_turret
bool
antidrone_turret__srv__TriggerActuator_Response__copy(
  const antidrone_turret__srv__TriggerActuator_Response * input,
  antidrone_turret__srv__TriggerActuator_Response * output);

/// Initialize array of srv/TriggerActuator messages.
/**
 * It allocates the memory for the number of elements and calls
 * antidrone_turret__srv__TriggerActuator_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_antidrone_turret
bool
antidrone_turret__srv__TriggerActuator_Response__Sequence__init(antidrone_turret__srv__TriggerActuator_Response__Sequence * array, size_t size);

/// Finalize array of srv/TriggerActuator messages.
/**
 * It calls
 * antidrone_turret__srv__TriggerActuator_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_antidrone_turret
void
antidrone_turret__srv__TriggerActuator_Response__Sequence__fini(antidrone_turret__srv__TriggerActuator_Response__Sequence * array);

/// Create array of srv/TriggerActuator messages.
/**
 * It allocates the memory for the array and calls
 * antidrone_turret__srv__TriggerActuator_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_antidrone_turret
antidrone_turret__srv__TriggerActuator_Response__Sequence *
antidrone_turret__srv__TriggerActuator_Response__Sequence__create(size_t size);

/// Destroy array of srv/TriggerActuator messages.
/**
 * It calls
 * antidrone_turret__srv__TriggerActuator_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_antidrone_turret
void
antidrone_turret__srv__TriggerActuator_Response__Sequence__destroy(antidrone_turret__srv__TriggerActuator_Response__Sequence * array);

/// Check for srv/TriggerActuator message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_antidrone_turret
bool
antidrone_turret__srv__TriggerActuator_Response__Sequence__are_equal(const antidrone_turret__srv__TriggerActuator_Response__Sequence * lhs, const antidrone_turret__srv__TriggerActuator_Response__Sequence * rhs);

/// Copy an array of srv/TriggerActuator messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_antidrone_turret
bool
antidrone_turret__srv__TriggerActuator_Response__Sequence__copy(
  const antidrone_turret__srv__TriggerActuator_Response__Sequence * input,
  antidrone_turret__srv__TriggerActuator_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // ANTIDRONE_TURRET__SRV__DETAIL__TRIGGER_ACTUATOR__FUNCTIONS_H_
