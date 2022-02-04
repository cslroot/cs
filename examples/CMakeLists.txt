cmake_minimum_required(VERSION 3.0.0)

add_subdirectory(simple)
IF (WIN32)
add_subdirectory(simple_glfw)
add_subdirectory(wpf_gl)
ENDIF()
