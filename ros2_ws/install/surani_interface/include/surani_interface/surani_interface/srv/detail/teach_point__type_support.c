// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from surani_interface:srv/TeachPoint.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "surani_interface/srv/detail/teach_point__rosidl_typesupport_introspection_c.h"
#include "surani_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "surani_interface/srv/detail/teach_point__functions.h"
#include "surani_interface/srv/detail/teach_point__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void surani_interface__srv__TeachPoint_Request__rosidl_typesupport_introspection_c__TeachPoint_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  surani_interface__srv__TeachPoint_Request__init(message_memory);
}

void surani_interface__srv__TeachPoint_Request__rosidl_typesupport_introspection_c__TeachPoint_Request_fini_function(void * message_memory)
{
  surani_interface__srv__TeachPoint_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember surani_interface__srv__TeachPoint_Request__rosidl_typesupport_introspection_c__TeachPoint_Request_message_member_array[1] = {
  {
    "velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(surani_interface__srv__TeachPoint_Request, velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers surani_interface__srv__TeachPoint_Request__rosidl_typesupport_introspection_c__TeachPoint_Request_message_members = {
  "surani_interface__srv",  // message namespace
  "TeachPoint_Request",  // message name
  1,  // number of fields
  sizeof(surani_interface__srv__TeachPoint_Request),
  false,  // has_any_key_member_
  surani_interface__srv__TeachPoint_Request__rosidl_typesupport_introspection_c__TeachPoint_Request_message_member_array,  // message members
  surani_interface__srv__TeachPoint_Request__rosidl_typesupport_introspection_c__TeachPoint_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  surani_interface__srv__TeachPoint_Request__rosidl_typesupport_introspection_c__TeachPoint_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t surani_interface__srv__TeachPoint_Request__rosidl_typesupport_introspection_c__TeachPoint_Request_message_type_support_handle = {
  0,
  &surani_interface__srv__TeachPoint_Request__rosidl_typesupport_introspection_c__TeachPoint_Request_message_members,
  get_message_typesupport_handle_function,
  &surani_interface__srv__TeachPoint_Request__get_type_hash,
  &surani_interface__srv__TeachPoint_Request__get_type_description,
  &surani_interface__srv__TeachPoint_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_surani_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, surani_interface, srv, TeachPoint_Request)() {
  if (!surani_interface__srv__TeachPoint_Request__rosidl_typesupport_introspection_c__TeachPoint_Request_message_type_support_handle.typesupport_identifier) {
    surani_interface__srv__TeachPoint_Request__rosidl_typesupport_introspection_c__TeachPoint_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &surani_interface__srv__TeachPoint_Request__rosidl_typesupport_introspection_c__TeachPoint_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "surani_interface/srv/detail/teach_point__rosidl_typesupport_introspection_c.h"
// already included above
// #include "surani_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "surani_interface/srv/detail/teach_point__functions.h"
// already included above
// #include "surani_interface/srv/detail/teach_point__struct.h"


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void surani_interface__srv__TeachPoint_Response__rosidl_typesupport_introspection_c__TeachPoint_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  surani_interface__srv__TeachPoint_Response__init(message_memory);
}

void surani_interface__srv__TeachPoint_Response__rosidl_typesupport_introspection_c__TeachPoint_Response_fini_function(void * message_memory)
{
  surani_interface__srv__TeachPoint_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember surani_interface__srv__TeachPoint_Response__rosidl_typesupport_introspection_c__TeachPoint_Response_message_member_array[3] = {
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(surani_interface__srv__TeachPoint_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(surani_interface__srv__TeachPoint_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(surani_interface__srv__TeachPoint_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers surani_interface__srv__TeachPoint_Response__rosidl_typesupport_introspection_c__TeachPoint_Response_message_members = {
  "surani_interface__srv",  // message namespace
  "TeachPoint_Response",  // message name
  3,  // number of fields
  sizeof(surani_interface__srv__TeachPoint_Response),
  false,  // has_any_key_member_
  surani_interface__srv__TeachPoint_Response__rosidl_typesupport_introspection_c__TeachPoint_Response_message_member_array,  // message members
  surani_interface__srv__TeachPoint_Response__rosidl_typesupport_introspection_c__TeachPoint_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  surani_interface__srv__TeachPoint_Response__rosidl_typesupport_introspection_c__TeachPoint_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t surani_interface__srv__TeachPoint_Response__rosidl_typesupport_introspection_c__TeachPoint_Response_message_type_support_handle = {
  0,
  &surani_interface__srv__TeachPoint_Response__rosidl_typesupport_introspection_c__TeachPoint_Response_message_members,
  get_message_typesupport_handle_function,
  &surani_interface__srv__TeachPoint_Response__get_type_hash,
  &surani_interface__srv__TeachPoint_Response__get_type_description,
  &surani_interface__srv__TeachPoint_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_surani_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, surani_interface, srv, TeachPoint_Response)() {
  if (!surani_interface__srv__TeachPoint_Response__rosidl_typesupport_introspection_c__TeachPoint_Response_message_type_support_handle.typesupport_identifier) {
    surani_interface__srv__TeachPoint_Response__rosidl_typesupport_introspection_c__TeachPoint_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &surani_interface__srv__TeachPoint_Response__rosidl_typesupport_introspection_c__TeachPoint_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "surani_interface/srv/detail/teach_point__rosidl_typesupport_introspection_c.h"
// already included above
// #include "surani_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "surani_interface/srv/detail/teach_point__functions.h"
// already included above
// #include "surani_interface/srv/detail/teach_point__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "surani_interface/srv/teach_point.h"
// Member `request`
// Member `response`
// already included above
// #include "surani_interface/srv/detail/teach_point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__TeachPoint_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  surani_interface__srv__TeachPoint_Event__init(message_memory);
}

void surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__TeachPoint_Event_fini_function(void * message_memory)
{
  surani_interface__srv__TeachPoint_Event__fini(message_memory);
}

size_t surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__size_function__TeachPoint_Event__request(
  const void * untyped_member)
{
  const surani_interface__srv__TeachPoint_Request__Sequence * member =
    (const surani_interface__srv__TeachPoint_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__get_const_function__TeachPoint_Event__request(
  const void * untyped_member, size_t index)
{
  const surani_interface__srv__TeachPoint_Request__Sequence * member =
    (const surani_interface__srv__TeachPoint_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__get_function__TeachPoint_Event__request(
  void * untyped_member, size_t index)
{
  surani_interface__srv__TeachPoint_Request__Sequence * member =
    (surani_interface__srv__TeachPoint_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__fetch_function__TeachPoint_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const surani_interface__srv__TeachPoint_Request * item =
    ((const surani_interface__srv__TeachPoint_Request *)
    surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__get_const_function__TeachPoint_Event__request(untyped_member, index));
  surani_interface__srv__TeachPoint_Request * value =
    (surani_interface__srv__TeachPoint_Request *)(untyped_value);
  *value = *item;
}

void surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__assign_function__TeachPoint_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  surani_interface__srv__TeachPoint_Request * item =
    ((surani_interface__srv__TeachPoint_Request *)
    surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__get_function__TeachPoint_Event__request(untyped_member, index));
  const surani_interface__srv__TeachPoint_Request * value =
    (const surani_interface__srv__TeachPoint_Request *)(untyped_value);
  *item = *value;
}

bool surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__resize_function__TeachPoint_Event__request(
  void * untyped_member, size_t size)
{
  surani_interface__srv__TeachPoint_Request__Sequence * member =
    (surani_interface__srv__TeachPoint_Request__Sequence *)(untyped_member);
  surani_interface__srv__TeachPoint_Request__Sequence__fini(member);
  return surani_interface__srv__TeachPoint_Request__Sequence__init(member, size);
}

size_t surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__size_function__TeachPoint_Event__response(
  const void * untyped_member)
{
  const surani_interface__srv__TeachPoint_Response__Sequence * member =
    (const surani_interface__srv__TeachPoint_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__get_const_function__TeachPoint_Event__response(
  const void * untyped_member, size_t index)
{
  const surani_interface__srv__TeachPoint_Response__Sequence * member =
    (const surani_interface__srv__TeachPoint_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__get_function__TeachPoint_Event__response(
  void * untyped_member, size_t index)
{
  surani_interface__srv__TeachPoint_Response__Sequence * member =
    (surani_interface__srv__TeachPoint_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__fetch_function__TeachPoint_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const surani_interface__srv__TeachPoint_Response * item =
    ((const surani_interface__srv__TeachPoint_Response *)
    surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__get_const_function__TeachPoint_Event__response(untyped_member, index));
  surani_interface__srv__TeachPoint_Response * value =
    (surani_interface__srv__TeachPoint_Response *)(untyped_value);
  *value = *item;
}

void surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__assign_function__TeachPoint_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  surani_interface__srv__TeachPoint_Response * item =
    ((surani_interface__srv__TeachPoint_Response *)
    surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__get_function__TeachPoint_Event__response(untyped_member, index));
  const surani_interface__srv__TeachPoint_Response * value =
    (const surani_interface__srv__TeachPoint_Response *)(untyped_value);
  *item = *value;
}

bool surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__resize_function__TeachPoint_Event__response(
  void * untyped_member, size_t size)
{
  surani_interface__srv__TeachPoint_Response__Sequence * member =
    (surani_interface__srv__TeachPoint_Response__Sequence *)(untyped_member);
  surani_interface__srv__TeachPoint_Response__Sequence__fini(member);
  return surani_interface__srv__TeachPoint_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__TeachPoint_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(surani_interface__srv__TeachPoint_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(surani_interface__srv__TeachPoint_Event, request),  // bytes offset in struct
    NULL,  // default value
    surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__size_function__TeachPoint_Event__request,  // size() function pointer
    surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__get_const_function__TeachPoint_Event__request,  // get_const(index) function pointer
    surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__get_function__TeachPoint_Event__request,  // get(index) function pointer
    surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__fetch_function__TeachPoint_Event__request,  // fetch(index, &value) function pointer
    surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__assign_function__TeachPoint_Event__request,  // assign(index, value) function pointer
    surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__resize_function__TeachPoint_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(surani_interface__srv__TeachPoint_Event, response),  // bytes offset in struct
    NULL,  // default value
    surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__size_function__TeachPoint_Event__response,  // size() function pointer
    surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__get_const_function__TeachPoint_Event__response,  // get_const(index) function pointer
    surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__get_function__TeachPoint_Event__response,  // get(index) function pointer
    surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__fetch_function__TeachPoint_Event__response,  // fetch(index, &value) function pointer
    surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__assign_function__TeachPoint_Event__response,  // assign(index, value) function pointer
    surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__resize_function__TeachPoint_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__TeachPoint_Event_message_members = {
  "surani_interface__srv",  // message namespace
  "TeachPoint_Event",  // message name
  3,  // number of fields
  sizeof(surani_interface__srv__TeachPoint_Event),
  false,  // has_any_key_member_
  surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__TeachPoint_Event_message_member_array,  // message members
  surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__TeachPoint_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__TeachPoint_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__TeachPoint_Event_message_type_support_handle = {
  0,
  &surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__TeachPoint_Event_message_members,
  get_message_typesupport_handle_function,
  &surani_interface__srv__TeachPoint_Event__get_type_hash,
  &surani_interface__srv__TeachPoint_Event__get_type_description,
  &surani_interface__srv__TeachPoint_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_surani_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, surani_interface, srv, TeachPoint_Event)() {
  surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__TeachPoint_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__TeachPoint_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, surani_interface, srv, TeachPoint_Request)();
  surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__TeachPoint_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, surani_interface, srv, TeachPoint_Response)();
  if (!surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__TeachPoint_Event_message_type_support_handle.typesupport_identifier) {
    surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__TeachPoint_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__TeachPoint_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "surani_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "surani_interface/srv/detail/teach_point__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers surani_interface__srv__detail__teach_point__rosidl_typesupport_introspection_c__TeachPoint_service_members = {
  "surani_interface__srv",  // service namespace
  "TeachPoint",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // surani_interface__srv__detail__teach_point__rosidl_typesupport_introspection_c__TeachPoint_Request_message_type_support_handle,
  NULL,  // response message
  // surani_interface__srv__detail__teach_point__rosidl_typesupport_introspection_c__TeachPoint_Response_message_type_support_handle
  NULL  // event_message
  // surani_interface__srv__detail__teach_point__rosidl_typesupport_introspection_c__TeachPoint_Response_message_type_support_handle
};


static rosidl_service_type_support_t surani_interface__srv__detail__teach_point__rosidl_typesupport_introspection_c__TeachPoint_service_type_support_handle = {
  0,
  &surani_interface__srv__detail__teach_point__rosidl_typesupport_introspection_c__TeachPoint_service_members,
  get_service_typesupport_handle_function,
  &surani_interface__srv__TeachPoint_Request__rosidl_typesupport_introspection_c__TeachPoint_Request_message_type_support_handle,
  &surani_interface__srv__TeachPoint_Response__rosidl_typesupport_introspection_c__TeachPoint_Response_message_type_support_handle,
  &surani_interface__srv__TeachPoint_Event__rosidl_typesupport_introspection_c__TeachPoint_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    surani_interface,
    srv,
    TeachPoint
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    surani_interface,
    srv,
    TeachPoint
  ),
  &surani_interface__srv__TeachPoint__get_type_hash,
  &surani_interface__srv__TeachPoint__get_type_description,
  &surani_interface__srv__TeachPoint__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, surani_interface, srv, TeachPoint_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, surani_interface, srv, TeachPoint_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, surani_interface, srv, TeachPoint_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_surani_interface
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, surani_interface, srv, TeachPoint)(void) {
  if (!surani_interface__srv__detail__teach_point__rosidl_typesupport_introspection_c__TeachPoint_service_type_support_handle.typesupport_identifier) {
    surani_interface__srv__detail__teach_point__rosidl_typesupport_introspection_c__TeachPoint_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)surani_interface__srv__detail__teach_point__rosidl_typesupport_introspection_c__TeachPoint_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, surani_interface, srv, TeachPoint_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, surani_interface, srv, TeachPoint_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, surani_interface, srv, TeachPoint_Event)()->data;
  }

  return &surani_interface__srv__detail__teach_point__rosidl_typesupport_introspection_c__TeachPoint_service_type_support_handle;
}
