#----------------------------------------------------------------------------
# Emscripten toolchain file
#----------------------------------------------------------------------------

# platform suffix (.bat on windows)
if (CMAKE_HOST_WIN32)
  set(TOOLS_SUFFIX ".bat")
else()
  set(TOOLS_SUFFIX "")
endif()

# Cross compilers
set(CMAKE_C_COMPILER "$ENV{EMSCRIPTEN}/emcc${TOOLS_SUFFIX}")
set(CMAKE_CXX_COMPILER "$ENV{EMSCRIPTEN}/em++${TOOLS_SUFFIX}")

# Target libraries and includes
set(CMAKE_FIND_ROOT_PATH $ENV{EMSCRIPTEN})
set(CMAKE_SYSTEM_INCLUDE_PATH "$ENV{EMSCRIPTEN}/system/include")

