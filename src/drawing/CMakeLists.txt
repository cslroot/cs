cmake_minimum_required(VERSION 3.16.0)

add_compile_definitions(BUILD_CS_DRAWING_LIB)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


if (CS_BUILD_SHARED_LIBS)
    add_library(cs.drawing SHARED)
else()
    add_library(cs.drawing STATIC)
endif()


file(GLOB_RECURSE CS_DRAWING_SRC CONFIGURE_DEPENDS 
    #  "*.h"
     "*.cpp"
)

target_sources(cs.drawing
PRIVATE
${CS_DRAWING_SRC}
)

target_link_libraries(cs.drawing PRIVATE cs.base)
target_link_libraries(cs.drawing PRIVATE cs.core)

target_include_directories(cs.drawing 
PUBLIC 
${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(cs.drawing 
PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR}/include/cs/drawing)