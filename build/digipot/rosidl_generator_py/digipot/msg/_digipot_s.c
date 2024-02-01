// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from digipot:msg/Digipot.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "digipot/msg/detail/digipot__struct.h"
#include "digipot/msg/detail/digipot__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool digipot__msg__digipot__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[29];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("digipot.msg._digipot.Digipot", full_classname_dest, 28) == 0);
  }
  digipot__msg__Digipot * ros_message = _ros_message;
  {  // value
    PyObject * field = PyObject_GetAttrString(_pymsg, "value");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->value = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // wiper
    PyObject * field = PyObject_GetAttrString(_pymsg, "wiper");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->wiper = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // high
    PyObject * field = PyObject_GetAttrString(_pymsg, "high");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->high = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * digipot__msg__digipot__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Digipot */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("digipot.msg._digipot");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Digipot");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  digipot__msg__Digipot * ros_message = (digipot__msg__Digipot *)raw_ros_message;
  {  // value
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->value);
    {
      int rc = PyObject_SetAttrString(_pymessage, "value", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // wiper
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->wiper);
    {
      int rc = PyObject_SetAttrString(_pymessage, "wiper", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // high
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->high);
    {
      int rc = PyObject_SetAttrString(_pymessage, "high", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
