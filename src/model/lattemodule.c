#include "Python.h"
#include "model.h"
#include "layer.h"

//Methods Table
static PyMethodDef LatteMethods[] = {
  {NULL, NULL, 0, NULL}        /* Sentinel */
};

//constructor
PyMODINIT_FUNC 
initlatte(void) {
  PyObject *m;

	model_type.tp_new = PyType_GenericNew;
  layer_type.tp_new = PyType_GenericNew;

	m = Py_InitModule("latte", LatteMethods);
  if (m == NULL)
    return;

	if (PyType_Ready(&model_type) < 0 || PyType_Ready(&layer_type) < 0)
    return;

  Py_XINCREF(&model_type);
  Py_XINCREF(&layer_type);
  PyModule_AddObject(m, "model", (PyObject *)&model_type);
  PyModule_AddObject(m, "layer", (PyObject *)&layer_type);

}
