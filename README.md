#############################################################################
# Build Instructions
#############################################################################

#Generate dependencies (see deps/README)

#Build the library
mkdir build
cd build
cmake -DCC_PLATFORM=LINUX -DCMAKE_BUILD_TYPE=Debug ..
