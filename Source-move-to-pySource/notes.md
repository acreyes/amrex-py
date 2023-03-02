# AMR Advection (AMR-Core)

Some notes on what virtual functions from the AMREX libarary need to be implemented and how they are called inside of the AmrCore-Advection tutorial problem provided by the AMReX tutorials.

## main.cpp

    * Uses the `AmrCoreAdv` (`AmrCoreAdv.cpp' ) class that implements all the numerical algorithms. The instance is `amr_core_adv`.

The core methods are:
    * `AmrCoreAdv::InitData`
    * `AmrCoreAdv::Evolve`

## AmrCoreAdv.cpp

This inherits the `amrex` namespace. The `class` is defined in `AmrCoreAdv.H`
    * this is where I could expose the class to python w/ pybind11

`AmrCoreAdv` constructor is responsible for reading runtime parameters and initializing the grid data structures
    * uses `ParmParse` `query` method to get and fill the space for the runtime parameters.
        * can also use the `add` method to directly set the variable's value
    * subcycling time steps are set in each level
    * arrays for phi & time (old/new), dt and face velocity are sized to number of max refinement levels.
    * BC's are set on each face

`Evolve` is the main loop over time steps. 
    * computes time step `ComputeDt`
    * calls `timeStep{With|No}Subcycling
    * manages calls to plot/checkpoint file writes

`InitData` restarts from checkpoint or creates initial data from scratch.
    * `InitFromScratch` is a method in `AMReX_AmrCore` that calls `MakeNewGrids` from `AMReX_AmrMesh` who finally calls `MakeNewLevelFromScratch` that ultimately is overridden by the implementation in `AmrCoreAdv`.