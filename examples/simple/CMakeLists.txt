cmake_minimum_required(VERSION 3.16.0)
set(PROJ_NAME cs.examples.simple)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_executable(${PROJ_NAME})

file(GLOB_RECURSE ${PROJ_NAME}_SRC CONFIGURE_DEPENDS "*.cpp")
file(GLOB_RECURSE ${PROJ_NAME}_HEADER CONFIGURE_DEPENDS "*.h")
target_sources(${PROJ_NAME} PRIVATE ${${PROJ_NAME}_SRC})
target_sources(${PROJ_NAME} PRIVATE ${${PROJ_NAME}_HEADER})

set_target_properties(${PROJ_NAME} PROPERTIES FOLDER examples)
target_compile_features(${PROJ_NAME} PRIVATE cxx_std_17)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(${PROJ_NAME} PRIVATE fmt::fmt)

target_link_libraries(${PROJ_NAME} PRIVATE cs.app)
