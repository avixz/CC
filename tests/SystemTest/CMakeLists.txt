#----------------------------------------------------------------------------
# CMakeLists.txt
#----------------------------------------------------------------------------

cmake_minimum_required(VERSION 2.6)
project(SystemTest)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/../../include
  )

link_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/../../build
  ${CMAKE_CURRENT_SOURCE_DIR}/../../deps/lib/linux
  )

file(GLOB_RECURSE all_sources
  ${CMAKE_CURRENT_SOURCE_DIR}/*.cc
  )

add_executable(SystemTest ${all_sources})

#FIXME: Is linking with all these libraries necessary?
target_link_libraries(SystemTest CC glfw3 X11 Xrandr Xi Xinerama Xxf86vm Xcursor GL pthread)
