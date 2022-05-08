#pragma once

#include <cs/base_fwd.h>
#include <cs/core_fwd.h>

#include <cs/kernel/common.h>
#include <cs/kernel/kernel2d/Curve2d.h>

#include <memory>

namespace cs {
namespace kernel {

class Segment2d : public Curve2d
{
public:
  DECL_CS_KERNEL Segment2d();
  DECL_CS_KERNEL Segment2d(const cs::base::CSVec2d& p1,
                           const cs::base::CSVec2d& p2);
  DECL_CS_KERNEL virtual ~Segment2d();

  DECL_CS_KERNEL const cs::base::CSVec2d& StartPoint() const;
  DECL_CS_KERNEL const cs::base::CSVec2d& EndPoint() const;

  DECL_CS_KERNEL virtual std::shared_ptr<cs::core::CSBufferObject>
  GenerateBuffer() const override;

private:
  struct Impl;
  std::unique_ptr<Impl> _impl;
};

} // namespace kernel
} // namespace cs
