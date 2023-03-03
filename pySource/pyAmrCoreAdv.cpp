// wrappers for AmrCoreAdv clas
// methods that need to be exposed are:
//    * InitData
//    * Evolve

#include <pybind11/pybind11.h>
#include "AmrCoreAdv.H"

namespace py = pybind11;

PYBIND11_MODULE(AmrCoreAdv,m)
{
    m.doc() = "Binds AmrCoreAdv class methods used explicitly in main.cpp";

    py::class_<AmrCoreAdv>(m,"AmrCoreAdv")
        .def(py::init<>())
        .def("Evolve"  , &AmrCoreAdv::Evolve)
        .def("InitData", &AmrCoreAdv::InitData);
}

/*
PYBIND11_MODULE(example, m) {
    py::class_<Animal>(m, "Animal")
        .def("go", &Animal::go);

    py::class_<Dog, Animal>(m, "Dog")
        .def(py::init<>());

    m.def("call_go", &call_go);
}*/