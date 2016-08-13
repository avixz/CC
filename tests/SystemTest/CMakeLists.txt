#----------------------------------------------------------------------------
# CMakeLists.txt
#----------------------------------------------------------------------------

cmake_minimum_required(VERSION 2.6)
project(SystemTest)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/../../include
  )

# Platform
# FIXME: Code duplication
if ("${CC_PLATFORM}" STREQUAL "LINUX")
  set(CMAKE_CXX_FLAGS "-DLINUX")
  link_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../../build
    ${CMAKE_CURRENT_SOURCE_DIR}/../../deps/lib/linux
    )
  #FIXME: Is linking with all these libraries necessary?
  set(platformLibraries
    "X11"
    "Xrandr"
    "Xi"
    "Xinerama"
    "Xxf86vm"
    "Xcursor"
    "GL"
    "pthread"
    )
  set(platformFlags "")

elseif ("${CC_PLATFORM}" STREQUAL "EMSC")
  set(CMAKE_CXX_FLAGS "-DEMSC")

elseif ("${CC_PLATFORM}" STREQUAL "WINDOWS")
  set(CMAKE_CXX_FLAGS "-DWINDOWS")
  link_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../../build/Debug
    ${CMAKE_CURRENT_SOURCE_DIR}/../../deps/lib/windows
    )
  set(platformLibraries
    "OpenGL32"
    )
  set(platformFlags
    "WIN32"
    )

else()
  message(FATAL_ERROR "Platform ${CC_PLATFORM} not supported")
endif()

file(GLOB_RECURSE all_sources
  ${CMAKE_CURRENT_SOURCE_DIR}/*.cc
  )

add_executable(SystemTest ${platformFlags} ${all_sources})

target_link_libraries(SystemTest CC glfw3 ${platformLibraries})
