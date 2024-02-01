// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from digipot:msg/Digipot.idl
// generated code does not contain a copyright notice

#ifndef DIGIPOT__MSG__DETAIL__DIGIPOT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define DIGIPOT__MSG__DETAIL__DIGIPOT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "digipot/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "digipot/msg/detail/digipot__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace digipot
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_digipot
cdr_serialize(
  const digipot::msg::Digipot & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_digipot
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  digipot::msg::Digipot & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_digipot
get_serialized_size(
  const digipot::msg::Digipot & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_digipot
max_serialized_size_Digipot(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace digipot

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_digipot
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, digipot, msg, Digipot)();

#ifdef __cplusplus
}
#endif

#endif  // DIGIPOT__MSG__DETAIL__DIGIPOT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
