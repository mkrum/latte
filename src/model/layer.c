#include <Python.h>
#include "layer.h"

PyObject *
layer_new(PyTypeObject *type, PyObject *args, PyObject *kwds) {
  layer *self = NULL;
  return (PyObject *)self;
}

PyObject *
layer_forward(layer *self, PyObject *args) {
  return (PyObject *)self;
}

PyObject *
layer_backward(layer *self, PyObject *args) {
  return (PyObject *)self;
}

PyMODINIT_FUNC
initlayer(void) {
	PyObject *m;
	
	m = Py_InitModule("layer", layer_methods);	

	if (m == NULL) {
	  return;
	}
}
