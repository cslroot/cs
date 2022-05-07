cmake_minimum_required(VERSION 3.16.0)
set(PROJ_NAME cs.core)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(${PROJ_NAME} ${CS_LIB_TYPE})

target_compile_definitions(${PROJ_NAME} PRIVATE BUILD_CS_CORE_LIB)
target_compile_features(${PROJ_NAME} PRIVATE cxx_std_17)

file(GLOB_RECURSE CS_CORE_SRC CONFIGURE_DEPENDS 
  "*.cpp"
)
file(GLOB_RECURSE CS_CORE_HEADER CONFIGURE_DEPENDS 
  "*.h"
)

target_precompile_headers(${PROJ_NAME}
  PRIVATE
    <vector>
    <string>
    <array>
    <cassert>
    <unordered_map>
    <iostream>
    <locale>
    <algorithm>
    <codecvt>
)

target_sources(${PROJ_NAME} PRIVATE ${CS_CORE_SRC})
source_group("headers" FILES ${CS_CORE_HEADER})

find_package(Poco CONFIG REQUIRED Foundation Util)
target_link_libraries(${PROJ_NAME} PRIVATE Poco::Util)
target_link_libraries(${PROJ_NAME} PRIVATE cs.base)

target_include_directories(${PROJ_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${PROJ_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/cs/core)
