cmake_minimum_required(VERSION 3.0.0)
project(cs)

option(CS_BUILD_SHARED_LIBS "build as a shared library" ON)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(examples)
