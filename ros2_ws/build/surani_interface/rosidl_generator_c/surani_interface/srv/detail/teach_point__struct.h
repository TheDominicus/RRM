// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from surani_interface:srv/TeachPoint.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "surani_interface/srv/teach_point.h"


#ifndef SURANI_INTERFACE__SRV__DETAIL__TEACH_POINT__STRUCT_H_
#define SURANI_INTERFACE__SRV__DETAIL__TEACH_POINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/TeachPoint in the package surani_interface.
typedef struct surani_interface__srv__TeachPoint_Request
{
  double velocity;
} surani_interface__srv__TeachPoint_Request;

// Struct for a sequence of surani_interface__srv__TeachPoint_Request.
typedef struct surani_interface__srv__TeachPoint_Request__Sequence
{
  surani_interface__srv__TeachPoint_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} surani_interface__srv__TeachPoint_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/TeachPoint in the package surani_interface.
typedef struct surani_interface__srv__TeachPoint_Response
{
  bool result;
  rosidl_runtime_c__String message;
} surani_interface__srv__TeachPoint_Response;

// Struct for a sequence of surani_interface__srv__TeachPoint_Response.
typedef struct surani_interface__srv__TeachPoint_Response__Sequence
{
  surani_interface__srv__TeachPoint_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} surani_interface__srv__TeachPoint_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  surani_interface__srv__TeachPoint_Event__request__MAX_SIZE = 1
};
// response
enum
{
  surani_interface__srv__TeachPoint_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/TeachPoint in the package surani_interface.
typedef struct surani_interface__srv__TeachPoint_Event
{
  service_msgs__msg__ServiceEventInfo info;
  surani_interface__srv__TeachPoint_Request__Sequence request;
  surani_interface__srv__TeachPoint_Response__Sequence response;
} surani_interface__srv__TeachPoint_Event;

// Struct for a sequence of surani_interface__srv__TeachPoint_Event.
typedef struct surani_interface__srv__TeachPoint_Event__Sequence
{
  surani_interface__srv__TeachPoint_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} surani_interface__srv__TeachPoint_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SURANI_INTERFACE__SRV__DETAIL__TEACH_POINT__STRUCT_H_
