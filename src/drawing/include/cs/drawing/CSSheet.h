#pragma once

#include <cs/base.h>
#include <cs/core.h>
#include <cs/drawing/common.h>

#include <memory>

namespace cs {
namespace drawing {

class CSSheet
{
public:
  DECL_CS_DRAWING CSSheet();
  DECL_CS_DRAWING virtual ~CSSheet();

public:
private:
  struct Impl;
  std::unique_ptr<Impl> _impl;
};

} // namespace drawing
} // namespace cs
