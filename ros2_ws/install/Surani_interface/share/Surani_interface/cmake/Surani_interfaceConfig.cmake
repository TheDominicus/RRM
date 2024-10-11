# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_Surani_interface_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED Surani_interface_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(Surani_interface_FOUND FALSE)
  elseif(NOT Surani_interface_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(Surani_interface_FOUND FALSE)
  endif()
  return()
endif()
set(_Surani_interface_CONFIG_INCLUDED TRUE)

# output package information
if(NOT Surani_interface_FIND_QUIETLY)
  message(STATUS "Found Surani_interface: 0.0.0 (${Surani_interface_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'Surani_interface' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT Surani_interface_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(Surani_interface_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${Surani_interface_DIR}/${_extra}")
endforeach()
