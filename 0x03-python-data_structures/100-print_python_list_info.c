#include <Python.h>
#include <object.h>
#include <listobject.h>

void print_python_list_info(PyObject *p) {
    if (PyList_Check(p)) {
        Py_ssize_t size = PyList_Size(p);
        Py_ssize_t allocated = ((PyListObject *)p)->allocated;

        printf("[*] Size of the Python List = %zd\n", size);
        printf("[*] Allocated = %zd\n", allocated);

        for (Py_ssize_t i = 0; i < size; ++i) {
            PyObject *item = PyList_GetItem(p, i);
            const char *type_name = Py_TYPE(item)->tp_name;
            printf("Element %zd: %s\n", i, type_name);
        }
    }
}
