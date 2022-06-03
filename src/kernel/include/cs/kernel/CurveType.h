#pragma once

#include <cs/core/CSObject.h>
#include <cs/kernel/common.h>
#include <cstdint>

namespace cs {
inline namespace kernel {

enum class CurveSubtype
{
  None = 0,

  Straight,
  Ellipse,
  InterpolateCurve,

  // 2d entity
  Curve2d,
  Line2d,
  Ray2d,
  Segment2d,
  Circle2d,
};

} // namespace kernel
} // namespace cs
