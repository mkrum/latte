#include <Python.h>
#include "structmember.h"

typedef struct {
  PyObject_HEAD
  PyObject** layers;
  int index;
} model;

PyObject *
model_new(PyTypeObject *type, PyObject *args, PyObject *kwds) {
  model *self = NULL;
  self->index = 0;
  return (PyObject *)self;
}

PyObject *
add_layer(model *self, PyObject *args) {
  PyObject *layer = NULL;
  if (!PyArg_ParseTuple(args, "O", layer)) {
    return NULL;
  }
  return (PyObject *)self;
}

static PyMemberDef model_members[] = {
    {"layers", T_OBJECT_EX , offsetof(model, layers), 0,
     "Layers"},
    {NULL}  /* Sentinel */
};

static PyMethodDef model_methods[] = {
    {"add_layer", (PyCFunction)add_layer, METH_VARARGS,
      "adds a layer to the model"},
    {NULL}
};

static PyTypeObject model_type = {
    PyObject_HEAD_INIT(NULL)
    0,                         /*ob_size*/
    "latte.make.model",             /*tp_name*/
    sizeof(model),             /*tp_basicsize*/
    0,                         /*tp_itemsize*/
    0,                         /*tp_dealloc*/
    0,                         /*tp_print*/
    0,                         /*tp_getattr*/
    0,                         /*tp_setattr*/
    0,                         /*tp_compare*/
    0,                         /*tp_repr*/
    0,                         /*tp_as_number*/
    0,                         /*tp_as_sequence*/
    0,                         /*tp_as_mapping*/
    0,                         /*tp_hash */
    0,                         /*tp_call*/
    0,                         /*tp_str*/
    0,                         /*tp_getattro*/
    0,                         /*tp_setattro*/
    0,                         /*tp_as_buffer*/
    Py_TPFLAGS_DEFAULT,        /*tp_flags*/
    "Base Model Object",       /* tp_doc */
    0,		                     /* tp_traverse */
    0,		                     /* tp_clear */
    0,		                     /* tp_richcompare */
    0,		                     /* tp_weaklistoffset */
    0,		                     /* tp_iter */
    0,		                     /* tp_iternext */
    model_methods,             /* tp_methods */
    model_members,             /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    0,      /* tp_init */
    0,                         /* tp_alloc */
    model_new,                 /* tp_new */
};


//Methods Table
static PyMethodDef MakeMethods[] = {
  {NULL, NULL, 0, NULL}        /* Sentinel */
};

//constructor
PyMODINIT_FUNC 
initmake(void) {
  PyObject *m;

	model_type.tp_new = PyType_GenericNew;

	m = Py_InitModule("make", MakeMethods);
  if (m == NULL)
    return;

	if (PyType_Ready(&model_type) < 0)
    return;

  Py_INCREF(&model_type);
  PyModule_AddObject(m, "model", (PyObject *)&model_type);
}
