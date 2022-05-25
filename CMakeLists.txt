cmake_minimum_required(VERSION 3.20.0)

#-----
# build options
option(CS_ENABLE_BUILD_EXAMPLES "Build examples" ON)
option(CS_ENABLE_TESTING "enable testing" ON)
option(CS_ENABLE_PACKAGING "enable packaging" ON)

option(CS_BUILD_SHARED_LIBS "build as a shared library" ON)
option(CS_ENABLE_CODE_COVERAGE "enable code coverage. this value is effective if testing is ON" ON)

# vcpkg 
# RAMARK: define before project()
set(VCPKG_OVERLAY_TRIPLETS "${CMAKE_SOURCE_DIR}/tools/vcpkg/custom-triplets")
set(VCPKG_ROOT "${CMAKE_SOURCE_DIR}/third/vcpkg" CACHE STRING "vcpkg root directory")
if(CS_ENABLE_BUILD_TESTING)
  list(APPEND VCPKG_MANIFEST_FEATURES "testing")
endif()

message(STATUS "VCPKG_MANIFEST_FEATURES: ${VCPKG_MANIFEST_FEATURES}")
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

#-----
project(cs VERSION 0.1.0)

cmake_policy(SET CMP0054 NEW)

# set(CMAKE_PROJECT_VERSION_MAJOR 0)
# set(CMAKE_PROJECT_VERSION_MINOR 1)
# set(CMAKE_PROJECT_VERSION_PATCH 1)
set(CS_PROJECT_VERSION_STR "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
message(STATUS "CS_PROJECT_VERSION_STR: ${CS_PROJECT_VERSION_STR}")

set(PRODUCT_COMMENTS "Product comment")
set(PRODUCT_COMPANY_NAME "net.savethebunny.cs")
set(PRODUCT_FILE_DESCRIPTION "cs modules 2022.0.0")
set(PRODUCT_FILE_VERSION ${CS_PROJECT_VERSION_STR})
set(PRODUCT_INTERNAL_NAME "Internal name")
set(PRODUCT_COMPANY_COPYRIGHT "Copyright (C) net.savethebunny.cs. All rights reserved.")
set(PRODUCT_ORIGINAL_FILENAME "")
set(PRODUCT_NAME ${PROJECT_NAME})
set(PRODUCT_VERSION_STR ${CS_PROJECT_VERSION_STR})

if(WIN32)
configure_file(
    ${CMAKE_SOURCE_DIR}/src/version.rc.in
    ${CMAKE_BINARY_DIR}/version.rc
    @ONLY)
endif()

set_property(GLOBAL PROPERTY
    VERSION ${CS_PROJECT_VERSION_NUMBER})


add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

if (CS_BUILD_SHARED_LIBS)
    set(CS_LIB_TYPE SHARED)
    add_definitions(-DCS_DLL)
else()
    set(CS_LIB_TYPE STATIC)
endif()

SET(CMAKE_DEBUG_POSTFIX "d")


# clang on ubuntu/WSLg: Could NOT find OpenGL (missing: OPENGL_opengl_LIBRARY OPENGL_glx_LIBRARY)  ??
set(OpenGL_GL_PREFERENCE LEGACY)


# same destinatin directory for dll
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)  # .exe, .dll with SHARED, .pdb
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)  # .dll, .so with MODULE
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/arc)  # .lib .exp, .a with STATIC

enable_language(CXX)

# information
message(STATUS "CMAKE_GENERATOR: " ${CMAKE_GENERATOR})
message(STATUS "CMAKE_CXX_COMPILER_ID: " ${CMAKE_CXX_COMPILER_ID})


# ignore warning
# warning C4996: 'std::codecvt_utf8_utf16<wchar_t,1114111,(std::codecvt_mode)0>': warning STL4017: std::wbuffer_convert, std::wstring_convert, and the <codecvt> header (containing std::codecvt_mode, std::codecvt_utf8, std::codecvt_utf16, and std::codecvt_utf8_utf16) are deprecated in C++17. (The std::codecvt class template is NOT deprecated.) The C++ Standard doesn't provide equivalent non-deprecated functionality; consider using MultiByteToWideChar() and WideCharToMultiByte() from <Windows.h> instead. You can define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.
add_definitions(-D_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING)
add_definitions(-D_USE_MATH_DEFINES)

#  for MSVC (cl)
if(${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    message(STATUS "MSVC settings")
    add_definitions(-D_USE_MATH_DEFINES)
    add_definitions(-DNOMINMAX)
    add_definitions(-D_UNICODE -DUNICODE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zc:__cplusplus /MP /EHsc")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd /W3" )
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Ot /openmp /MD -DNDEBUG" )
endif()
# for VS Generator
if("${CMAKE_GENERATOR}" MATCHES "^Visual Studio.*")
    # prevent MinSizeRel and RelWithDebInfo for vcxproj
    set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "limited configs" FORCE)
    # suppress ZERO_CHECK project generation
    set(CMAKE_SUPPRESS_REGENERATION true)
    # enable to filter in project
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
    set_property(GLOBAL PROPERTY CMAKE_SKIP_PACKAGE_ALL_DEPENDENCY true)
    set_property(GLOBAL PROPERTY CMAKE_SKIP_INSTALL_ALL_DEPENDENCY true)
endif()

include(GenerateExportHeader)   # to create CS_XXX_EXPORT with generate_export_header

add_subdirectory(src)

# enable testing
if(CS_ENABLE_TESTING)
enable_testing()
add_subdirectory(test)
endif()

# build example app
if (CS_ENABLE_BUILD_EXAMPLES)
add_subdirectory(examples)
endif()

# build installer
if(CS_ENABLE_PACKAGING)
if(WIN32)
add_subdirectory(package)
endif()
endif()
