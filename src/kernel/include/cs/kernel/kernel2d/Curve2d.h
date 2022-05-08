#pragma once

#include <cs/kernel/common.h>
#include <cs/kernel/kernel2d/Geometry2d.h>

namespace cs {
namespace kernel {

class Curve2d : public Geometry2d
{
public:
  DECL_CS_KERNEL Curve2d() {}
  DECL_CS_KERNEL virtual ~Curve2d() {}
};

} // namespace kernel
} // namespace cs
