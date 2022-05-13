#pragma once

#include <cs/math/common.h>

#include <memory>

namespace cs {
namespace math {

class CSVec3;

class CSQuaternion
{
public:
  DECL_CS_MATH CSQuaternion();
  // DECL_CS_MATH explicit CSQuaternion(double w, double x, double y, double z);
  // DECL_CS_MATH explicit CSQuaternion(const CSVec3& eulerAngleXYZ);
  DECL_CS_MATH virtual ~CSQuaternion();

public:
private:
  struct Impl;
  std::unique_ptr<Impl> _impl;
};

} // namespace math
} // namespace cs
