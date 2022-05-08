cmake_minimum_required(VERSION 3.0.0)

option(CS_BUILD_SHARED_LIBS "build as a shared library" ON)
if (CS_BUILD_SHARED_LIBS)
    set(CS_LIB_TYPE SHARED)
else()
    set(CS_LIB_TYPE STATIC)
endif()

#  for VS
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/Zc:__cplusplus>")

# vcpkg
if(NOT DEFINED VCPKG_ROOT)
    set(VCPKG_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/third/vcpkg" CACHE STRING "vcpkg root directory")
endif()
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

# clang on ubuntu/WSLg: Could NOT find OpenGL (missing: OPENGL_opengl_LIBRARY OPENGL_glx_LIBRARY)  ??
set(OpenGL_GL_PREFERENCE LEGACY)


# same destinatin directory for dll
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# ignore warning
# warning C4996: 'std::codecvt_utf8_utf16<wchar_t,1114111,(std::codecvt_mode)0>': warning STL4017: std::wbuffer_convert, std::wstring_convert, and the <codecvt> header (containing std::codecvt_mode, std::codecvt_utf8, std::codecvt_utf16, and std::codecvt_utf8_utf16) are deprecated in C++17. (The std::codecvt class template is NOT deprecated.) The C++ Standard doesn't provide equivalent non-deprecated functionality; consider using MultiByteToWideChar() and WideCharToMultiByte() from <Windows.h> instead. You can define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.
add_definitions(-D_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING)
add_definitions(-D_USE_MATH_DEFINES)
if(MSVC)
    message(STATUS "MSVC settings")
    add_definitions(-D_USE_MATH_DEFINES)
    add_definitions(-DNOMINMAX)
    add_definitions(-D_UNICODE -DUNICODE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP /EHsc")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd /W3" )
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Ot /openmp /MD -DNDEBUG" )
    # enable to filter in project
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
    # suppress ZERO_CHECK project generation
    set(CMAKE_SUPPRESS_REGENERATION true)
    # prevent MinSizeRel and RelWithDebInfo for vcxproj
    set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "limited configs" FORCE)
    set_property(GLOBAL PROPERTY CMAKE_SKIP_PACKAGE_ALL_DEPENDENCY true)
    set_property(GLOBAL PROPERTY CMAKE_SKIP_INSTALL_ALL_DEPENDENCY true)
endif()

enable_language(CXX)
project(cs)

add_subdirectory(src)

# enable testing
enable_testing()
add_subdirectory(test)

# build example app
add_subdirectory(examples)
