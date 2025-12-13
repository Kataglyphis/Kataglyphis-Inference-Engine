cmake_minimum_required(VERSION 3.10)

project(kataglyphis_native)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add GStreamer path to CMAKE_MODULE_PATH
# Allow override via GSTREAMER_ROOT environment variable or CMake variable
if(NOT DEFINED GSTREAMER_ROOT)
    set(GSTREAMER_ROOT "/opt/gstreamer/1.26.7")
endif()

# Verify GStreamer path exists
if(NOT EXISTS "${GSTREAMER_ROOT}")
    message(FATAL_ERROR 
        "GStreamer not found at ${GSTREAMER_ROOT}.\n"
        "Please install GStreamer or set GSTREAMER_ROOT to the correct path.\n"
        "Example: cmake -DGSTREAMER_ROOT=/path/to/gstreamer ...")
endif()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${GSTREAMER_ROOT}/cmake/modules/")

# Find required packages
find_package(PkgConfig REQUIRED)

# Find GStreamer
find_package(GStreamer REQUIRED)
if(NOT GSTREAMER_FOUND)
    message(FATAL_ERROR 
        "GStreamer package not found.\n"
        "Ensure GStreamer is properly installed and CMAKE_MODULE_PATH includes GStreamer cmake modules.\n"
        "Current GSTREAMER_ROOT: ${GSTREAMER_ROOT}")
endif()

# Include directories for GStreamer
if(GSTREAMER_FOUND)
    include_directories(${GSTREAMER_INCLUDE_DIRS})
    link_directories(${GSTREAMER_LIBRARY_DIRS})
endif()

# Add your native sources here
# add_library(kataglyphis_native SHARED
#     native_lib.cpp
# )

# Link GStreamer libraries
# if(GSTREAMER_FOUND)
#     target_link_libraries(kataglyphis_native ${GSTREAMER_LIBRARIES})
# endif()
