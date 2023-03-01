
#include <pybind11/pybind11.h>

namespace py = pybind11;
class Units
{
public:
    virtual ~Units() {};

    // call before main evolution loop
    virtual void Init(){};

//     // call in main evolution loop
    virtual void Evolve(){};

//     // call after main evolution loop before exiting
    virtual void Finalize(){};

private:

//     // call just before entering this unit's Evolve
    virtual void Adjust(){};

};

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