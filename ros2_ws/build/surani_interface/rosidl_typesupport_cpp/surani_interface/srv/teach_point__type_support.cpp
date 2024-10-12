// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from surani_interface:srv/TeachPoint.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "surani_interface/srv/detail/teach_point__functions.h"
#include "surani_interface/srv/detail/teach_point__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace surani_interface
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _TeachPoint_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TeachPoint_Request_type_support_ids_t;

static const _TeachPoint_Request_type_support_ids_t _TeachPoint_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _TeachPoint_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TeachPoint_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TeachPoint_Request_type_support_symbol_names_t _TeachPoint_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, surani_interface, srv, TeachPoint_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, surani_interface, srv, TeachPoint_Request)),
  }
};

typedef struct _TeachPoint_Request_type_support_data_t
{
  void * data[2];
} _TeachPoint_Request_type_support_data_t;

static _TeachPoint_Request_type_support_data_t _TeachPoint_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TeachPoint_Request_message_typesupport_map = {
  2,
  "surani_interface",
  &_TeachPoint_Request_message_typesupport_ids.typesupport_identifier[0],
  &_TeachPoint_Request_message_typesupport_symbol_names.symbol_name[0],
  &_TeachPoint_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TeachPoint_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TeachPoint_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &surani_interface__srv__TeachPoint_Request__get_type_hash,
  &surani_interface__srv__TeachPoint_Request__get_type_description,
  &surani_interface__srv__TeachPoint_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace surani_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<surani_interface::srv::TeachPoint_Request>()
{
  return &::surani_interface::srv::rosidl_typesupport_cpp::TeachPoint_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, surani_interface, srv, TeachPoint_Request)() {
  return get_message_type_support_handle<surani_interface::srv::TeachPoint_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "surani_interface/srv/detail/teach_point__functions.h"
// already included above
// #include "surani_interface/srv/detail/teach_point__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace surani_interface
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _TeachPoint_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TeachPoint_Response_type_support_ids_t;

static const _TeachPoint_Response_type_support_ids_t _TeachPoint_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _TeachPoint_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TeachPoint_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TeachPoint_Response_type_support_symbol_names_t _TeachPoint_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, surani_interface, srv, TeachPoint_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, surani_interface, srv, TeachPoint_Response)),
  }
};

typedef struct _TeachPoint_Response_type_support_data_t
{
  void * data[2];
} _TeachPoint_Response_type_support_data_t;

static _TeachPoint_Response_type_support_data_t _TeachPoint_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TeachPoint_Response_message_typesupport_map = {
  2,
  "surani_interface",
  &_TeachPoint_Response_message_typesupport_ids.typesupport_identifier[0],
  &_TeachPoint_Response_message_typesupport_symbol_names.symbol_name[0],
  &_TeachPoint_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TeachPoint_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TeachPoint_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &surani_interface__srv__TeachPoint_Response__get_type_hash,
  &surani_interface__srv__TeachPoint_Response__get_type_description,
  &surani_interface__srv__TeachPoint_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace surani_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<surani_interface::srv::TeachPoint_Response>()
{
  return &::surani_interface::srv::rosidl_typesupport_cpp::TeachPoint_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, surani_interface, srv, TeachPoint_Response)() {
  return get_message_type_support_handle<surani_interface::srv::TeachPoint_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "surani_interface/srv/detail/teach_point__functions.h"
// already included above
// #include "surani_interface/srv/detail/teach_point__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace surani_interface
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _TeachPoint_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TeachPoint_Event_type_support_ids_t;

static const _TeachPoint_Event_type_support_ids_t _TeachPoint_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _TeachPoint_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TeachPoint_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TeachPoint_Event_type_support_symbol_names_t _TeachPoint_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, surani_interface, srv, TeachPoint_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, surani_interface, srv, TeachPoint_Event)),
  }
};

typedef struct _TeachPoint_Event_type_support_data_t
{
  void * data[2];
} _TeachPoint_Event_type_support_data_t;

static _TeachPoint_Event_type_support_data_t _TeachPoint_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TeachPoint_Event_message_typesupport_map = {
  2,
  "surani_interface",
  &_TeachPoint_Event_message_typesupport_ids.typesupport_identifier[0],
  &_TeachPoint_Event_message_typesupport_symbol_names.symbol_name[0],
  &_TeachPoint_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TeachPoint_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TeachPoint_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &surani_interface__srv__TeachPoint_Event__get_type_hash,
  &surani_interface__srv__TeachPoint_Event__get_type_description,
  &surani_interface__srv__TeachPoint_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace surani_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<surani_interface::srv::TeachPoint_Event>()
{
  return &::surani_interface::srv::rosidl_typesupport_cpp::TeachPoint_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, surani_interface, srv, TeachPoint_Event)() {
  return get_message_type_support_handle<surani_interface::srv::TeachPoint_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "surani_interface/srv/detail/teach_point__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace surani_interface
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _TeachPoint_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TeachPoint_type_support_ids_t;

static const _TeachPoint_type_support_ids_t _TeachPoint_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _TeachPoint_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TeachPoint_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TeachPoint_type_support_symbol_names_t _TeachPoint_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, surani_interface, srv, TeachPoint)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, surani_interface, srv, TeachPoint)),
  }
};

typedef struct _TeachPoint_type_support_data_t
{
  void * data[2];
} _TeachPoint_type_support_data_t;

static _TeachPoint_type_support_data_t _TeachPoint_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TeachPoint_service_typesupport_map = {
  2,
  "surani_interface",
  &_TeachPoint_service_typesupport_ids.typesupport_identifier[0],
  &_TeachPoint_service_typesupport_symbol_names.symbol_name[0],
  &_TeachPoint_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t TeachPoint_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TeachPoint_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<surani_interface::srv::TeachPoint_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<surani_interface::srv::TeachPoint_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<surani_interface::srv::TeachPoint_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<surani_interface::srv::TeachPoint>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<surani_interface::srv::TeachPoint>,
  &surani_interface__srv__TeachPoint__get_type_hash,
  &surani_interface__srv__TeachPoint__get_type_description,
  &surani_interface__srv__TeachPoint__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace surani_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<surani_interface::srv::TeachPoint>()
{
  return &::surani_interface::srv::rosidl_typesupport_cpp::TeachPoint_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, surani_interface, srv, TeachPoint)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<surani_interface::srv::TeachPoint>();
}

#ifdef __cplusplus
}
#endif
