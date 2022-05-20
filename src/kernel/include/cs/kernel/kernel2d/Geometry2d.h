#pragma once

#include <cs/kernel/Geometry.h>
#include <cs/kernel/common.h>

#include <cs/kernel/kernel2d/Geometry2dProperty.h>

#include <memory>

namespace cs {
namespace kernel {

class Geometry2d : public Geometry
{
  using BASE_CLASS = Geometry;

public:
  DECL_CS_KERNEL explicit Geometry2d(EntityType entType)
    : BASE_CLASS(entType)
    , _props(std::make_unique<Geometry2dProperty>())
  {}
  DECL_CS_KERNEL ~Geometry2d() override = default;

  DECL_CS_KERNEL Geometry2dProperty& Property() const { return *_props; }

private:
  std::unique_ptr<Geometry2dProperty> _props;
};

} // namespace kernel
} // namespace cs
