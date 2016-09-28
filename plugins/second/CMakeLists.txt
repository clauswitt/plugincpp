
#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

add_library(second_plugin SHARED src/main.cpp)

set_target_properties( second_plugin
      PROPERTIES
      LIBRARY_OUTPUT_DIRECTORY "../bin"
      )
target_compile_features(second_plugin PRIVATE cxx_range_for cxx_auto_type)



