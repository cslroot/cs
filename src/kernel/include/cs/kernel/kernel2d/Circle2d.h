#pragma once

#include <cs/base_fwd.h>
#include <cs/core_fwd.h>
#include <cs/math_fwd.h>

#include <cs/kernel/common.h>
#include <cs/kernel/kernel2d/Curve2d.h>

#include <memory>

namespace cs {
namespace kernel {

class Circle2d : public Curve2d
{
public:
  DECL_CS_KERNEL Circle2d();
  DECL_CS_KERNEL Circle2d(const cs::math::CSVec2d& center, double radius);
  DECL_CS_KERNEL virtual ~Circle2d();

public:
  DECL_CS_KERNEL const cs::math::CSVec2d& Center() const;
  DECL_CS_KERNEL const double& Radius() const;
  DECL_CS_KERNEL void SetCenter(const cs::math::CSVec2d& center);
  DECL_CS_KERNEL void SetRadius(double radius) const;

  // TODO: create tessalation data from out of geometry class
  DECL_CS_KERNEL virtual std::shared_ptr<cs::core::CSBufferObject>
  GenerateBuffer() const override;

private:
  struct Impl;
  std::unique_ptr<Impl> _impl;
};

} // namespace kernel
} // namespace cs
