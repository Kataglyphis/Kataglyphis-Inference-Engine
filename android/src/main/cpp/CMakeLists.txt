cmake_minimum_required(VERSION 3.10)

project(native_inference)

# Add GStreamer native library support for Android
if(ANDROID)
  set(JNI_LIBS_DIR "${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}")
  message(STATUS "Using JNI libs dir: ${JNI_LIBS_DIR}")

  foreach(gstlib libgstreamer-1.0 libgobject-2.0 libglib-2.0 libgstbase-1.0)
    if(EXISTS "${JNI_LIBS_DIR}/${gstlib}.so")
      add_library(${gstlib} SHARED IMPORTED)
      set_target_properties(${gstlib} PROPERTIES IMPORTED_LOCATION "${JNI_LIBS_DIR}/${gstlib}.so")
    endif()
  endforeach()

  # Link your native target with the imported targets
  target_link_libraries(native_inference PRIVATE libgstreamer-1.0 libgobject-2.0 libglib-2.0 libgstbase-1.0)
endif()
