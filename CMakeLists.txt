cmake_minimum_required(VERSION 3.28.0)

project(DesignPatterns VERSION 0.1 LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(main)
add_subdirectory(lib)
add_subdirectory(tests)