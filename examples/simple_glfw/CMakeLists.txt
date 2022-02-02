project(cs.examples.simple_glfw)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

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

target_link_libraries(cs.examples.simple_glfw PRIVATE fmt::fmt)
target_link_libraries(cs.examples.simple_glfw PRIVATE glfw)
target_link_libraries(cs.examples.simple_glfw PRIVATE GLEW::GLEW)
target_link_libraries(cs.examples.simple_glfw PRIVATE glm::glm)

target_link_libraries(cs.examples.simple_glfw PRIVATE cs.base)
target_link_libraries(cs.examples.simple_glfw PRIVATE cs.core)
target_link_libraries(cs.examples.simple_glfw PRIVATE cs.modeler)
target_link_libraries(cs.examples.simple_glfw PRIVATE cs.render)
target_link_libraries(cs.examples.simple_glfw PRIVATE cs.app)
