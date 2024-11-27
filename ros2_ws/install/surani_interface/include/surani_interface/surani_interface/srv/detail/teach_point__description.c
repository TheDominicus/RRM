// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from surani_interface:srv/TeachPoint.idl
// generated code does not contain a copyright notice

#include "surani_interface/srv/detail/teach_point__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_surani_interface
const rosidl_type_hash_t *
surani_interface__srv__TeachPoint__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd4, 0xfb, 0x40, 0x64, 0x78, 0x12, 0x47, 0x25,
      0x3e, 0xb6, 0xf3, 0x3b, 0x8e, 0x25, 0x33, 0x25,
      0xeb, 0x59, 0x54, 0x8b, 0xbd, 0xb8, 0x88, 0x32,
      0xaf, 0xac, 0x49, 0xb2, 0x11, 0xa6, 0x71, 0x14,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_surani_interface
const rosidl_type_hash_t *
surani_interface__srv__TeachPoint_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xde, 0x67, 0x96, 0x2f, 0xf3, 0xf4, 0x84, 0x8f,
      0xc1, 0x2e, 0xfc, 0xac, 0x06, 0x34, 0xec, 0xe3,
      0x36, 0x2e, 0x62, 0xe4, 0xb1, 0x38, 0x02, 0x42,
      0x02, 0x3a, 0xa8, 0xa9, 0x5e, 0xdf, 0xc0, 0x67,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_surani_interface
const rosidl_type_hash_t *
surani_interface__srv__TeachPoint_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xaf, 0x72, 0x29, 0x9b, 0xb0, 0x87, 0x99, 0x8c,
      0x70, 0x8f, 0x99, 0xdb, 0xab, 0xdd, 0x8a, 0x40,
      0xa3, 0xe5, 0xc5, 0xfa, 0x32, 0x82, 0x3f, 0xe0,
      0xc2, 0xc8, 0x5e, 0x19, 0xce, 0x7a, 0xaf, 0x5a,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_surani_interface
const rosidl_type_hash_t *
surani_interface__srv__TeachPoint_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x06, 0xd6, 0x8e, 0x22, 0x73, 0x33, 0x73, 0xce,
      0xb2, 0xfa, 0xe7, 0x68, 0x64, 0x08, 0x49, 0xd7,
      0x9a, 0xbc, 0x60, 0x9e, 0xbf, 0x4a, 0x08, 0xd6,
      0xc4, 0x83, 0x81, 0xa3, 0x92, 0x50, 0xc3, 0x8d,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char surani_interface__srv__TeachPoint__TYPE_NAME[] = "surani_interface/srv/TeachPoint";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";
static char surani_interface__srv__TeachPoint_Event__TYPE_NAME[] = "surani_interface/srv/TeachPoint_Event";
static char surani_interface__srv__TeachPoint_Request__TYPE_NAME[] = "surani_interface/srv/TeachPoint_Request";
static char surani_interface__srv__TeachPoint_Response__TYPE_NAME[] = "surani_interface/srv/TeachPoint_Response";

// Define type names, field names, and default values
static char surani_interface__srv__TeachPoint__FIELD_NAME__request_message[] = "request_message";
static char surani_interface__srv__TeachPoint__FIELD_NAME__response_message[] = "response_message";
static char surani_interface__srv__TeachPoint__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field surani_interface__srv__TeachPoint__FIELDS[] = {
  {
    {surani_interface__srv__TeachPoint__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {surani_interface__srv__TeachPoint_Request__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
  {
    {surani_interface__srv__TeachPoint__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {surani_interface__srv__TeachPoint_Response__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
  {
    {surani_interface__srv__TeachPoint__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {surani_interface__srv__TeachPoint_Event__TYPE_NAME, 37, 37},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription surani_interface__srv__TeachPoint__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {surani_interface__srv__TeachPoint_Event__TYPE_NAME, 37, 37},
    {NULL, 0, 0},
  },
  {
    {surani_interface__srv__TeachPoint_Request__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {surani_interface__srv__TeachPoint_Response__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
surani_interface__srv__TeachPoint__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {surani_interface__srv__TeachPoint__TYPE_NAME, 31, 31},
      {surani_interface__srv__TeachPoint__FIELDS, 3, 3},
    },
    {surani_interface__srv__TeachPoint__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = surani_interface__srv__TeachPoint_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = surani_interface__srv__TeachPoint_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = surani_interface__srv__TeachPoint_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char surani_interface__srv__TeachPoint_Request__FIELD_NAME__velocity[] = "velocity";

static rosidl_runtime_c__type_description__Field surani_interface__srv__TeachPoint_Request__FIELDS[] = {
  {
    {surani_interface__srv__TeachPoint_Request__FIELD_NAME__velocity, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
surani_interface__srv__TeachPoint_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {surani_interface__srv__TeachPoint_Request__TYPE_NAME, 39, 39},
      {surani_interface__srv__TeachPoint_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char surani_interface__srv__TeachPoint_Response__FIELD_NAME__result[] = "result";
static char surani_interface__srv__TeachPoint_Response__FIELD_NAME__message[] = "message";
static char surani_interface__srv__TeachPoint_Response__FIELD_NAME__success[] = "success";

static rosidl_runtime_c__type_description__Field surani_interface__srv__TeachPoint_Response__FIELDS[] = {
  {
    {surani_interface__srv__TeachPoint_Response__FIELD_NAME__result, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {surani_interface__srv__TeachPoint_Response__FIELD_NAME__message, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {surani_interface__srv__TeachPoint_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
surani_interface__srv__TeachPoint_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {surani_interface__srv__TeachPoint_Response__TYPE_NAME, 40, 40},
      {surani_interface__srv__TeachPoint_Response__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char surani_interface__srv__TeachPoint_Event__FIELD_NAME__info[] = "info";
static char surani_interface__srv__TeachPoint_Event__FIELD_NAME__request[] = "request";
static char surani_interface__srv__TeachPoint_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field surani_interface__srv__TeachPoint_Event__FIELDS[] = {
  {
    {surani_interface__srv__TeachPoint_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {surani_interface__srv__TeachPoint_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {surani_interface__srv__TeachPoint_Request__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
  {
    {surani_interface__srv__TeachPoint_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {surani_interface__srv__TeachPoint_Response__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription surani_interface__srv__TeachPoint_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {surani_interface__srv__TeachPoint_Request__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {surani_interface__srv__TeachPoint_Response__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
surani_interface__srv__TeachPoint_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {surani_interface__srv__TeachPoint_Event__TYPE_NAME, 37, 37},
      {surani_interface__srv__TeachPoint_Event__FIELDS, 3, 3},
    },
    {surani_interface__srv__TeachPoint_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = surani_interface__srv__TeachPoint_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = surani_interface__srv__TeachPoint_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64 velocity\n"
  "---\n"
  "bool result\n"
  "string message\n"
  "bool success";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
surani_interface__srv__TeachPoint__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {surani_interface__srv__TeachPoint__TYPE_NAME, 31, 31},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 60, 60},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
surani_interface__srv__TeachPoint_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {surani_interface__srv__TeachPoint_Request__TYPE_NAME, 39, 39},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
surani_interface__srv__TeachPoint_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {surani_interface__srv__TeachPoint_Response__TYPE_NAME, 40, 40},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
surani_interface__srv__TeachPoint_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {surani_interface__srv__TeachPoint_Event__TYPE_NAME, 37, 37},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
surani_interface__srv__TeachPoint__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *surani_interface__srv__TeachPoint__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *surani_interface__srv__TeachPoint_Event__get_individual_type_description_source(NULL);
    sources[4] = *surani_interface__srv__TeachPoint_Request__get_individual_type_description_source(NULL);
    sources[5] = *surani_interface__srv__TeachPoint_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
surani_interface__srv__TeachPoint_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *surani_interface__srv__TeachPoint_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
surani_interface__srv__TeachPoint_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *surani_interface__srv__TeachPoint_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
surani_interface__srv__TeachPoint_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *surani_interface__srv__TeachPoint_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *surani_interface__srv__TeachPoint_Request__get_individual_type_description_source(NULL);
    sources[4] = *surani_interface__srv__TeachPoint_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
