enable_language(CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(cs.examples.wpf_gl
main.cpp
)

target_link_libraries(cs.examples.wpf_gl PRIVATE cs.base)
target_link_libraries(cs.examples.wpf_gl PRIVATE cs.core)
target_link_libraries(cs.examples.wpf_gl PRIVATE cs.modeler)
target_link_libraries(cs.examples.wpf_gl PRIVATE cs.render)
target_link_libraries(cs.examples.wpf_gl PRIVATE cs.app)
