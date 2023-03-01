cmake_minimum_required(VERSION 3.25)
project(amrex-py)

# add_subdirectory(extern/amrex)

add_subdirectory(extern/pybind11)
# find_package(pybind11)

# make list of source files
pybind11_add_module(Units Units.cpp)
# pybind11_add_module(example example.cpp)
# set(_sources AdvancePhiAllLevels.cpp  AdvancePhiAtLevel.cpp  AmrCoreAdv.cpp  AmrCoreAdv.H bc_fill.H)
# list(APPEND _sources DefineVelocity.cpp  face_velocity.H  Kernels.H  main.cpp  Tagging.H)
# list(APPEND _sources Src_K/Adv_K.H  Src_K/compute_flux_${AMReX_SPACEDIM}D_K.H  Src_K/slope_K.H)
# list(TRANSFORM _sources PREPEND Source/)
# list(APPEND _sources Exec/Prob.H)

# list(FILTER _sources INCLUDE REGEX "\\.cpp$")
# set(_include_dirs Source Source/Src_K Exec)

# add_executable(main)
# target_sources(main PRIVATE ${_sources})
# target_include_directories(main PRIVATE ${_include_dirs})
# target_link_libraries(main PUBLIC AMReX::amrex)
# configure_file(Exec/inputs inputs)