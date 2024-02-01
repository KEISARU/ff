#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "digipot_interfaces::digipot_interfaces__rosidl_generator_py" for configuration ""
set_property(TARGET digipot_interfaces::digipot_interfaces__rosidl_generator_py APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(digipot_interfaces::digipot_interfaces__rosidl_generator_py PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libdigipot_interfaces__rosidl_generator_py.so"
  IMPORTED_SONAME_NOCONFIG "libdigipot_interfaces__rosidl_generator_py.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS digipot_interfaces::digipot_interfaces__rosidl_generator_py )
list(APPEND _IMPORT_CHECK_FILES_FOR_digipot_interfaces::digipot_interfaces__rosidl_generator_py "${_IMPORT_PREFIX}/lib/libdigipot_interfaces__rosidl_generator_py.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
