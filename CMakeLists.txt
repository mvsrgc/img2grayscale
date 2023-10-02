cmake_minimum_required(VERSION 3.10)
project(GrayScaleConverter)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

# Find OpenCV
find_package(OpenCV REQUIRED)

# Find OpenCL
find_package(OpenCL REQUIRED)

# Specify include directories
include_directories(${OpenCV_INCLUDE_DIRS} ${OpenCL_INCLUDE_DIRS})

# Specify target and source files to compile
add_executable(GrayScaleConverter main.cpp)

# Link libraries
target_link_libraries(GrayScaleConverter ${OpenCV_LIBS} ${OpenCL_LIBRARIES})