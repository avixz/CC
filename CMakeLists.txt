#----------------------------------------------------------------------------
# CMakeLists.txt
#----------------------------------------------------------------------------

cmake_minimum_required(VERSION 2.6)
project(CC)

set(CC_VERSION_MAJOR 0)
set(CC_VERSION_MINOR 3)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/deps/include
  )

file(GLOB_RECURSE all_sources
  ${CMAKE_CURRENT_SOURCE_DIR}/sources/*.cc
  )

add_library(CC STATIC ${all_sources})

add_library(glfw STATIC IMPORTED)
set_target_properties(glfw PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../deps/lib/linux/libglfw3.a)
