#include <Python.h>
#include "layers/data.h"

PyObject *
data_new(PyTypeObject *type, PyObject *args, PyObject *kwds) {
  data *self = NULL;
  return (PyObject *)self;
}

PyObject *
data_init(data *self, PyObject *args, PyObject *kwds) {
  return (PyObject *)self;
}

inline PyObject *
forward(data *self, PyObject *args) {
  return (PyObject *)self;
}

inline PyObject *
backward(data *self, PyObject *args) {
  return (PyObject *)self;
}

