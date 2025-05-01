cmake_minimum_required(VERSION 3.10)
project(MatrixLib LANGUAGES CXX VERSION 0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

#Include the header file
include_directories(/Users/antoniocicchella/Programs/C++/matrix-lib/include/)


#Include the source
add_library(matrix STATIC src/matrix.cpp
                        include/matrix.hpp
                        include/operations.hpp
)

#Add unit tests
enable_testing()
add_subdirectory(tests)


