cmake_minimum_required(VERSION 3.0.0)

add_subdirectory(simple)
add_subdirectory(simple_glfw)
if("${CMAKE_GENERATOR}" MATCHES "^Visual Studio.*")
add_subdirectory(wpf)
endif()
