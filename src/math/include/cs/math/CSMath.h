#pragma once

#include <cs/math/common.h>

#include <cmath>
#include <memory>

namespace cs {
namespace math {

class CSMath
{
public:
  static constexpr double CS_PI = 3.1415926535897932384626433832795028841971;
  static constexpr double Tau = 6.2831853071795862;
  static constexpr double CS_PI_2 = CS_PI / 2.0;

  static constexpr double E = 2.7182818284590451;

  static constexpr double DEGRA = CS_PI / 180.0;
  static constexpr double RADEG = 180.0 / CS_PI;

public:
  DECL_CS_MATH CSMath();
  DECL_CS_MATH virtual ~CSMath();

public:
  static inline double Sqrt(double d) { return std::sqrt(d); }
  static inline float Sqrt(float d) { return std::sqrt(d); }

private:
  struct Impl;
  std::unique_ptr<Impl> _impl;
};

} // namespace math
} // namespace cs
