#pragma once

#include <cs/kernel/Geometry.h>
#include <cs/kernel/common.h>

#include <memory>

namespace cs {
namespace kernel {

class Geometry2d : public Geometry
{
  using BASE_CLASS = Geometry;

public:
  DECL_CS_KERNEL Geometry2d(EntityType entType)
    : BASE_CLASS(entType)
  {}
  DECL_CS_KERNEL virtual ~Geometry2d() {}
};

} // namespace core
} // namespace cs
