#----------------------------------------------------------------------------
#	emscripten.toolchain.cmake
#	cmake toolchain file for cross-compiling to emscripten.
#----------------------------------------------------------------------------

if (${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Windows")
    set(EMSC_EMSDK_DIRNAME "../CC/sdks/win/emsdk_portable/emscripten/master")
elseif (${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Linux")
    set(EMSC_EMSDK_DIRNAME "../CC/sdks/linux/emsdk_portable/emscripten/master")
endif()

# tool suffix (.bat on windows)
if (CMAKE_HOST_WIN32)
    set(EMCC_SUFFIX ".bat")
else()
    set(EMCC_SUFFIX "")
endif()

get_filename_component(EMSCRIPTEN_ROOT_PATH "${EMSC_EMSDK_DIRNAME}" ABSOLUTE)

set(CMAKE_CXX_COMPILER "${EMSCRIPTEN_ROOT_PATH}/em++${EMCC_SUFFIX}")
set(CMAKE_LINKER "${EMSCRIPTEN_ROOT_PATH}/emcc${EMCC_SUFFIX}")

set(CMAKE_SYSTEM_INCLUDE_PATH "${EMSCRIPTEN_ROOT_PATH}/system/include")
