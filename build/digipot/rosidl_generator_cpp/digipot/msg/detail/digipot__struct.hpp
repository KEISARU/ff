// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from digipot:msg/Digipot.idl
// generated code does not contain a copyright notice

#ifndef DIGIPOT__MSG__DETAIL__DIGIPOT__STRUCT_HPP_
#define DIGIPOT__MSG__DETAIL__DIGIPOT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__digipot__msg__Digipot __attribute__((deprecated))
#else
# define DEPRECATED__digipot__msg__Digipot __declspec(deprecated)
#endif

namespace digipot
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Digipot_
{
  using Type = Digipot_<ContainerAllocator>;

  explicit Digipot_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->value = 0;
      this->wiper = 0.0f;
      this->high = 0.0f;
    }
  }

  explicit Digipot_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->value = 0;
      this->wiper = 0.0f;
      this->high = 0.0f;
    }
  }

  // field types and members
  using _value_type =
    int8_t;
  _value_type value;
  using _wiper_type =
    float;
  _wiper_type wiper;
  using _high_type =
    float;
  _high_type high;

  // setters for named parameter idiom
  Type & set__value(
    const int8_t & _arg)
  {
    this->value = _arg;
    return *this;
  }
  Type & set__wiper(
    const float & _arg)
  {
    this->wiper = _arg;
    return *this;
  }
  Type & set__high(
    const float & _arg)
  {
    this->high = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    digipot::msg::Digipot_<ContainerAllocator> *;
  using ConstRawPtr =
    const digipot::msg::Digipot_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<digipot::msg::Digipot_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<digipot::msg::Digipot_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      digipot::msg::Digipot_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<digipot::msg::Digipot_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      digipot::msg::Digipot_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<digipot::msg::Digipot_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<digipot::msg::Digipot_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<digipot::msg::Digipot_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__digipot__msg__Digipot
    std::shared_ptr<digipot::msg::Digipot_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__digipot__msg__Digipot
    std::shared_ptr<digipot::msg::Digipot_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Digipot_ & other) const
  {
    if (this->value != other.value) {
      return false;
    }
    if (this->wiper != other.wiper) {
      return false;
    }
    if (this->high != other.high) {
      return false;
    }
    return true;
  }
  bool operator!=(const Digipot_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Digipot_

// alias to use template instance with default allocator
using Digipot =
  digipot::msg::Digipot_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace digipot

#endif  // DIGIPOT__MSG__DETAIL__DIGIPOT__STRUCT_HPP_
