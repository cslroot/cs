#pragma once

#include <cs/base.h>
#include <cs/core.h>
#include <cs/kernel_fwd.h>
#include <cs/modeler/modeler_common.h>

#include <memory>

namespace cs {
namespace modeler {
class CSModeler
{
public:
  DECL_CS_MODELER CSModeler();
  DECL_CS_MODELER virtual ~CSModeler();

public:
  DECL_CS_MODELER cs::kernel::Body& CreateBox(const cs::base::CSVec3d& p1,
                                              const cs::base::CSVec3d& p2);

private:
  struct Impl;
  std::unique_ptr<Impl> _impl;
};

} // namespace modeler

} // namespace cs
