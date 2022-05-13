#pragma once

#if !defined(cs_math_EXPORTS)
// w/a without cmake
#if defined(CS_DLL)
#if defined(_MSC_VER)
#define EXPORT __declspec(dllexport)
#define IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
#define EXPORT __attribute__((visibility("default")))
#define IMPORT
#else
#define EXPORT
#define IMPORT
#pragma warning Unknown dynamic link import / export semantics.
#endif
#else
#define EXPORT
#define IMPORT
#endif
#if BUILD_CS_MATH_LIB
#define DECL_CS_MATH EXPORT
#else
#define DECL_CS_MATH IMPORT
#endif
#else
#include <cs_math_export.h>
#define DECL_CS_MATH CS_MATH_EXPORT
#endif
