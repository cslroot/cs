cmake_minimum_required(VERSION 3.16.0)
set(PROJ_NAME cs.base)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(${PROJ_NAME} ${CS_LIB_TYPE})

file(GLOB_RECURSE CS_BASE_SRC CONFIGURE_DEPENDS 
    #  "*.h"
     "*.cpp"
)
target_sources(${PROJ_NAME} PRIVATE ${CS_BASE_SRC})

target_compile_definitions(${PROJ_NAME} PRIVATE BUILD_CS_BASE_LIB)
target_compile_features(${PROJ_NAME} PRIVATE cxx_std_17)

target_precompile_headers(${PROJ_NAME}
  PRIVATE
    <vector>
    <array>
    <string>
    <array>
    <cassert>
    <unordered_map>
    <iostream>
    <locale>
    <algorithm>
    <codecvt>
    <cstddef>
)

target_include_directories(${PROJ_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${PROJ_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/cs/base)
