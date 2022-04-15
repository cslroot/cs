cmake_minimum_required(VERSION 3.16.0)

add_compile_definitions(BUILD_CS_RENDER_LIB)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(glfw3 CONFIG REQUIRED)
find_package(glew CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

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

target_link_libraries(cs.render PRIVATE glfw)
target_link_libraries(cs.render PRIVATE GLEW::GLEW)
target_link_libraries(cs.render PRIVATE glm::glm)

target_link_libraries(cs.render PRIVATE cs.base)
target_link_libraries(cs.render PRIVATE cs.core)

target_include_directories(cs.render 
PUBLIC 
${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(cs.render 
PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR}/include/cs/render)