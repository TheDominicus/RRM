// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from surani_interface:srv/TeachPoint.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "surani_interface/srv/teach_point.hpp"


#ifndef SURANI_INTERFACE__SRV__DETAIL__TEACH_POINT__STRUCT_HPP_
#define SURANI_INTERFACE__SRV__DETAIL__TEACH_POINT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__surani_interface__srv__TeachPoint_Request __attribute__((deprecated))
#else
# define DEPRECATED__surani_interface__srv__TeachPoint_Request __declspec(deprecated)
#endif

namespace surani_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TeachPoint_Request_
{
  using Type = TeachPoint_Request_<ContainerAllocator>;

  explicit TeachPoint_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->velocity = 0.0;
    }
  }

  explicit TeachPoint_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->velocity = 0.0;
    }
  }

  // field types and members
  using _velocity_type =
    double;
  _velocity_type velocity;

  // setters for named parameter idiom
  Type & set__velocity(
    const double & _arg)
  {
    this->velocity = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    surani_interface::srv::TeachPoint_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const surani_interface::srv::TeachPoint_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<surani_interface::srv::TeachPoint_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<surani_interface::srv::TeachPoint_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      surani_interface::srv::TeachPoint_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<surani_interface::srv::TeachPoint_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      surani_interface::srv::TeachPoint_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<surani_interface::srv::TeachPoint_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<surani_interface::srv::TeachPoint_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<surani_interface::srv::TeachPoint_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__surani_interface__srv__TeachPoint_Request
    std::shared_ptr<surani_interface::srv::TeachPoint_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__surani_interface__srv__TeachPoint_Request
    std::shared_ptr<surani_interface::srv::TeachPoint_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TeachPoint_Request_ & other) const
  {
    if (this->velocity != other.velocity) {
      return false;
    }
    return true;
  }
  bool operator!=(const TeachPoint_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TeachPoint_Request_

// alias to use template instance with default allocator
using TeachPoint_Request =
  surani_interface::srv::TeachPoint_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace surani_interface


#ifndef _WIN32
# define DEPRECATED__surani_interface__srv__TeachPoint_Response __attribute__((deprecated))
#else
# define DEPRECATED__surani_interface__srv__TeachPoint_Response __declspec(deprecated)
#endif

namespace surani_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TeachPoint_Response_
{
  using Type = TeachPoint_Response_<ContainerAllocator>;

  explicit TeachPoint_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = false;
      this->message = "";
    }
  }

  explicit TeachPoint_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = false;
      this->message = "";
    }
  }

  // field types and members
  using _result_type =
    bool;
  _result_type result;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__result(
    const bool & _arg)
  {
    this->result = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    surani_interface::srv::TeachPoint_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const surani_interface::srv::TeachPoint_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<surani_interface::srv::TeachPoint_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<surani_interface::srv::TeachPoint_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      surani_interface::srv::TeachPoint_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<surani_interface::srv::TeachPoint_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      surani_interface::srv::TeachPoint_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<surani_interface::srv::TeachPoint_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<surani_interface::srv::TeachPoint_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<surani_interface::srv::TeachPoint_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__surani_interface__srv__TeachPoint_Response
    std::shared_ptr<surani_interface::srv::TeachPoint_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__surani_interface__srv__TeachPoint_Response
    std::shared_ptr<surani_interface::srv::TeachPoint_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TeachPoint_Response_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const TeachPoint_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TeachPoint_Response_

// alias to use template instance with default allocator
using TeachPoint_Response =
  surani_interface::srv::TeachPoint_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace surani_interface


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__surani_interface__srv__TeachPoint_Event __attribute__((deprecated))
#else
# define DEPRECATED__surani_interface__srv__TeachPoint_Event __declspec(deprecated)
#endif

namespace surani_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TeachPoint_Event_
{
  using Type = TeachPoint_Event_<ContainerAllocator>;

  explicit TeachPoint_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit TeachPoint_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<surani_interface::srv::TeachPoint_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<surani_interface::srv::TeachPoint_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<surani_interface::srv::TeachPoint_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<surani_interface::srv::TeachPoint_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<surani_interface::srv::TeachPoint_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<surani_interface::srv::TeachPoint_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<surani_interface::srv::TeachPoint_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<surani_interface::srv::TeachPoint_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    surani_interface::srv::TeachPoint_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const surani_interface::srv::TeachPoint_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<surani_interface::srv::TeachPoint_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<surani_interface::srv::TeachPoint_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      surani_interface::srv::TeachPoint_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<surani_interface::srv::TeachPoint_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      surani_interface::srv::TeachPoint_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<surani_interface::srv::TeachPoint_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<surani_interface::srv::TeachPoint_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<surani_interface::srv::TeachPoint_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__surani_interface__srv__TeachPoint_Event
    std::shared_ptr<surani_interface::srv::TeachPoint_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__surani_interface__srv__TeachPoint_Event
    std::shared_ptr<surani_interface::srv::TeachPoint_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TeachPoint_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const TeachPoint_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TeachPoint_Event_

// alias to use template instance with default allocator
using TeachPoint_Event =
  surani_interface::srv::TeachPoint_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace surani_interface

namespace surani_interface
{

namespace srv
{

struct TeachPoint
{
  using Request = surani_interface::srv::TeachPoint_Request;
  using Response = surani_interface::srv::TeachPoint_Response;
  using Event = surani_interface::srv::TeachPoint_Event;
};

}  // namespace srv

}  // namespace surani_interface

#endif  // SURANI_INTERFACE__SRV__DETAIL__TEACH_POINT__STRUCT_HPP_