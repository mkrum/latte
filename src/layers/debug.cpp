#include "layer.h"

PyObject *
layer_new(PyTypeObject *type, PyObject *args, PyObject *kwds) {
  layer *self = NULL;
  self->vals = Matrix();
  return (PyObject *)self;
}

PyObject *
forward(layer *self, PyObject *args) {
  return (PyObject *)self;
}

PyObject *
backward(layer *self, PyObject *args) {
  return (PyObject *)self;
}
