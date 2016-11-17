#include <Python/Python.h>
#include <iostream>

#include "model.h"
#include "layer.h"

using std::cout;

//Methods Table
static PyMethodDef LatteMethods[] = {
  {NULL, NULL, 0, NULL}        /* Sentinel */
};

//constructor
PyMODINIT_FUNC 
initlatte(void) {
  PyObject *m;

  m = Py_InitModule("latte", LatteMethods);
  if (m == NULL)
    return;

  model_type.tp_new = PyType_GenericNew;
  layer_type.tp_new = PyType_GenericNew;

  if (PyType_Ready(&model_type) < 0 && PyType_Ready(&layer_type) < 0)
    return;

  Py_INCREF(&model_type);
  Py_INCREF(&layer_type);
  PyModule_AddObject(m, "model", (PyObject *)&model_type);
  PyModule_AddObject(m, "layer", (PyObject *)&layer_type);
}

