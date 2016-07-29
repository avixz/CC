#----------------------------------------------------------------------------
# CMakeLists.txt
#----------------------------------------------------------------------------

cmake_minimum_required(VERSION 2.6)
project(SystemTest)

set(CMAKE_CXX_FLAGS_DEBUG "-g")

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/../../include
  )

link_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/../../build
  )

file(GLOB_RECURSE all_sources
  ${CMAKE_CURRENT_SOURCE_DIR}/*.cc
  )

add_executable(SystemTest ${all_sources})
target_link_libraries(SystemTest CC)
