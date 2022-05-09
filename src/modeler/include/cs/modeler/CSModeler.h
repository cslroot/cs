#pragma once

#include <cs/kernel_fwd.h>
#include <cs/math_fwd.h>
#include <cs/modeler/common.h>

#include <memory>

namespace cs {
namespace modeler {

class CSModeler
{
public:
  DECL_CS_MODELER CSModeler();
  DECL_CS_MODELER virtual ~CSModeler();

public:
  DECL_CS_MODELER cs::kernel::Body& CreateBox(const cs::math::CSVec3d& p1,
                                              const cs::math::CSVec3d& p2);

private:
  struct Impl;
  std::unique_ptr<Impl> _impl;
};

} // namespace modeler
} // namespace cs
