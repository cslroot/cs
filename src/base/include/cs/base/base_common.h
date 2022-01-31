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

#if CS_BASE_EXPORT
#define DECL_CS_BASE EXPORT
#else
#define DECL_CS_BASE IMPORT
#endif

#define CS_NEW new
#define CS_DELETE delete
