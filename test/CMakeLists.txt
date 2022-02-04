cmake_minimum_required(VERSION 3.10)

project(cs.test)

set(CMAKE_CXX_STANDARD 14)  # GoogleTest requires at least C++11

# # ----- setup google test -----
# # https://google.github.io/googletest/quickstart-cmake.html#set-up-a-project
# # ./build/_deps
# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
# )
# if(WIN32)
#   # For Windows: Prevent overriding the parent project's compiler/linker settings
#   set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# endif()
# FetchContent_MakeAvailable(googletest)
# FetchContent_GetProperties(googletest)

# テスト有効化
enable_testing()

find_package(Threads REQUIRED)
find_package(GTest CONFIG REQUIRED)

message(STATUS "gtest_SOURCE_DIR = ${gtest_SOURCE_DIR}")
message(STATUS "gmock_SOURCE_DIR = ${gmock_SOURCE_DIR}")

# C++ソースから `#include <gmock/gmock.h>` の形でincludeするために cmakeのinclude_directoriesを指定
set(GTEST_INCLUDE_DIR ${gtest_SOURCE_DIR}/include)
set(GMOCK_INCLUDE_DIR ${gmock_SOURCE_DIR}/include)
include_directories(${GTEST_INCLUDE_DIR} ${GMOCK_INCLUDE_DIR})

include(GoogleTest)


enable_language(CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE CS_TEST_SRC CONFIGURE_DEPENDS 
  # "*.h"
  "*.cpp"
)

add_executable(cs.test
${CS_TEST_SRC}
)

target_link_libraries(cs.test PRIVATE cs.base)
target_link_libraries(cs.test PRIVATE cs.core)
# target_link_libraries(cs.test PRIVATE GTest::GTest GTest::Main)
# target_link_libraries(cs.test PRIVATE gtest_main)
target_link_libraries(cs.test PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)
# Add the test case use the old feature.
# gtest_discover_tests() cmake > v3.10
gtest_discover_tests(cs.test)
