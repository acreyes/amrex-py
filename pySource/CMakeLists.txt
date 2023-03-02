add_custom_target(__init__.py ALL COMMAND ${CMAKE_COMMAND} -E touch __init__.py)

set(_sources AdvancePhiAllLevels.cpp  AdvancePhiAtLevel.cpp  AmrCoreAdv.cpp  AmrCoreAdv.H bc_fill.H)
list(APPEND _sources DefineVelocity.cpp)
include_directories(Src_K)

pybind11_add_module(pyAmrex pyAmrex.cpp)
pybind11_add_module(AmrCoreAdv pyAmrCoreAdv.cpp)
target_link_libraries(AmrCoreAdv PUBLIC AMReX::amrex)
target_link_libraries(pyAmrex PUBLIC AMReX::amrex)
target_sources(AmrCoreAdv PRIVATE ${_sources})

add_executable(main)
list(APPEND _sources main.cpp)
target_sources(main PRIVATE ${_sources})
target_link_libraries(main PUBLIC AMReX::amrex)