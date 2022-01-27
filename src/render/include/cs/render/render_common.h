#pragma once

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

#if BUILD_CS_RENDER_LIB
#define DECL_CS_RENDER EXPORT
#else
#define DECL_CS_RENDER IMPORT
#endif
