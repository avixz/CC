cmake_minimum_required(VERSION 2.6)
project(CC)

set(CMAKE_BUILD_TYPE Debug)
set(CC_VERSION_MAJOR 1)
set(CC_VERSION_MINOR 0)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
file(GLOB_RECURSE all_sources
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

# Remove all plaform specific sources
file(GLOB_RECURSE to_remove_all *Windows.cpp *WGL.cpp
    *Linux.cpp *GLX.cpp
    *Emscripten.cpp *EGL.cpp
    *Android.cpp android*)
list(REMOVE_ITEM all_sources ${to_remove_all})
list(REMOVE_DUPLICATES all_sources)

# Linux
if (${CC_PLATFORM} STREQUAL "LINUX")
    set(CMAKE_CXX_FLAGS "-DLINUX")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/linux)
    file(GLOB_RECURSE to_add_all *Linux.cpp *GLX.cpp)
    list(APPEND all_sources ${to_add_all})

# Emscripten
elseif (${CC_PLATFORM} STREQUAL "EMSC")
    set(CMAKE_CXX_FLAGS "-DEMSC")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/emsc)
    file(GLOB_RECURSE to_add_all *Emscripten.cpp *EGL.cpp)
    list(APPEND all_sources ${to_add_all})

# Windows
elseif (${CC_PLATFORM} STREQUAL "WINDOWS")
    set(CMAKE_CXX_FLAGS "-DWINDOWS")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows)
    file(GLOB_RECURSE to_add_all *Windows.cpp *WGL.cpp)
    list(APPEND all_sources ${to_add_all})

    source_group(IGL ${CMAKE_CURRENT_SOURCE_DIR}/src/IGL/*)
    source_group(SYS ${CMAKE_CURRENT_SOURCE_DIR}/src/SYS/*)
    source_group(GL ${CMAKE_CURRENT_SOURCE_DIR}/src/GL/*)

# Android
elseif (${CC_PLATFORM} STREQUAL "ANDROID")
    #set(CMAKE_CXX_FLAGS "-DANDROID")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/android)
    file(GLOB_RECURSE to_add_all *Android.cpp *EGL.cpp android*)
    list(APPEND all_sources ${to_add_all})
endif()

# android ndk code is always in dynamic libraries
if (${CC_PLATFORM} STREQUAL "ANDROID")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/android)
    add_library(CC SHARED ${all_sources})
else()
    add_library(CC STATIC ${all_sources})
endif()
