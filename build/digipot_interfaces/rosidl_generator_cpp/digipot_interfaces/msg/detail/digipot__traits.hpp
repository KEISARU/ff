// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from digipot_interfaces:msg/Digipot.idl
// generated code does not contain a copyright notice

#ifndef DIGIPOT_INTERFACES__MSG__DETAIL__DIGIPOT__TRAITS_HPP_
#define DIGIPOT_INTERFACES__MSG__DETAIL__DIGIPOT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "digipot_interfaces/msg/detail/digipot__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace digipot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Digipot & msg,
  std::ostream & out)
{
  out << "{";
  // member: value
  {
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
    out << ", ";
  }

  // member: wiper
  {
    out << "wiper: ";
    rosidl_generator_traits::value_to_yaml(msg.wiper, out);
    out << ", ";
  }

  // member: high
  {
    out << "high: ";
    rosidl_generator_traits::value_to_yaml(msg.high, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Digipot & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
    out << "\n";
  }

  // member: wiper
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "wiper: ";
    rosidl_generator_traits::value_to_yaml(msg.wiper, out);
    out << "\n";
  }

  // member: high
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "high: ";
    rosidl_generator_traits::value_to_yaml(msg.high, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Digipot & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace digipot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use digipot_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const digipot_interfaces::msg::Digipot & msg,
  std::ostream & out, size_t indentation = 0)
{
  digipot_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use digipot_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const digipot_interfaces::msg::Digipot & msg)
{
  return digipot_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<digipot_interfaces::msg::Digipot>()
{
  return "digipot_interfaces::msg::Digipot";
}

template<>
inline const char * name<digipot_interfaces::msg::Digipot>()
{
  return "digipot_interfaces/msg/Digipot";
}

template<>
struct has_fixed_size<digipot_interfaces::msg::Digipot>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<digipot_interfaces::msg::Digipot>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<digipot_interfaces::msg::Digipot>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DIGIPOT_INTERFACES__MSG__DETAIL__DIGIPOT__TRAITS_HPP_
