#----------------------------------------------------------------------------
# CMakeLists.txt
#----------------------------------------------------------------------------

cmake_minimum_required(VERSION 2.6)
project(CC)

set(CC_VERSION_MAJOR 0)
set(CC_VERSION_MINOR 3)

file(GLOB_RECURSE all_sources
  ${CMAKE_CURRENT_SOURCE_DIR}/sources/*.cc
  )

# Platform
if ("${CC_PLATFORM}" STREQUAL "LINUX")
  file(GLOB_RECURSE sourcesToRemove
    *Windows.cc
    )
  set(CMAKE_CXX_FLAGS "-DLINUX")

elseif ("${CC_PLATFORM}" STREQUAL "EMSC")
  set(CMAKE_CXX_FLAGS "-DEMSC")

elseif ("${CC_PLATFORM}" STREQUAL "WINDOWS")
  set(CMAKE_CXX_FLAGS "-DWINDOWS")
  file(GLOB_RECURSE sourcesToRemove
    *Linux.cc
    )

else ()
  message(FATAL_ERROR "Platform ${CC_PLATFORM} not supported")
endif()

# Remove other platfoms sources
list(REMOVE_ITEM all_sources ${sourcesToRemove})

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/deps/include
  )

add_library(CC STATIC ${all_sources})

add_library(glfw STATIC IMPORTED)
set_target_properties(glfw PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../deps/lib/linux/libglfw3.a)
