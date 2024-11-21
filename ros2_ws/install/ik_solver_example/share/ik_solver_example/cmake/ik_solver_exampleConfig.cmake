# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_ik_solver_example_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED ik_solver_example_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(ik_solver_example_FOUND FALSE)
  elseif(NOT ik_solver_example_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(ik_solver_example_FOUND FALSE)
  endif()
  return()
endif()
set(_ik_solver_example_CONFIG_INCLUDED TRUE)

# output package information
if(NOT ik_solver_example_FIND_QUIETLY)
  message(STATUS "Found ik_solver_example: 0.0.0 (${ik_solver_example_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'ik_solver_example' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ik_solver_example_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(ik_solver_example_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${ik_solver_example_DIR}/${_extra}")
endforeach()
