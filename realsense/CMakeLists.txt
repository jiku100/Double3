# License: Apache 2.0. See LICENSE file in root directory.
# Copyright(c) 2019 Intel Corporation. All Rights Reserved.
cmake_minimum_required(VERSION 3.1.0)

project(realsense2)

# Find librealsense2 installed package
find_package(OpenCV REQUIRED)
find_package(realsense2 REQUIRED)

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories(${OpenCV_INCLUDE_DIRS})

# Add the application sources to the target
add_executable(floor floor.cpp)
add_executable(front front.cpp)

# Link librealsense2 to the target
target_link_libraries(floor ${OpenCV_LIBS} ${realsense2_LIBRARY})
target_link_libraries(front ${OpenCV_LIBS} ${realsense2_LIBRARY})