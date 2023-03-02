/*
Exposes core amrex functions need in AmrCoreAdv problem

Needs: Initialize
       Finalize
*/
#include <pybind11/pybind11.h>
#include <AMReX.H>
#include <AmrCoreAdv.H>
#include <iostream>

#if PY_VERSION_HEX < 0x03000000
#define MyPyText_AsString PyString_AsString
#else
#define MyPyText_AsString PyUnicode_AsUTF8
#endif

namespace py = pybind11;
using namespace amrex;

/*
This is some magic I found on SO:
https://stackoverflow.com/questions/60040665/replacing-the-command-line-arguments-int-argc-and-char-argv-with-stdvectors
*/
amrex::AMReX* amrInitialize(py::object pyargv11) {
    int argc = 0;
    char ** dargv;
    std::unique_ptr<char*[]> argv;

// convert input list to C/C++ argc/argv
    PyObject* pyargv = pyargv11.ptr();
    if (PySequence_Check(pyargv)) {
        Py_ssize_t sz = PySequence_Size(pyargv);
        argc = (int)sz;
        argv = std::unique_ptr<char*[]>{new char*[sz]};
        for (Py_ssize_t i = 0; i < sz; ++i) {
            PyObject* item = PySequence_GetItem(pyargv, i);
            argv[i] = (char*)MyPyText_AsString(item);
            Py_DECREF(item);
            if (!argv[i] || PyErr_Occurred()) {
                argv = nullptr;
                break;
            }
        }
    }

// bail if failed to convert
    if (!argv) {
        std::cerr << "argument is not a sequence of strings" << std::endl;
        return nullptr;
    }

// call the Initialize function with the proper types
//c++ only seems to be happy if it's passed something declared as char**...
    dargv = argv.get();
    return amrex::Initialize(argc, dargv);
    // return amrex::Initialize(1,"inputs\0");
}

void amrFinalize()
{
    amrex::Finalize();
};

PYBIND11_MODULE(pyAmrex, m)
{
    m.doc() = "Bindings for amrex initialization/finalize";

    m.def("Initialize", &amrInitialize, py::return_value_policy::reference);
    m.def("Evolve"    , &amrFinalize);
}
/*
PYBIND11_MODULE(example, m) {
    py::class_<Animal>(m, "Animal")
        .def("go", &Animal::go);

    py::class_<Dog, Animal>(m, "Dog")
        .def(py::init<>());

    m.def("call_go", &call_go);
*/