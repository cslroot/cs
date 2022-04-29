
enable_language(CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(cs.examples.simple
main.cpp
)

target_link_libraries(cs.examples.simple PRIVATE cs.base)
target_link_libraries(cs.examples.simple PRIVATE cs.core)
target_link_libraries(cs.examples.simple PRIVATE cs.modeler)
target_link_libraries(cs.examples.simple PRIVATE cs.render)
target_link_libraries(cs.examples.simple PRIVATE cs.app)
