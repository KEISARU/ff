// generated from rosidl_generator_c/resource/rosidl_generator_c__visibility_control.h.in
// generated code does not contain a copyright notice

#ifndef DIGIPOT__MSG__ROSIDL_GENERATOR_C__VISIBILITY_CONTROL_H_
#define DIGIPOT__MSG__ROSIDL_GENERATOR_C__VISIBILITY_CONTROL_H_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_GENERATOR_C_EXPORT_digipot __attribute__ ((dllexport))
    #define ROSIDL_GENERATOR_C_IMPORT_digipot __attribute__ ((dllimport))
  #else
    #define ROSIDL_GENERATOR_C_EXPORT_digipot __declspec(dllexport)
    #define ROSIDL_GENERATOR_C_IMPORT_digipot __declspec(dllimport)
  #endif
  #ifdef ROSIDL_GENERATOR_C_BUILDING_DLL_digipot
    #define ROSIDL_GENERATOR_C_PUBLIC_digipot ROSIDL_GENERATOR_C_EXPORT_digipot
  #else
    #define ROSIDL_GENERATOR_C_PUBLIC_digipot ROSIDL_GENERATOR_C_IMPORT_digipot
  #endif
#else
  #define ROSIDL_GENERATOR_C_EXPORT_digipot __attribute__ ((visibility("default")))
  #define ROSIDL_GENERATOR_C_IMPORT_digipot
  #if __GNUC__ >= 4
    #define ROSIDL_GENERATOR_C_PUBLIC_digipot __attribute__ ((visibility("default")))
  #else
    #define ROSIDL_GENERATOR_C_PUBLIC_digipot
  #endif
#endif

#ifdef __cplusplus
}
#endif

#endif  // DIGIPOT__MSG__ROSIDL_GENERATOR_C__VISIBILITY_CONTROL_H_
