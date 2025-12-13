cmake_minimum_required(VERSION 3.18.1)

project("kataglyphis_native_inference_plugin")

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add GStreamer module path
list(APPEND CMAKE_MODULE_PATH "/opt/gstreamer")

# Find required packages
find_package(PkgConfig REQUIRED)

# Find GStreamer
find_package(GStreamer REQUIRED)

# Include directories
include_directories(
    ${GSTREAMER_INCLUDE_DIRS}
)

# Create the native library
add_library(
    kataglyphis_native_inference_plugin
    SHARED
    native_inference.cpp
)

# Link libraries
target_link_libraries(
    kataglyphis_native_inference_plugin
    ${GSTREAMER_LIBRARIES}
    android
    log
)
