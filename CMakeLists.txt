cmake_minimum_required(VERSION 3.20.0)

cmake_policy(SET CMP0054 NEW)

option(CS_BUILD_SHARED_LIBS "build as a shared library" ON)
option(CS_CODE_COVERAGE "enable code coverage" ON)

if (CS_BUILD_SHARED_LIBS)
    set(CS_LIB_TYPE SHARED)
    add_definitions(-DCS_DLL)
else()
    set(CS_LIB_TYPE STATIC)
endif()


# vcpkg
if(NOT DEFINED VCPKG_ROOT)
    set(VCPKG_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/third/vcpkg" CACHE STRING "vcpkg root directory")
endif()
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
endif()

# clang on ubuntu/WSLg: Could NOT find OpenGL (missing: OPENGL_opengl_LIBRARY OPENGL_glx_LIBRARY)  ??
set(OpenGL_GL_PREFERENCE LEGACY)


# same destinatin directory for dll
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)  # .exe, .dll with SHARED, .pdb
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)  # .dll, .so with MODULE
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/arc)  # .lib .exp, .a with STATIC

enable_language(CXX)
project(cs)

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

add_subdirectory(src)

# enable testing
enable_testing()
add_subdirectory(test)

# build example app
add_subdirectory(examples)
