#pragma once

#include <cs/math/common.h>

#include <memory>

namespace cs {
namespace math {

class CSMath
{
public:
  static constexpr double CS_PI = 3.1415926535897932384626433832795028841971;
  static constexpr double CS_PI_x2 = CS_PI * 2.0;
  static constexpr double CS_PI_2 = CS_PI / 2.0;
  static constexpr double DEGRA = CS_PI / 180.0;
  static constexpr double RADEG = 180.0 / CS_PI;

public:
  DECL_CS_MATH CSMath();
  DECL_CS_MATH virtual ~CSMath();

public:
private:
  struct Impl;
  std::unique_ptr<Impl> _impl;
};

} // namespace math
} // namespace cs
