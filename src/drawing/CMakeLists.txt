cmake_minimum_required(VERSION 3.16.0)
set(PROJ_NAME cs.drawing)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(${PROJ_NAME} ${CS_LIB_TYPE})

target_compile_definitions(${PROJ_NAME} PRIVATE BUILD_CS_DRAWING_LIB)
target_compile_features(${PROJ_NAME} PRIVATE cxx_std_17)

file(GLOB_RECURSE CS_DRAWING_SRC CONFIGURE_DEPENDS 
    #  "*.h"
     "*.cpp"
)
target_sources(${PROJ_NAME} PRIVATE ${CS_DRAWING_SRC})

target_link_libraries(${PROJ_NAME} PRIVATE cs.base)
target_link_libraries(${PROJ_NAME} PRIVATE cs.core)

target_include_directories(${PROJ_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${PROJ_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/cs/drawing)
