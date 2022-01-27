cmake_minimum_required(VERSION 3.10)

project(cs.test)

enable_testing()

find_package(GTest REQUIRED)
include(GoogleTest)


enable_language(CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(cs.test
# main.cpp
test_sample.cpp
)

target_link_libraries(cs.test PRIVATE cs.base)
target_link_libraries(cs.test PRIVATE cs.core)
target_link_libraries(cs.test PRIVATE GTest::GTest GTest::Main)

# Add the test case use the old feature.
# gtest_discover_tests() cmake > v3.10
gtest_discover_tests(cs.test)
