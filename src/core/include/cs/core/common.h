#pragma once

#if !defined(cs_core_EXPORTS)
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
#if BUILD_CS_CORE_LIB
#define DECL_CS_CORE EXPORT
#else
#define DECL_CS_CORE IMPORT
#endif
#else
#include <cs_core_export.h>
#define DECL_CS_CORE CS_CORE_EXPORT
#endif
