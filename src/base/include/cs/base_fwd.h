#pragma once

#include <cstddef>

// wrap to use other allocation
#if !defined(CS_NEW)
#define CS_NEW new
#endif
#if !defined(CS_DELETE)
#define CS_DELETE delete
#endif

namespace cs {
inline namespace base {

class CSString;
class CSColor;
class CSPath;
class CSException;

} // namespace base
} // namespace cs
