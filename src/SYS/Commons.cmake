#---------------------------------------------------------------------------
# Commons.cmake
#---------------------------------------------------------------------------

list(APPEND SYStest_sources
    "")
list(APPEND SYStest_libs
    "GFX")
add_executable(SYStest ${SYStest_sources})
target_link_libraries(SYStest ${SYStest_libs})
