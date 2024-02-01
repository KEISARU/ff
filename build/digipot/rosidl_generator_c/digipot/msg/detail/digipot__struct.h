// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from digipot:msg/Digipot.idl
// generated code does not contain a copyright notice

#ifndef DIGIPOT__MSG__DETAIL__DIGIPOT__STRUCT_H_
#define DIGIPOT__MSG__DETAIL__DIGIPOT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Digipot in the package digipot.
typedef struct digipot__msg__Digipot
{
  int8_t value;
  float wiper;
  float high;
} digipot__msg__Digipot;

// Struct for a sequence of digipot__msg__Digipot.
typedef struct digipot__msg__Digipot__Sequence
{
  digipot__msg__Digipot * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} digipot__msg__Digipot__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DIGIPOT__MSG__DETAIL__DIGIPOT__STRUCT_H_
