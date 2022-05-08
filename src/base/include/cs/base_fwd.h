#pragma once

#include <cstddef>

namespace cs {
namespace base {

class CSString;
class CSColor;

template<typename T, size_t N>
class CSVector;

using CSVec2d = CSVector<double, 2>;
using CSVec3d = CSVector<double, 3>;

} // namespace base
} // namespace cs
