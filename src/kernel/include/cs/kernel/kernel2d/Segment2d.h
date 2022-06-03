#pragma once

#include <cs/base_fwd.h>
#include <cs/core_fwd.h>
#include <cs/math_fwd.h>

#include <cs/kernel/common.h>
#include <cs/kernel/kernel2d/Curve2d.h>

#include <memory>

namespace cs {
inline namespace kernel {

class Segment2d : public Curve2d
{
  using BASE_CLASS = Curve2d;

public:
  DECL_CS_KERNEL Segment2d();
  DECL_CS_KERNEL Segment2d(const cs::math::CSVec2d& p1,
                           const cs::math::CSVec2d& p2);
  DECL_CS_KERNEL ~Segment2d() override;

public:
  DECL_CS_KERNEL const cs::math::CSVec2d& StartPoint() const;
  DECL_CS_KERNEL const cs::math::CSVec2d& EndPoint() const;

  // TODO: create tessalation data from out of geometry class
  DECL_CS_KERNEL std::shared_ptr<cs::core::CSBufferObject> GenerateBuffer()
    const override;

private:
  struct Impl;
  std::unique_ptr<Impl> _impl;
};

} // namespace kernel
} // namespace cs
