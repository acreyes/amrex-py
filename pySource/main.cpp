
#include <iostream>

#include <cstdio>
#include <AMReX.H>
#include <AMReX_BLProfiler.H>
#include <AMReX_ParallelDescriptor.H>
#include <pybind11/embed.h>

#include <AmrCoreAdv.H>

using namespace amrex;
namespace py = pybind11;

int main(int argc, char* argv[])
{
    amrex::Initialize(argc,argv);

    {
        // timer for profiling
        BL_PROFILE("main()");

        // wallclock time
        const auto strt_total = amrex::second();

        py::scoped_interpreter guard{};
        auto pyMain = py::module_::import("main");
        auto result_main = pyMain.attr("main")();

        // wallclock time
        auto end_total = amrex::second() - strt_total;

        // // print wallclock time
        ParallelDescriptor::ReduceRealMax(end_total ,ParallelDescriptor::IOProcessorNumber());
        amrex::Print() << "\nTotal Time: " << end_total << '\n';
    }

    amrex::Finalize();
}
