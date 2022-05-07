cmake_minimum_required(VERSION 3.16.0)
set(PROJ_NAME cs.examples.wpf.gl)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE CS_EX_WPF_SRC CONFIGURE_DEPENDS 
  "*.cpp"
)
add_executable(${PROJ_NAME} ${CS_EX_WPF_SRC})

set_target_properties(${PROJ_NAME} PROPERTIES FOLDER examples)
target_compile_features(${PROJ_NAME} PRIVATE cxx_std_17)

target_link_libraries(${PROJ_NAME} PRIVATE cs.base)
target_link_libraries(${PROJ_NAME} PRIVATE cs.core)
target_link_libraries(${PROJ_NAME} PRIVATE cs.modeler)
target_link_libraries(${PROJ_NAME} PRIVATE cs.render)
target_link_libraries(${PROJ_NAME} PRIVATE cs.app)
