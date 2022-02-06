cmake_minimum_required(VERSION 3.0.0)


option(CS_BUILD_SHARED_LIBS "build as a shared library" ON)

#  for VS
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/Zc:__cplusplus>")

# vcpkg
if(NOT DEFINED VCPKG_ROOT)
    set(VCPKG_ROOT "${CMAKE_SOURCE_DIR}/third/vcpkg" CACHE STRING "vcpkg root directory")
endif()
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
message(STATUS "----- ${CMAKE_TOOLCHAIN_FILE}")

# same destinatin directory for dll
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# prevent unused 
if(MSVC)
    add_definitions(-D_USE_MATH_DEFINES)
    add_definitions(-DNOMINMAX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP ")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}  /MDd" )
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Ot /openmp /MD -DNDEBUG" )
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
    set(CMAKE_SUPPRESS_REGENERATION true)
    set_property(GLOBAL PROPERTY CMAKE_SKIP_PACKAGE_ALL_DEPENDENCY true)
    set_property(GLOBAL PROPERTY CMAKE_SKIP_INSTALL_ALL_DEPENDENCY true)
endif()

project(cs)
enable_testing()

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(examples)
