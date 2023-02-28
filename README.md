# amrex-py

playing around with exposing AMReX functionality to python using `pybind11`.

As a first step I've copied the `AdvectionAmrCore` tutorial setup from AMReX here and 
configured CMake.

```bash
mkdir build && cd build
cmake .. -DAMReX_SPACEDIM=2
make -j
./main inputs
```