cmake_minimum_required(VERSION 3.16.0)
project(cs.app)

add_compile_definitions(BUILD_CS_APP_LIB)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


if (CS_BUILD_SHARED_LIBS)
    add_library(cs.app SHARED)
else()
    add_library(cs.app STATIC)
endif()

file(GLOB_RECURSE CS_APP_SRC CONFIGURE_DEPENDS 
    #  "*.h"
     "*.cpp"
)

target_sources(cs.app
PRIVATE
${CS_APP_SRC}
)

target_link_libraries(cs.app PRIVATE cs.base)
target_link_libraries(cs.app PRIVATE cs.core)
target_link_libraries(cs.app PRIVATE cs.modeler)
target_link_libraries(cs.app PRIVATE cs.render)

target_include_directories(cs.app 
PUBLIC 
${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(cs.app 
PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR}/include/cs/app)