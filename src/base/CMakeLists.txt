cmake_minimum_required(VERSION 3.16.0)
project(cs.base)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_definitions(CS_BASE_EXPORT)

if (CS_BUILD_SHARED_LIBS)
    add_library(cs.base SHARED)
else()
    add_library(cs.base STATIC)
endif()

file(GLOB_RECURSE CS_BASE_SRC CONFIGURE_DEPENDS 
     "*.h"
     "*.cpp"
)

target_precompile_headers(cs.base
  PRIVATE
    <vector>
    <string>
    <array>
    <cassert>
    <unordered_map>
)

target_sources(cs.base
PRIVATE
${CS_BASE_SRC}
)

target_include_directories(cs.base 
PUBLIC 
${CMAKE_CURRENT_SOURCE_DIR}/include)


target_include_directories(cs.base 
PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR}/include/cs/base)

