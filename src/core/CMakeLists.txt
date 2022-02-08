cmake_minimum_required(VERSION 3.16.0)

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

find_package(Poco CONFIG REQUIRED Foundation Util)

file(GLOB_RECURSE CS_CORE_SRC CONFIGURE_DEPENDS 
    "*.cpp"
)
file(GLOB_RECURSE CS_CORE_HEADER CONFIGURE_DEPENDS 
    "*.h"
)

target_sources(cs.core
PRIVATE
${CS_CORE_SRC}
)
source_group("headers" FILES ${CS_CORE_HEADER})

target_link_libraries(cs.core PRIVATE Poco::Util)
target_link_libraries(cs.core PRIVATE cs.base)

target_include_directories(cs.core 
PUBLIC 
${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(cs.core 
PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR}/include/cs/core)