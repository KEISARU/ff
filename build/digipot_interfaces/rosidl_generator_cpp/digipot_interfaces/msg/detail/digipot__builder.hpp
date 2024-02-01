// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from digipot_interfaces:msg/Digipot.idl
// generated code does not contain a copyright notice

#ifndef DIGIPOT_INTERFACES__MSG__DETAIL__DIGIPOT__BUILDER_HPP_
#define DIGIPOT_INTERFACES__MSG__DETAIL__DIGIPOT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "digipot_interfaces/msg/detail/digipot__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace digipot_interfaces
{

namespace msg
{

namespace builder
{

class Init_Digipot_high
{
public:
  explicit Init_Digipot_high(::digipot_interfaces::msg::Digipot & msg)
  : msg_(msg)
  {}
  ::digipot_interfaces::msg::Digipot high(::digipot_interfaces::msg::Digipot::_high_type arg)
  {
    msg_.high = std::move(arg);
    return std::move(msg_);
  }

private:
  ::digipot_interfaces::msg::Digipot msg_;
};

class Init_Digipot_wiper
{
public:
  explicit Init_Digipot_wiper(::digipot_interfaces::msg::Digipot & msg)
  : msg_(msg)
  {}
  Init_Digipot_high wiper(::digipot_interfaces::msg::Digipot::_wiper_type arg)
  {
    msg_.wiper = std::move(arg);
    return Init_Digipot_high(msg_);
  }

private:
  ::digipot_interfaces::msg::Digipot msg_;
};

class Init_Digipot_value
{
public:
  Init_Digipot_value()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Digipot_wiper value(::digipot_interfaces::msg::Digipot::_value_type arg)
  {
    msg_.value = std::move(arg);
    return Init_Digipot_wiper(msg_);
  }

private:
  ::digipot_interfaces::msg::Digipot msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::digipot_interfaces::msg::Digipot>()
{
  return digipot_interfaces::msg::builder::Init_Digipot_value();
}

}  // namespace digipot_interfaces

#endif  // DIGIPOT_INTERFACES__MSG__DETAIL__DIGIPOT__BUILDER_HPP_
