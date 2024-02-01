// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from digipot_interfaces:msg/Digipot.idl
// generated code does not contain a copyright notice
#include "digipot_interfaces/msg/detail/digipot__rosidl_typesupport_fastrtps_cpp.hpp"
#include "digipot_interfaces/msg/detail/digipot__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace digipot_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_digipot_interfaces
cdr_serialize(
  const digipot_interfaces::msg::Digipot & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: value
  cdr << ros_message.value;
  // Member: wiper
  cdr << ros_message.wiper;
  // Member: high
  cdr << ros_message.high;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_digipot_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  digipot_interfaces::msg::Digipot & ros_message)
{
  // Member: value
  cdr >> ros_message.value;

  // Member: wiper
  cdr >> ros_message.wiper;

  // Member: high
  cdr >> ros_message.high;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_digipot_interfaces
get_serialized_size(
  const digipot_interfaces::msg::Digipot & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: value
  {
    size_t item_size = sizeof(ros_message.value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: wiper
  {
    size_t item_size = sizeof(ros_message.wiper);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: high
  {
    size_t item_size = sizeof(ros_message.high);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_digipot_interfaces
max_serialized_size_Digipot(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: value
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: wiper
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: high
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _Digipot__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const digipot_interfaces::msg::Digipot *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Digipot__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<digipot_interfaces::msg::Digipot *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Digipot__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const digipot_interfaces::msg::Digipot *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Digipot__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Digipot(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Digipot__callbacks = {
  "digipot_interfaces::msg",
  "Digipot",
  _Digipot__cdr_serialize,
  _Digipot__cdr_deserialize,
  _Digipot__get_serialized_size,
  _Digipot__max_serialized_size
};

static rosidl_message_type_support_t _Digipot__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Digipot__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace digipot_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_digipot_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<digipot_interfaces::msg::Digipot>()
{
  return &digipot_interfaces::msg::typesupport_fastrtps_cpp::_Digipot__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, digipot_interfaces, msg, Digipot)() {
  return &digipot_interfaces::msg::typesupport_fastrtps_cpp::_Digipot__handle;
}

#ifdef __cplusplus
}
#endif
