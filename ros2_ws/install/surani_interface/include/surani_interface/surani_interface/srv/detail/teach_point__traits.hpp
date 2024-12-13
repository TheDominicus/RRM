// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from surani_interface:srv/TeachPoint.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "surani_interface/srv/teach_point.hpp"


#ifndef SURANI_INTERFACE__SRV__DETAIL__TEACH_POINT__TRAITS_HPP_
#define SURANI_INTERFACE__SRV__DETAIL__TEACH_POINT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "surani_interface/srv/detail/teach_point__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace surani_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const TeachPoint_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: velocity
  {
    out << "velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.velocity, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TeachPoint_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.velocity, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TeachPoint_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace surani_interface

namespace rosidl_generator_traits
{

[[deprecated("use surani_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const surani_interface::srv::TeachPoint_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  surani_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use surani_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const surani_interface::srv::TeachPoint_Request & msg)
{
  return surani_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<surani_interface::srv::TeachPoint_Request>()
{
  return "surani_interface::srv::TeachPoint_Request";
}

template<>
inline const char * name<surani_interface::srv::TeachPoint_Request>()
{
  return "surani_interface/srv/TeachPoint_Request";
}

template<>
struct has_fixed_size<surani_interface::srv::TeachPoint_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<surani_interface::srv::TeachPoint_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<surani_interface::srv::TeachPoint_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace surani_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const TeachPoint_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: result
  {
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << ", ";
  }

  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TeachPoint_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }

  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TeachPoint_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace surani_interface

namespace rosidl_generator_traits
{

[[deprecated("use surani_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const surani_interface::srv::TeachPoint_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  surani_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use surani_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const surani_interface::srv::TeachPoint_Response & msg)
{
  return surani_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<surani_interface::srv::TeachPoint_Response>()
{
  return "surani_interface::srv::TeachPoint_Response";
}

template<>
inline const char * name<surani_interface::srv::TeachPoint_Response>()
{
  return "surani_interface/srv/TeachPoint_Response";
}

template<>
struct has_fixed_size<surani_interface::srv::TeachPoint_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<surani_interface::srv::TeachPoint_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<surani_interface::srv::TeachPoint_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace surani_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const TeachPoint_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TeachPoint_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TeachPoint_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace surani_interface

namespace rosidl_generator_traits
{

[[deprecated("use surani_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const surani_interface::srv::TeachPoint_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  surani_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use surani_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const surani_interface::srv::TeachPoint_Event & msg)
{
  return surani_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<surani_interface::srv::TeachPoint_Event>()
{
  return "surani_interface::srv::TeachPoint_Event";
}

template<>
inline const char * name<surani_interface::srv::TeachPoint_Event>()
{
  return "surani_interface/srv/TeachPoint_Event";
}

template<>
struct has_fixed_size<surani_interface::srv::TeachPoint_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<surani_interface::srv::TeachPoint_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<surani_interface::srv::TeachPoint_Request>::value && has_bounded_size<surani_interface::srv::TeachPoint_Response>::value> {};

template<>
struct is_message<surani_interface::srv::TeachPoint_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<surani_interface::srv::TeachPoint>()
{
  return "surani_interface::srv::TeachPoint";
}

template<>
inline const char * name<surani_interface::srv::TeachPoint>()
{
  return "surani_interface/srv/TeachPoint";
}

template<>
struct has_fixed_size<surani_interface::srv::TeachPoint>
  : std::integral_constant<
    bool,
    has_fixed_size<surani_interface::srv::TeachPoint_Request>::value &&
    has_fixed_size<surani_interface::srv::TeachPoint_Response>::value
  >
{
};

template<>
struct has_bounded_size<surani_interface::srv::TeachPoint>
  : std::integral_constant<
    bool,
    has_bounded_size<surani_interface::srv::TeachPoint_Request>::value &&
    has_bounded_size<surani_interface::srv::TeachPoint_Response>::value
  >
{
};

template<>
struct is_service<surani_interface::srv::TeachPoint>
  : std::true_type
{
};

template<>
struct is_service_request<surani_interface::srv::TeachPoint_Request>
  : std::true_type
{
};

template<>
struct is_service_response<surani_interface::srv::TeachPoint_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SURANI_INTERFACE__SRV__DETAIL__TEACH_POINT__TRAITS_HPP_
