// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from digipot_interfaces:msg/Digipot.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "digipot_interfaces/msg/detail/digipot__rosidl_typesupport_introspection_c.h"
#include "digipot_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "digipot_interfaces/msg/detail/digipot__functions.h"
#include "digipot_interfaces/msg/detail/digipot__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void digipot_interfaces__msg__Digipot__rosidl_typesupport_introspection_c__Digipot_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  digipot_interfaces__msg__Digipot__init(message_memory);
}

void digipot_interfaces__msg__Digipot__rosidl_typesupport_introspection_c__Digipot_fini_function(void * message_memory)
{
  digipot_interfaces__msg__Digipot__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember digipot_interfaces__msg__Digipot__rosidl_typesupport_introspection_c__Digipot_message_member_array[3] = {
  {
    "value",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(digipot_interfaces__msg__Digipot, value),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "wiper",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(digipot_interfaces__msg__Digipot, wiper),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "high",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(digipot_interfaces__msg__Digipot, high),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers digipot_interfaces__msg__Digipot__rosidl_typesupport_introspection_c__Digipot_message_members = {
  "digipot_interfaces__msg",  // message namespace
  "Digipot",  // message name
  3,  // number of fields
  sizeof(digipot_interfaces__msg__Digipot),
  digipot_interfaces__msg__Digipot__rosidl_typesupport_introspection_c__Digipot_message_member_array,  // message members
  digipot_interfaces__msg__Digipot__rosidl_typesupport_introspection_c__Digipot_init_function,  // function to initialize message memory (memory has to be allocated)
  digipot_interfaces__msg__Digipot__rosidl_typesupport_introspection_c__Digipot_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t digipot_interfaces__msg__Digipot__rosidl_typesupport_introspection_c__Digipot_message_type_support_handle = {
  0,
  &digipot_interfaces__msg__Digipot__rosidl_typesupport_introspection_c__Digipot_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_digipot_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, digipot_interfaces, msg, Digipot)() {
  if (!digipot_interfaces__msg__Digipot__rosidl_typesupport_introspection_c__Digipot_message_type_support_handle.typesupport_identifier) {
    digipot_interfaces__msg__Digipot__rosidl_typesupport_introspection_c__Digipot_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &digipot_interfaces__msg__Digipot__rosidl_typesupport_introspection_c__Digipot_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
