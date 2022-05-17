cmake_minimum_required(VERSION 3.16.0)
set(PROJ_NAME cs.render)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(${PROJ_NAME} ${CS_LIB_TYPE})

generate_export_header(${PROJ_NAME} BASE_NAME cs_render)
target_include_directories(${PROJ_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

target_compile_definitions(${PROJ_NAME} PRIVATE BUILD_CS_RENDER_LIB)
target_compile_features(${PROJ_NAME} PRIVATE cxx_std_17)


# message(STATUS "OPENGL_FOUND: ${OPENGL_FOUND}")
# message(STATUS "OPENGL_XMESA_FOUND: ${OPENGL_XMESA_FOUND}")
# message(STATUS "OPENGL_GLU_FOUND: ${OPENGL_GLU_FOUND}")
# message(STATUS "OpenGL_OpenGL_FOUND: ${OpenGL_OpenGL_FOUND}")
# message(STATUS "OpenGL_GLX_FOUND: ${OpenGL_GLX_FOUND}")
# message(STATUS "OpenGL_EGL_FOUND: ${OpenGL_EGL_FOUND}")
# message(STATUS "OPENGL_INCLUDE_DIR: ${OPENGL_INCLUDE_DIR}")
# message(STATUS "OPENGL_EGL_INCLUDE_DIRS: ${OPENGL_EGL_INCLUDE_DIRS}")
# message(STATUS "OPENGL_LIBRARIES: ${OPENGL_LIBRARIES}")

file(GLOB_RECURSE ${PROJ_NAME}_SRC CONFIGURE_DEPENDS "*.cpp")
file(GLOB_RECURSE ${PROJ_NAME}_HEADER CONFIGURE_DEPENDS "*.h")
target_sources(${PROJ_NAME} PRIVATE ${${PROJ_NAME}_SRC})
target_sources(${PROJ_NAME} PRIVATE ${${PROJ_NAME}_HEADER})
if(WIN32)
target_sources(${PROJ_NAME} PRIVATE ${CMAKE_BINARY_DIR}/version.rc)
endif()

find_package(glfw3 CONFIG REQUIRED)
find_package(glew CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(OpenGL)
target_link_libraries(${PROJ_NAME} PRIVATE glfw)
target_link_libraries(${PROJ_NAME} PRIVATE GLEW::GLEW)
target_link_libraries(${PROJ_NAME} PRIVATE glm::glm)

target_link_libraries(${PROJ_NAME} PUBLIC cs.kernel)

target_include_directories(${PROJ_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${PROJ_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/cs/render)
