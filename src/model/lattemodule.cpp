#include <Python/Python.h>
#include "model.h"

static PyObject *LatteError;
static Model *model;

//module functions
static PyObject *
py_forward(PyObject *self, PyObject *args) {
  
  return PyFloat_FromDouble(*model->forward()(0));
}

static PyObject *
add_layer(PyObject *self, PyObject *args) {
  const char * layer_name;

  if(!PyArg_ParseTuple(args, "s", &layer_name)) {
    return NULL;
  }
  model->add_layer(layer_name);
  return Py_BuildValue("");
}


//Methods Table
static PyMethodDef LatteMethods[] = {
    {"forward", py_forward, METH_VARARGS,
     "forward pass"},
    {"add_layer", add_layer, METH_VARARGS,
      "add a layer to the model"},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

//constructor
PyMODINIT_FUNC 
initlatte(void) {
  PyObject *m;
  m = Py_InitModule("latte", LatteMethods);
  if (m == NULL)
    return;

  model = new Model();    
  LatteError = PyErr_NewException("latte.error", NULL, NULL);
  Py_INCREF(LatteError);
  PyModule_AddObject(m, "error", LatteError);
}
