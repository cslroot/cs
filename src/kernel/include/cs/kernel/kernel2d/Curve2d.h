#pragma once

#include <cs/kernel/common.h>
#include <cs/kernel/kernel2d/Geometry2d.h>

namespace cs {
namespace kernel {

class Curve2d : public Geometry2d
{
  using BASE_CLASS = Geometry2d;

public:
  DECL_CS_KERNEL Curve2d()
    : BASE_CLASS(EntityType::Curve)
  {}
  DECL_CS_KERNEL virtual ~Curve2d() {}

public:
};

} // namespace kernel
} // namespace cs
