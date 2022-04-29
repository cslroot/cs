enable_language(CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")

find_package(fmt CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glew CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(OpenGL)


# message(STATUS "OPENGL_FOUND: ${OPENGL_FOUND}")
# message(STATUS "OPENGL_XMESA_FOUND: ${OPENGL_XMESA_FOUND}")
# message(STATUS "OPENGL_GLU_FOUND: ${OPENGL_GLU_FOUND}")
# message(STATUS "OpenGL_OpenGL_FOUND: ${OpenGL_OpenGL_FOUND}")
# message(STATUS "OpenGL_GLX_FOUND: ${OpenGL_GLX_FOUND}")
# message(STATUS "OpenGL_EGL_FOUND: ${OpenGL_EGL_FOUND}")
# message(STATUS "OPENGL_INCLUDE_DIR: ${OPENGL_INCLUDE_DIR}")
# message(STATUS "OPENGL_EGL_INCLUDE_DIRS: ${OPENGL_EGL_INCLUDE_DIRS}")
# message(STATUS "OPENGL_LIBRARIES: ${OPENGL_LIBRARIES}")


file(GLOB_RECURSE CS_EX_GLFW_SRC CONFIGURE_DEPENDS 
     # "*.h"
     "*.cpp"
)

add_executable(cs.examples.simple_glfw
${CS_EX_GLFW_SRC}
)

# add_custom_command(TARGET cs.examples.simple_glfw POST_BUILD
#  COMMAND copy /Y
#   "some-file.txt"
#   "$(TargetDir)some-file.txt"
# )

target_link_libraries(cs.examples.simple_glfw PRIVATE fmt::fmt)
target_link_libraries(cs.examples.simple_glfw PRIVATE glfw)
target_link_libraries(cs.examples.simple_glfw PRIVATE GLEW::GLEW)
target_link_libraries(cs.examples.simple_glfw PRIVATE glm::glm)
target_link_libraries(cs.examples.simple_glfw PRIVATE OpenGL::GL)

target_link_libraries(cs.examples.simple_glfw PRIVATE cs.base)
target_link_libraries(cs.examples.simple_glfw PRIVATE cs.core)
target_link_libraries(cs.examples.simple_glfw PRIVATE cs.modeler)
target_link_libraries(cs.examples.simple_glfw PRIVATE cs.render)
target_link_libraries(cs.examples.simple_glfw PRIVATE cs.app)
