#include <Python/Python.h>
#include "model.h"

#include <iostream>

using std::cout;

static PyObject *LatteError;
static Model *model;

//module functions
static PyObject *
py_forward(PyObject *self, PyObject *args) {
  double out = *model->forward()(0);
  return PyFloat_FromDouble(out);
}

static PyObject *
add_data_layer(PyObject *self, PyObject *args, PyObject *kwargs) {

  const char *path;
  bool random = true;
  static char *kwlist[] = { "path", "random" , NULL};
  PyObject *boolean_val = NULL; 
  if(!PyArg_ParseTupleAndKeywords(args, kwargs, "s|O", kwlist, &path, &boolean_val)) {
    return NULL;
  }
  random = PyObject_IsTrue(boolean_val);
  model->add_data_layer(path, random);
  return Py_BuildValue("");
}

//Methods Table
static PyMethodDef LatteMethods[] = {
    {"forward", py_forward, METH_VARARGS,
     "forward pass"},
    {"add_data_layer", (PyCFunction)add_data_layer, METH_VARARGS | METH_KEYWORDS,
      "adds a data layer to the model"},
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
