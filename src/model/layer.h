#include <Python.h>
#include "structmember.h"

typedef struct {
  PyObject_HEAD
} layer;

PyObject *
layer_new(PyTypeObject *type, PyObject *args, PyObject *kwds); 

PyObject *
layer_forward(layer *self, PyObject *args); 

PyObject *
layer_backward(layer *self, PyObject *args);

static PyMethodDef layer_methods[] = {
    {"forward", (PyCFunction)layer_forward, METH_VARARGS,
      "Compute forward output"}, 
    {"backward", (PyCFunction)layer_backward, METH_VARARGS,
      "backpropagate"}, 
   {NULL, NULL, 0, NULL}  /* Sentinel */
};

static PyMemberDef layer_members[] = {
  {NULL}
};

static PyTypeObject layer_type = {
    PyObject_HEAD_INIT(NULL)
    0,                         /*ob_size*/
    "latte.layer",             /*tp_name*/
    sizeof(layer),             /*tp_basicsize*/
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
    "Some Layer",              /* tp_doc */
    0,		                     /* tp_traverse */
    0,		                     /* tp_clear */
    0,		                     /* tp_richcompare */
    0,		                     /* tp_weaklistoffset */
    0,		                     /* tp_iter */
    0,		                     /* tp_iternext */
    layer_methods,             /* tp_methods */
    layer_members,                         /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    0,      /* tp_init */
    0,                         /* tp_alloc */
    layer_new,                 /* tp_new */
};


