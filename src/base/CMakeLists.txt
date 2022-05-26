cmake_minimum_required(VERSION 3.16.0)
set(PROJ_NAME cs.base)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(${PROJ_NAME} ${CS_LIB_TYPE})

generate_export_header(${PROJ_NAME} BASE_NAME cs_base)
target_include_directories(${PROJ_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

file(GLOB_RECURSE ${PROJ_NAME}_SRC CONFIGURE_DEPENDS "*.cpp")
file(GLOB_RECURSE ${PROJ_NAME}_HEADER CONFIGURE_DEPENDS "*.h")
target_sources(${PROJ_NAME} PRIVATE ${${PROJ_NAME}_SRC})
target_sources(${PROJ_NAME} PRIVATE ${${PROJ_NAME}_HEADER})
# source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX "Header Files" FILES ${${PROJ_NAME}_HEADER})
if(WIN32)
target_sources(${PROJ_NAME} PRIVATE ${CMAKE_BINARY_DIR}/version.rc)
endif()


target_compile_definitions(${PROJ_NAME} PRIVATE BUILD_CS_BASE_LIB)
target_compile_features(${PROJ_NAME} PRIVATE cxx_std_17)

target_precompile_headers(${PROJ_NAME}
  PRIVATE
    <algorithm>
    <array>
    <cassert>
    <codecvt>
    <cstddef>
    <iostream>
    <iomanip>
    <locale>
    <string>
    <unordered_map>
    <vector>
)

target_include_directories(${PROJ_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${PROJ_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/cs/base)
