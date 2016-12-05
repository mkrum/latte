#include <Python.h>
#include "structmember.h"
#include <string>
#include <vector>
#include <memory>

#include "layer.h"
#include "layers/debug.h"
#include "layers/data.h"
#include "graph.h"

//Debugging
#include <iostream>

using std::string;
using std::vector;
using std::cout;

typedef struct {
  PyObject_HEAD
  Graph graph;
  int index;
} model;


PyObject *
model_new(PyTypeObject *type, PyObject *args, PyObject *kwds) {
  model *self = NULL;
  self->index = 0;
  return (PyObject *)self;
}

vector<string> read_PyList(PyObject *list) {

  vector<string> args;
  int list_size = PyList_Size(list);
  if (!PyList_CheckExact(list)) {
    return args;
  }

  for(int i = 0; i < list_size; i++) {
    PyObject *StrObj = PyList_GetItem(list, i);
    char* line = PyString_AsString(StrObj);
    if (line != NULL) {
      string temp(line);
      args.push_back(temp);
    }
  }

  // You can't use the list after this
  Py_DECREF(list);
  return args;
}

PyObject *
add_layer(model *self, PyObject *args) {
  const char* type;
  const char* name;

  PyObject *list_args;
  PyObject *list_in;
  PyObject *list_out;

  if (!PyArg_ParseTuple(args, "ssO!O!O!", &type, &name, &PyList_Type, &list_in, &PyList_Type, &list_out, &PyList_Type, &list_args)) {
    return NULL;
  }

  string s_type(type);
  string s_name(name);

  vector<string> in_args = read_PyList(list_args);
  vector<string> inputs = read_PyList(list_in);
  vector<string> outputs = read_PyList(list_out);

  self->graph.insert(s_type, s_name, inputs, outputs, in_args);

  return (PyObject *)self;
}

PyObject *
run(model *self, PyObject *args) {
  const char* output;

  if (!PyArg_ParseTuple(args, "s", &output)) {
    return NULL;
  }

  string s_output(output);
  self->graph.find_path(s_output);
  self->graph.forward();
  return (PyObject *)self;
}

static PyMemberDef model_members[] = {
    {NULL}  /* Sentinel */
};

static PyMethodDef model_methods[] = {
    {"add_layer", (PyCFunction)add_layer, METH_VARARGS,
      "adds a layer to the model"},
    {"run", (PyCFunction)run, METH_VARARGS,
      "run the model"},
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
