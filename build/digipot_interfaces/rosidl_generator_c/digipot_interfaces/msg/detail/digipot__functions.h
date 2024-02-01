// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from digipot_interfaces:msg/Digipot.idl
// generated code does not contain a copyright notice

#ifndef DIGIPOT_INTERFACES__MSG__DETAIL__DIGIPOT__FUNCTIONS_H_
#define DIGIPOT_INTERFACES__MSG__DETAIL__DIGIPOT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "digipot_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "digipot_interfaces/msg/detail/digipot__struct.h"

/// Initialize msg/Digipot message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * digipot_interfaces__msg__Digipot
 * )) before or use
 * digipot_interfaces__msg__Digipot__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_digipot_interfaces
bool
digipot_interfaces__msg__Digipot__init(digipot_interfaces__msg__Digipot * msg);

/// Finalize msg/Digipot message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_digipot_interfaces
void
digipot_interfaces__msg__Digipot__fini(digipot_interfaces__msg__Digipot * msg);

/// Create msg/Digipot message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * digipot_interfaces__msg__Digipot__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_digipot_interfaces
digipot_interfaces__msg__Digipot *
digipot_interfaces__msg__Digipot__create();

/// Destroy msg/Digipot message.
/**
 * It calls
 * digipot_interfaces__msg__Digipot__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_digipot_interfaces
void
digipot_interfaces__msg__Digipot__destroy(digipot_interfaces__msg__Digipot * msg);

/// Check for msg/Digipot message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_digipot_interfaces
bool
digipot_interfaces__msg__Digipot__are_equal(const digipot_interfaces__msg__Digipot * lhs, const digipot_interfaces__msg__Digipot * rhs);

/// Copy a msg/Digipot message.
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
ROSIDL_GENERATOR_C_PUBLIC_digipot_interfaces
bool
digipot_interfaces__msg__Digipot__copy(
  const digipot_interfaces__msg__Digipot * input,
  digipot_interfaces__msg__Digipot * output);

/// Initialize array of msg/Digipot messages.
/**
 * It allocates the memory for the number of elements and calls
 * digipot_interfaces__msg__Digipot__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_digipot_interfaces
bool
digipot_interfaces__msg__Digipot__Sequence__init(digipot_interfaces__msg__Digipot__Sequence * array, size_t size);

/// Finalize array of msg/Digipot messages.
/**
 * It calls
 * digipot_interfaces__msg__Digipot__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_digipot_interfaces
void
digipot_interfaces__msg__Digipot__Sequence__fini(digipot_interfaces__msg__Digipot__Sequence * array);

/// Create array of msg/Digipot messages.
/**
 * It allocates the memory for the array and calls
 * digipot_interfaces__msg__Digipot__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_digipot_interfaces
digipot_interfaces__msg__Digipot__Sequence *
digipot_interfaces__msg__Digipot__Sequence__create(size_t size);

/// Destroy array of msg/Digipot messages.
/**
 * It calls
 * digipot_interfaces__msg__Digipot__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_digipot_interfaces
void
digipot_interfaces__msg__Digipot__Sequence__destroy(digipot_interfaces__msg__Digipot__Sequence * array);

/// Check for msg/Digipot message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_digipot_interfaces
bool
digipot_interfaces__msg__Digipot__Sequence__are_equal(const digipot_interfaces__msg__Digipot__Sequence * lhs, const digipot_interfaces__msg__Digipot__Sequence * rhs);

/// Copy an array of msg/Digipot messages.
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
ROSIDL_GENERATOR_C_PUBLIC_digipot_interfaces
bool
digipot_interfaces__msg__Digipot__Sequence__copy(
  const digipot_interfaces__msg__Digipot__Sequence * input,
  digipot_interfaces__msg__Digipot__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // DIGIPOT_INTERFACES__MSG__DETAIL__DIGIPOT__FUNCTIONS_H_
