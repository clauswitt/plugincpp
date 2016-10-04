
#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(plugincpp)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Enable debug symbols by default
if(CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE Debug)
endif()

include_directories(include)

# Define sources and executable
set(PROJECT_NAME "plugincpp")
add_executable(${PROJECT_NAME} src/main.cpp)

add_subdirectory(plugins/first)
add_subdirectory(plugins/second)
target_compile_features(plugincpp PRIVATE cxx_range_for cxx_auto_type)



