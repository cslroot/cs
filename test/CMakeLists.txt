set(PROJ_NAME cs.test)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

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


file(GLOB_RECURSE CS_TEST_SRC CONFIGURE_DEPENDS 
    # "*.h"
    "*.cpp"
)
add_executable(${PROJ_NAME} ${CS_TEST_SRC})

set_target_properties(${PROJ_NAME} PROPERTIES FOLDER test)
target_compile_features(${PROJ_NAME} PRIVATE cxx_std_17)

find_package(Threads REQUIRED)
find_package(GTest CONFIG REQUIRED)
include(GoogleTest)

target_link_libraries(${PROJ_NAME} PRIVATE cs.base)
target_link_libraries(${PROJ_NAME} PRIVATE cs.core)

if (MSVC)
    # on Windows, google test can not find test cases when `GTest::gmock` is exist
    target_link_libraries(${PROJ_NAME} PRIVATE GTest::gtest GTest::gmock_main GTest::gtest_main)
else()
    target_link_libraries(${PROJ_NAME} PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)
endif()

gtest_discover_tests(${PROJ_NAME}) # cmake v3.10+
# gtest_add_tests(TARGET cs.test)