#include "model.h"

PyObject *
model_new(PyTypeObject *type, PyObject *args, PyObject *kwds) {
  model *self = NULL;
  self->layers = new PyObject*[100];
  self->index = 0;
  return (PyObject *)self;
}

PyObject *
add_layer(model *self, PyObject *args) {
  PyObject *layer = NULL;
  if (!PyArg_ParseTuple(args, "O", layer)) {
    return NULL;
  }
  self->layers[self->index] = layer;
  return (PyObject *)self;
}

