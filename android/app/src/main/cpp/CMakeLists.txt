cmake_minimum_required(VERSION 3.10)

project(kataglyphis_native)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add GStreamer path to CMAKE_MODULE_PATH
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "/opt/gstreamer/1.26.7/cmake/modules/")

# Find required packages
find_package(PkgConfig REQUIRED)

# Find GStreamer
find_package(GStreamer REQUIRED)

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
