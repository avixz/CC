![alt tag](https://upload.wikimedia.org/wikipedia/commons/9/99/Linux_kernel_and_OpenGL_video_games.svg)

Instructions
------------

Linux
-----
mkdir build
cd build
cmake .. -DCC_PLATFORM=LINUX

Android
-------
Install the android sdk and ndk (see docs/androidSdk.txt)

mkdir build
cd build
cmake .. -DCC_PLATFORM=ANDROID -DCMAKE_TOOLCHAIN_FILE="../../CC/include/SYS/emscripten.toolchain.cmake"

Web
---
Install the emscripten sdk (see docs/emscriptenSdk.txt)

mkdir build
cd build
cmake .. -DCC_PLATFORM=EMSC -DCMAKE_TOOLCHAIN_FILE="../../CC/include/SYS/emscripten.toolchain.cmake"

Windows
-------
mkdir build
cd build
cmake .. -DCC_PLATFORM=WINDOWS
