cmake_minimum_required(VERSION 3.16.0)
project(cs.render)

add_compile_definitions(BUILD_CS_RENDER_LIB)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


if (CS_BUILD_SHARED_LIBS)
    add_library(cs.render SHARED)
else()
    add_library(cs.render STATIC)
endif()


file(GLOB_RECURSE CS_RENDER_SRC CONFIGURE_DEPENDS 
    #  "*.h"
     "*.cpp"
)

target_sources(cs.render
PRIVATE
${CS_RENDER_SRC}
)

target_link_libraries(cs.render cs.base)
target_link_libraries(cs.render cs.core)

target_include_directories(cs.render 
PUBLIC 
${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(cs.render 
PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR}/include/cs/render)