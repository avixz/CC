#----------------------------------------------------------------------------
#	android.toolchain.cmake
#	cmake toolchain file for cross-compiling to android.
#----------------------------------------------------------------------------

set(ANDROID_CPU "arm")
set(ANDROID_API "android-19")
set(ANDROID_NDK_STL "gnu-libstdc++")
set(ANDROID_NDK_NAME "android-ndk-r11b")
set(ANDROID_NDK_GCC_VERSION "4.9")

if (${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Linux")
    set(ANDROID_NDK_HOST "linux-x86_64")
    get_filename_component(ANDROID_NDK_ROOT "../CC/sdks/linux/${ANDROID_NDK_NAME}" ABSOLUTE)
    get_filename_component(ANDROID_SDK_ROOT "../CC/sdks/linux/android-sdk-linux" ABSOLUTE)
    set(ANDROID_NDK_EXE_EXT "")
    set(ANDROID_SDK_TOOL_EXT "")
endif()

if (${ANDROID_CPU} STREQUAL "arm")
    set(ANDROID_NDK_ARCH "armeabi-v7a")
    set(ANDROID_NDK_SYSROOT_DIR "arch-arm")
    set(ANDROID_NDK_ABI "armeabi-v7a-hard") 
    set(ANDROID_NDK_ABI_EXT "arm-linux-androideabi")
    set(ANDROID_NDK_GCC_PREFIX "arm-linux-androideabi")
    set(ANDROID_NDK_ARCH_CFLAGS "-march=armv7-a")
endif()

# Root dirs
set(ANDROID_NDK_SYSROOT "${ANDROID_NDK_ROOT}/platforms/${ANDROID_API}/${ANDROID_NDK_SYSROOT_DIR}")
set(ANDROID_NDK_STL_ROOT "${ANDROID_NDK_ROOT}/sources/cxx-stl/${ANDROID_NDK_STL}/${ANDROID_NDK_GCC_VERSION}")
set(ANDROID_NDK_TOOLCHAIN_BIN "${ANDROID_NDK_ROOT}/toolchains/${ANDROID_NDK_ABI_EXT}-${ANDROID_NDK_GCC_VERSION}/prebuilt/${ANDROID_NDK_HOST}/bin")

# disable compiler detection
include(CMakeForceCompiler)
CMAKE_FORCE_C_COMPILER("${CMAKE_C_COMPILER}" GNU)
CMAKE_FORCE_CXX_COMPILER("${CMAKE_CXX_COMPILER}" GNU)

# System libraries
set(CMAKE_C_STANDARD_LIBRARIES "-landroid -llog -lc -lgcc")
set(CMAKE_CXX_STANDARD_LIBRARIES "${CMAKE_C_STANDARD_LIBRARIES} ${ANDROID_NDK_STL_LDFLAGS}")

# Xcompilers
set(CMAKE_C_COMPILER "${ANDROID_NDK_TOOLCHAIN_BIN}/${ANDROID_NDK_GCC_PREFIX}-gcc${ANDROID_NDK_EXE_EXT}")
set(CMAKE_CXX_COMPILER "${ANDROID_NDK_TOOLCHAIN_BIN}/${ANDROID_NDK_GCC_PREFIX}-g++${ANDROID_NDK_EXE_EXT}")
set(CMAKE_LINKER "${ANDROID_NDK_TOOLCHAIN_BIN}/${ANDROID_NDK_GCC_PREFIX}-g++${ANDROID_NDK_EXE_EXT}")

# System paths
set(CMAKE_FIND_ROOT_PATH ${ANDROID_NDK_SYSROOT})
set(CMAKE_SYSTEM_PROGRAM_PATH ${ANDROID_NDK_TOOLCHAIN_BIN})

# Flags
set(CMAKE_C_FLAGS "-DANDROID --sysroot=${ANDROID_NDK_SYSROOT} ${ANDROID_NDK_ARCH_CFLAGS} -I${ANDROID_NDK_ROOT}/${ANDROID_API}/${ANDROID_NDK_SYSROOT_DIR}/usr/include")
set(CMAKE_CXX_FLAGS "-DANDROID --sysroot=${ANDROID_NDK_SYSROOT} ${ANDROID_NDK_ARCH_CFLAGS} -I${ANDROID_NDK_STL_ROOT}/include -I${ANDROID_NDK_STL_ROOT}/libs/${ANDROID_NDK_ABI}/include -I${ANDROID_NDK_ROOT}/${ANDROID_API}/${ANDROID_NDK_SYSROOT_DIR}/usr/include")
set(CMAKE_SHARED_LINKER_FLAGS "--sysroot=${ANDROID_NDK_SYSROOT} -L${ANDROID_NDK_STL_ROOT}/libs/${ANDROID_NDK_ABI}")

message("NDK_SYSROOT: ${ANDROID_NDK_SYSROOT}")
message("NDK_STL_ROOT: ${ANDROID_NDK_STL_ROOT}")
