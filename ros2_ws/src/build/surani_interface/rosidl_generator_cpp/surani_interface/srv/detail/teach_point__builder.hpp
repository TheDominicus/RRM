// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from surani_interface:srv/TeachPoint.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "surani_interface/srv/teach_point.hpp"


#ifndef SURANI_INTERFACE__SRV__DETAIL__TEACH_POINT__BUILDER_HPP_
#define SURANI_INTERFACE__SRV__DETAIL__TEACH_POINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "surani_interface/srv/detail/teach_point__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace surani_interface
{

namespace srv
{

namespace builder
{

class Init_TeachPoint_Request_velocity
{
public:
  Init_TeachPoint_Request_velocity()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::surani_interface::srv::TeachPoint_Request velocity(::surani_interface::srv::TeachPoint_Request::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::surani_interface::srv::TeachPoint_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::surani_interface::srv::TeachPoint_Request>()
{
  return surani_interface::srv::builder::Init_TeachPoint_Request_velocity();
}

}  // namespace surani_interface


namespace surani_interface
{

namespace srv
{

namespace builder
{

class Init_TeachPoint_Response_message
{
public:
  explicit Init_TeachPoint_Response_message(::surani_interface::srv::TeachPoint_Response & msg)
  : msg_(msg)
  {}
  ::surani_interface::srv::TeachPoint_Response message(::surani_interface::srv::TeachPoint_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::surani_interface::srv::TeachPoint_Response msg_;
};

class Init_TeachPoint_Response_result
{
public:
  Init_TeachPoint_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TeachPoint_Response_message result(::surani_interface::srv::TeachPoint_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return Init_TeachPoint_Response_message(msg_);
  }

private:
  ::surani_interface::srv::TeachPoint_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::surani_interface::srv::TeachPoint_Response>()
{
  return surani_interface::srv::builder::Init_TeachPoint_Response_result();
}

}  // namespace surani_interface


namespace surani_interface
{

namespace srv
{

namespace builder
{

class Init_TeachPoint_Event_response
{
public:
  explicit Init_TeachPoint_Event_response(::surani_interface::srv::TeachPoint_Event & msg)
  : msg_(msg)
  {}
  ::surani_interface::srv::TeachPoint_Event response(::surani_interface::srv::TeachPoint_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::surani_interface::srv::TeachPoint_Event msg_;
};

class Init_TeachPoint_Event_request
{
public:
  explicit Init_TeachPoint_Event_request(::surani_interface::srv::TeachPoint_Event & msg)
  : msg_(msg)
  {}
  Init_TeachPoint_Event_response request(::surani_interface::srv::TeachPoint_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_TeachPoint_Event_response(msg_);
  }

private:
  ::surani_interface::srv::TeachPoint_Event msg_;
};

class Init_TeachPoint_Event_info
{
public:
  Init_TeachPoint_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TeachPoint_Event_request info(::surani_interface::srv::TeachPoint_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_TeachPoint_Event_request(msg_);
  }

private:
  ::surani_interface::srv::TeachPoint_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::surani_interface::srv::TeachPoint_Event>()
{
  return surani_interface::srv::builder::Init_TeachPoint_Event_info();
}

}  // namespace surani_interface

#endif  // SURANI_INTERFACE__SRV__DETAIL__TEACH_POINT__BUILDER_HPP_
