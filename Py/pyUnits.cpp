
#include <pybind11/pybind11.h>
#include "Units.H"

namespace py = pybind11;

class pyUnit:
     public Units
{
public:
    using Units::Units;
    void Init() override{
        PYBIND11_OVERRIDE_PURE(
            void,
            Units,
            Init
        );
    }
};

PYBIND11_MODULE(Units, m){
    py::class_<Units,pyUnit>(m,"Units")
        .def(py::init<>())
        .def("Init",&Units::Init);
}