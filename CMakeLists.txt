#---------------------------------------------------------------------------
# CMakeLists.txt
#---------------------------------------------------------------------------

cmake_minimum_required(VERSION 2.8)

# Project settings
project(CC)
set(CC_VERSION_MAJOR 0)
set(CC_VERSION_MINOR 2)

# Output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/${CC_PLATFORM})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CC_PLATFORM})

# Includes and libraries
include_directories(src)
link_directories(lib/${CC_PLATFORM})

# Sources
add_subdirectory(src)
