#include <Python/Python.h>
#include "model.h"

static PyObject *LatteError;

//module functions
static PyObject *
py_forward(PyObject *self, PyObject *args) {
  double num;

  if(!PyArg_ParseTuple(args, "d", &num))
    return NULL;

  Model test;
  num = test.forward(num);
  return PyFloat_FromDouble(num);
}

static PyObject *
add(PyObject *self, PyObject *args) {
  const char * layer_name;

  if(!PyArg_ParseTuple(args, "s", &layer_name)) {
    return NULL;
  }
  system("echo test");

  return Py_BuildValue("");
}


//Methods Table
static PyMethodDef LatteMethods[] = {
    {"forward", py_forward, METH_VARARGS,
     "forward pass"},
    {"add", add, METH_VARARGS,
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
  
  LatteError = PyErr_NewException("latte.error", NULL, NULL);
  Py_INCREF(LatteError);
  PyModule_AddObject(m, "error", LatteError);
}
