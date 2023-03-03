add_custom_target(__init__.py ALL COMMAND ${CMAKE_COMMAND} -E touch __init__.py)

set(_sources AdvancePhiAllLevels.cpp  AdvancePhiAtLevel.cpp  AmrCoreAdv.cpp  AmrCoreAdv.H bc_fill.H)
list(APPEND _sources DefineVelocity.cpp main.cpp)
include_directories(Src_K)

pybind11_add_module(pyAmrex pyAmrex.cpp)
# pybind11_add_module(AmrCoreAdv pyAmrCoreAdv.cpp)
# target_link_libraries(AmrCoreAdv PUBLIC AMReX::amrex)
target_link_libraries(pyAmrex PUBLIC AMReX::amrex)
target_sources(pyAmrex PUBLIC ${_sources})

add_executable(main)
target_sources(main PRIVATE ${_sources})
target_link_libraries(main PUBLIC AMReX::amrex pybind11::embed)

#copy python scripts
execute_process(
    COMMAND ${CMAKE_COMMAND} -E 
    create_symlink "${CMAKE_CURRENT_SOURCE_DIR}/main.py" "${CMAKE_CURRENT_BINARY_DIR}/main.py"
    )
execute_process(
    COMMAND ${CMAKE_COMMAND} -E 
    create_symlink "${CMAKE_CURRENT_SOURCE_DIR}/inputs" "${CMAKE_CURRENT_BINARY_DIR}/inputs"
    )