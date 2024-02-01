// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from digipot_interfaces:msg/Digipot.idl
// generated code does not contain a copyright notice
#include "digipot_interfaces/msg/detail/digipot__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
digipot_interfaces__msg__Digipot__init(digipot_interfaces__msg__Digipot * msg)
{
  if (!msg) {
    return false;
  }
  // value
  // wiper
  // high
  return true;
}

void
digipot_interfaces__msg__Digipot__fini(digipot_interfaces__msg__Digipot * msg)
{
  if (!msg) {
    return;
  }
  // value
  // wiper
  // high
}

bool
digipot_interfaces__msg__Digipot__are_equal(const digipot_interfaces__msg__Digipot * lhs, const digipot_interfaces__msg__Digipot * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // value
  if (lhs->value != rhs->value) {
    return false;
  }
  // wiper
  if (lhs->wiper != rhs->wiper) {
    return false;
  }
  // high
  if (lhs->high != rhs->high) {
    return false;
  }
  return true;
}

bool
digipot_interfaces__msg__Digipot__copy(
  const digipot_interfaces__msg__Digipot * input,
  digipot_interfaces__msg__Digipot * output)
{
  if (!input || !output) {
    return false;
  }
  // value
  output->value = input->value;
  // wiper
  output->wiper = input->wiper;
  // high
  output->high = input->high;
  return true;
}

digipot_interfaces__msg__Digipot *
digipot_interfaces__msg__Digipot__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  digipot_interfaces__msg__Digipot * msg = (digipot_interfaces__msg__Digipot *)allocator.allocate(sizeof(digipot_interfaces__msg__Digipot), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(digipot_interfaces__msg__Digipot));
  bool success = digipot_interfaces__msg__Digipot__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
digipot_interfaces__msg__Digipot__destroy(digipot_interfaces__msg__Digipot * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    digipot_interfaces__msg__Digipot__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
digipot_interfaces__msg__Digipot__Sequence__init(digipot_interfaces__msg__Digipot__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  digipot_interfaces__msg__Digipot * data = NULL;

  if (size) {
    data = (digipot_interfaces__msg__Digipot *)allocator.zero_allocate(size, sizeof(digipot_interfaces__msg__Digipot), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = digipot_interfaces__msg__Digipot__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        digipot_interfaces__msg__Digipot__fini(&data[i - 1]);
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
digipot_interfaces__msg__Digipot__Sequence__fini(digipot_interfaces__msg__Digipot__Sequence * array)
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
      digipot_interfaces__msg__Digipot__fini(&array->data[i]);
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

digipot_interfaces__msg__Digipot__Sequence *
digipot_interfaces__msg__Digipot__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  digipot_interfaces__msg__Digipot__Sequence * array = (digipot_interfaces__msg__Digipot__Sequence *)allocator.allocate(sizeof(digipot_interfaces__msg__Digipot__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = digipot_interfaces__msg__Digipot__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
digipot_interfaces__msg__Digipot__Sequence__destroy(digipot_interfaces__msg__Digipot__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    digipot_interfaces__msg__Digipot__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
digipot_interfaces__msg__Digipot__Sequence__are_equal(const digipot_interfaces__msg__Digipot__Sequence * lhs, const digipot_interfaces__msg__Digipot__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!digipot_interfaces__msg__Digipot__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
digipot_interfaces__msg__Digipot__Sequence__copy(
  const digipot_interfaces__msg__Digipot__Sequence * input,
  digipot_interfaces__msg__Digipot__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(digipot_interfaces__msg__Digipot);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    digipot_interfaces__msg__Digipot * data =
      (digipot_interfaces__msg__Digipot *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!digipot_interfaces__msg__Digipot__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          digipot_interfaces__msg__Digipot__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!digipot_interfaces__msg__Digipot__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
