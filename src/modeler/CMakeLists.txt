cmake_minimum_required(VERSION 3.16.0)
project(cs.modeler)

add_compile_definitions(BUILD_CS_MODELER_LIB)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


if (CS_BUILD_SHARED_LIBS)
    add_library(cs.modeler SHARED)
else()
    add_library(cs.modeler STATIC)
endif()


file(GLOB_RECURSE CS_MODELER_SRC CONFIGURE_DEPENDS 
     "*.h"
     "*.cpp"
)

target_sources(cs.modeler
PRIVATE
${CS_MODELER_SRC}
)

target_link_libraries(cs.modeler cs.base)
target_link_libraries(cs.modeler cs.core)

target_include_directories(cs.modeler 
PUBLIC 
${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(cs.modeler 
PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR}/include/cs/modeler)