# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_digipot_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED digipot_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(digipot_FOUND FALSE)
  elseif(NOT digipot_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(digipot_FOUND FALSE)
  endif()
  return()
endif()
set(_digipot_CONFIG_INCLUDED TRUE)

# output package information
if(NOT digipot_FIND_QUIETLY)
  message(STATUS "Found digipot: 0.0.0 (${digipot_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'digipot' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${digipot_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(digipot_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${digipot_DIR}/${_extra}")
endforeach()
