# Set the minimum required version of CMake for this project
cmake_minimum_required(VERSION 3.10)

# Set the name of the project
project(TinySTL)

# Specify the C++ standard to use
set(CMAKE_CXX_STANDARD 20)       # Use C++20 standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # Enforce the specified C++ standard

# Add an executable target
add_executable(VectorTest TinySTL/Test/VectorTest.cpp TinySTL/Detail/Alloc.cpp)
