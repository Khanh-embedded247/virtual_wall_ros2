# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_plu_virtual_wall_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED plu_virtual_wall_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(plu_virtual_wall_FOUND FALSE)
  elseif(NOT plu_virtual_wall_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(plu_virtual_wall_FOUND FALSE)
  endif()
  return()
endif()
set(_plu_virtual_wall_CONFIG_INCLUDED TRUE)

# output package information
if(NOT plu_virtual_wall_FIND_QUIETLY)
  message(STATUS "Found plu_virtual_wall: 0.0.1 (${plu_virtual_wall_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'plu_virtual_wall' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${plu_virtual_wall_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(plu_virtual_wall_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${plu_virtual_wall_DIR}/${_extra}")
endforeach()
