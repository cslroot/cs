cmake_minimum_required(VERSION 3.16.0)
set(PROJ_NAME cs.examples.simple)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE CS_EX_SIMPLE_SRC CONFIGURE_DEPENDS 
  "*.cpp"
)
add_executable(${PROJ_NAME} ${CS_EX_SIMPLE_SRC})

set_target_properties(${PROJ_NAME} PROPERTIES FOLDER examples)
target_compile_features(${PROJ_NAME} PRIVATE cxx_std_17)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(${PROJ_NAME} PRIVATE fmt::fmt)

target_link_libraries(${PROJ_NAME} PRIVATE cs.app)
