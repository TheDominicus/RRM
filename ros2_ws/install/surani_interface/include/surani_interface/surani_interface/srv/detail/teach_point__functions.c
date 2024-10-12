// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from surani_interface:srv/TeachPoint.idl
// generated code does not contain a copyright notice
#include "surani_interface/srv/detail/teach_point__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
surani_interface__srv__TeachPoint_Request__init(surani_interface__srv__TeachPoint_Request * msg)
{
  if (!msg) {
    return false;
  }
  // velocity
  return true;
}

void
surani_interface__srv__TeachPoint_Request__fini(surani_interface__srv__TeachPoint_Request * msg)
{
  if (!msg) {
    return;
  }
  // velocity
}

bool
surani_interface__srv__TeachPoint_Request__are_equal(const surani_interface__srv__TeachPoint_Request * lhs, const surani_interface__srv__TeachPoint_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // velocity
  if (lhs->velocity != rhs->velocity) {
    return false;
  }
  return true;
}

bool
surani_interface__srv__TeachPoint_Request__copy(
  const surani_interface__srv__TeachPoint_Request * input,
  surani_interface__srv__TeachPoint_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // velocity
  output->velocity = input->velocity;
  return true;
}

surani_interface__srv__TeachPoint_Request *
surani_interface__srv__TeachPoint_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  surani_interface__srv__TeachPoint_Request * msg = (surani_interface__srv__TeachPoint_Request *)allocator.allocate(sizeof(surani_interface__srv__TeachPoint_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(surani_interface__srv__TeachPoint_Request));
  bool success = surani_interface__srv__TeachPoint_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
surani_interface__srv__TeachPoint_Request__destroy(surani_interface__srv__TeachPoint_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    surani_interface__srv__TeachPoint_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
surani_interface__srv__TeachPoint_Request__Sequence__init(surani_interface__srv__TeachPoint_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  surani_interface__srv__TeachPoint_Request * data = NULL;

  if (size) {
    data = (surani_interface__srv__TeachPoint_Request *)allocator.zero_allocate(size, sizeof(surani_interface__srv__TeachPoint_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = surani_interface__srv__TeachPoint_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        surani_interface__srv__TeachPoint_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
surani_interface__srv__TeachPoint_Request__Sequence__fini(surani_interface__srv__TeachPoint_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      surani_interface__srv__TeachPoint_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

surani_interface__srv__TeachPoint_Request__Sequence *
surani_interface__srv__TeachPoint_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  surani_interface__srv__TeachPoint_Request__Sequence * array = (surani_interface__srv__TeachPoint_Request__Sequence *)allocator.allocate(sizeof(surani_interface__srv__TeachPoint_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = surani_interface__srv__TeachPoint_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
surani_interface__srv__TeachPoint_Request__Sequence__destroy(surani_interface__srv__TeachPoint_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    surani_interface__srv__TeachPoint_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
surani_interface__srv__TeachPoint_Request__Sequence__are_equal(const surani_interface__srv__TeachPoint_Request__Sequence * lhs, const surani_interface__srv__TeachPoint_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!surani_interface__srv__TeachPoint_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
surani_interface__srv__TeachPoint_Request__Sequence__copy(
  const surani_interface__srv__TeachPoint_Request__Sequence * input,
  surani_interface__srv__TeachPoint_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(surani_interface__srv__TeachPoint_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    surani_interface__srv__TeachPoint_Request * data =
      (surani_interface__srv__TeachPoint_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!surani_interface__srv__TeachPoint_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          surani_interface__srv__TeachPoint_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!surani_interface__srv__TeachPoint_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
surani_interface__srv__TeachPoint_Response__init(surani_interface__srv__TeachPoint_Response * msg)
{
  if (!msg) {
    return false;
  }
  // result
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    surani_interface__srv__TeachPoint_Response__fini(msg);
    return false;
  }
  return true;
}

void
surani_interface__srv__TeachPoint_Response__fini(surani_interface__srv__TeachPoint_Response * msg)
{
  if (!msg) {
    return;
  }
  // result
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
surani_interface__srv__TeachPoint_Response__are_equal(const surani_interface__srv__TeachPoint_Response * lhs, const surani_interface__srv__TeachPoint_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // result
  if (lhs->result != rhs->result) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
surani_interface__srv__TeachPoint_Response__copy(
  const surani_interface__srv__TeachPoint_Response * input,
  surani_interface__srv__TeachPoint_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // result
  output->result = input->result;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

surani_interface__srv__TeachPoint_Response *
surani_interface__srv__TeachPoint_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  surani_interface__srv__TeachPoint_Response * msg = (surani_interface__srv__TeachPoint_Response *)allocator.allocate(sizeof(surani_interface__srv__TeachPoint_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(surani_interface__srv__TeachPoint_Response));
  bool success = surani_interface__srv__TeachPoint_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
surani_interface__srv__TeachPoint_Response__destroy(surani_interface__srv__TeachPoint_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    surani_interface__srv__TeachPoint_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
surani_interface__srv__TeachPoint_Response__Sequence__init(surani_interface__srv__TeachPoint_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  surani_interface__srv__TeachPoint_Response * data = NULL;

  if (size) {
    data = (surani_interface__srv__TeachPoint_Response *)allocator.zero_allocate(size, sizeof(surani_interface__srv__TeachPoint_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = surani_interface__srv__TeachPoint_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        surani_interface__srv__TeachPoint_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
surani_interface__srv__TeachPoint_Response__Sequence__fini(surani_interface__srv__TeachPoint_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      surani_interface__srv__TeachPoint_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

surani_interface__srv__TeachPoint_Response__Sequence *
surani_interface__srv__TeachPoint_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  surani_interface__srv__TeachPoint_Response__Sequence * array = (surani_interface__srv__TeachPoint_Response__Sequence *)allocator.allocate(sizeof(surani_interface__srv__TeachPoint_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = surani_interface__srv__TeachPoint_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
surani_interface__srv__TeachPoint_Response__Sequence__destroy(surani_interface__srv__TeachPoint_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    surani_interface__srv__TeachPoint_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
surani_interface__srv__TeachPoint_Response__Sequence__are_equal(const surani_interface__srv__TeachPoint_Response__Sequence * lhs, const surani_interface__srv__TeachPoint_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!surani_interface__srv__TeachPoint_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
surani_interface__srv__TeachPoint_Response__Sequence__copy(
  const surani_interface__srv__TeachPoint_Response__Sequence * input,
  surani_interface__srv__TeachPoint_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(surani_interface__srv__TeachPoint_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    surani_interface__srv__TeachPoint_Response * data =
      (surani_interface__srv__TeachPoint_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!surani_interface__srv__TeachPoint_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          surani_interface__srv__TeachPoint_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!surani_interface__srv__TeachPoint_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "surani_interface/srv/detail/teach_point__functions.h"

bool
surani_interface__srv__TeachPoint_Event__init(surani_interface__srv__TeachPoint_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    surani_interface__srv__TeachPoint_Event__fini(msg);
    return false;
  }
  // request
  if (!surani_interface__srv__TeachPoint_Request__Sequence__init(&msg->request, 0)) {
    surani_interface__srv__TeachPoint_Event__fini(msg);
    return false;
  }
  // response
  if (!surani_interface__srv__TeachPoint_Response__Sequence__init(&msg->response, 0)) {
    surani_interface__srv__TeachPoint_Event__fini(msg);
    return false;
  }
  return true;
}

void
surani_interface__srv__TeachPoint_Event__fini(surani_interface__srv__TeachPoint_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  surani_interface__srv__TeachPoint_Request__Sequence__fini(&msg->request);
  // response
  surani_interface__srv__TeachPoint_Response__Sequence__fini(&msg->response);
}

bool
surani_interface__srv__TeachPoint_Event__are_equal(const surani_interface__srv__TeachPoint_Event * lhs, const surani_interface__srv__TeachPoint_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!surani_interface__srv__TeachPoint_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!surani_interface__srv__TeachPoint_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
surani_interface__srv__TeachPoint_Event__copy(
  const surani_interface__srv__TeachPoint_Event * input,
  surani_interface__srv__TeachPoint_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!surani_interface__srv__TeachPoint_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!surani_interface__srv__TeachPoint_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

surani_interface__srv__TeachPoint_Event *
surani_interface__srv__TeachPoint_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  surani_interface__srv__TeachPoint_Event * msg = (surani_interface__srv__TeachPoint_Event *)allocator.allocate(sizeof(surani_interface__srv__TeachPoint_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(surani_interface__srv__TeachPoint_Event));
  bool success = surani_interface__srv__TeachPoint_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
surani_interface__srv__TeachPoint_Event__destroy(surani_interface__srv__TeachPoint_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    surani_interface__srv__TeachPoint_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
surani_interface__srv__TeachPoint_Event__Sequence__init(surani_interface__srv__TeachPoint_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  surani_interface__srv__TeachPoint_Event * data = NULL;

  if (size) {
    data = (surani_interface__srv__TeachPoint_Event *)allocator.zero_allocate(size, sizeof(surani_interface__srv__TeachPoint_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = surani_interface__srv__TeachPoint_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        surani_interface__srv__TeachPoint_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
surani_interface__srv__TeachPoint_Event__Sequence__fini(surani_interface__srv__TeachPoint_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      surani_interface__srv__TeachPoint_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

surani_interface__srv__TeachPoint_Event__Sequence *
surani_interface__srv__TeachPoint_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  surani_interface__srv__TeachPoint_Event__Sequence * array = (surani_interface__srv__TeachPoint_Event__Sequence *)allocator.allocate(sizeof(surani_interface__srv__TeachPoint_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = surani_interface__srv__TeachPoint_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
surani_interface__srv__TeachPoint_Event__Sequence__destroy(surani_interface__srv__TeachPoint_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    surani_interface__srv__TeachPoint_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
surani_interface__srv__TeachPoint_Event__Sequence__are_equal(const surani_interface__srv__TeachPoint_Event__Sequence * lhs, const surani_interface__srv__TeachPoint_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!surani_interface__srv__TeachPoint_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
surani_interface__srv__TeachPoint_Event__Sequence__copy(
  const surani_interface__srv__TeachPoint_Event__Sequence * input,
  surani_interface__srv__TeachPoint_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(surani_interface__srv__TeachPoint_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    surani_interface__srv__TeachPoint_Event * data =
      (surani_interface__srv__TeachPoint_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!surani_interface__srv__TeachPoint_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          surani_interface__srv__TeachPoint_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!surani_interface__srv__TeachPoint_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
