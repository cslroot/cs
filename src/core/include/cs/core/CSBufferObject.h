#pragma once

#include <cs/base_fwd.h>
#include <cs/core/CSObject.h>
#include <cs/core/core_common.h>

#include <memory>
#include <vector>

namespace cs {
namespace core {

class CSBufferObject : public CSObject
{
public:
  DECL_CS_CORE CSBufferObject();
  DECL_CS_CORE virtual ~CSBufferObject();

public:
  std::vector<double> _points;

private:
  struct Impl;
  std::unique_ptr<Impl> _impl;
};

} // namespace core
} // namespace cs
