# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_surani_interface_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED surani_interface_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(surani_interface_FOUND FALSE)
  elseif(NOT surani_interface_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(surani_interface_FOUND FALSE)
  endif()
  return()
endif()
set(_surani_interface_CONFIG_INCLUDED TRUE)

# output package information
if(NOT surani_interface_FIND_QUIETLY)
  message(STATUS "Found surani_interface: 0.0.0 (${surani_interface_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'surani_interface' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT surani_interface_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(surani_interface_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${surani_interface_DIR}/${_extra}")
endforeach()
