project(cs.examples.simple_glfw)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")
set(OpenGL_GL_PREFERENCE LEGACY)

find_package(fmt CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glew CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

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
