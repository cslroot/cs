cmake_minimum_required(VERSION 3.16.0)
set(PROJ_NAME cs.examples.glfw)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")

add_executable(${PROJ_NAME})

file(GLOB_RECURSE ${PROJ_NAME}_SRC CONFIGURE_DEPENDS "*.cpp")
file(GLOB_RECURSE ${PROJ_NAME}_HEADER CONFIGURE_DEPENDS "*.h")
target_sources(${PROJ_NAME} PRIVATE ${${PROJ_NAME}_SRC})
target_sources(${PROJ_NAME} PRIVATE ${${PROJ_NAME}_HEADER})

set_target_properties(${PROJ_NAME} PROPERTIES FOLDER examples)
target_compile_features(${PROJ_NAME} PRIVATE cxx_std_17)

# add_custom_command(TARGET cs.examples.simple_glfw POST_BUILD
#  COMMAND copy /Y
#   "some-file.txt"
#   "$(TargetDir)some-file.txt"
# )

find_package(fmt CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glew CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(OpenGL)

target_link_libraries(${PROJ_NAME} PRIVATE fmt::fmt)
target_link_libraries(${PROJ_NAME} PRIVATE glfw)
target_link_libraries(${PROJ_NAME} PRIVATE GLEW::GLEW)
target_link_libraries(${PROJ_NAME} PRIVATE glm::glm)
target_link_libraries(${PROJ_NAME} PRIVATE OpenGL::GL)

target_link_libraries(${PROJ_NAME} PRIVATE cs.modeler)
target_link_libraries(${PROJ_NAME} PRIVATE cs.render)
target_link_libraries(${PROJ_NAME} PRIVATE cs.app)
