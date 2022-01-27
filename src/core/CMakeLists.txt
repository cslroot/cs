cmake_minimum_required(VERSION 3.16.0)
project(cs.core)

add_compile_definitions(BUILD_CS_CORE_LIB)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


if (CS_BUILD_SHARED_LIBS)
    add_library(cs.core SHARED)
else()
    add_library(cs.core STATIC)
endif()

target_sources(cs.core
PRIVATE
src/cs_core.cpp
src/csobject.cpp
src/entity.cpp
src/geometry.cpp
)

target_link_libraries(cs.core cs.base)

target_include_directories(cs.core 
PUBLIC 
${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(cs.core 
PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR}/include/cs/core)