#pragma once

#include <cs/base_fwd.h>
#include <cs/core/CSObject.h>
#include <cs/core/common.h>

#include <memory>
#include <vector>

namespace cs {
inline namespace core {

class CSBufferObject : public CSObject
{
public:
  using Ptr = std::shared_ptr<CSBufferObject>;

  DECL_CS_CORE CSBufferObject();
  DECL_CS_CORE ~CSBufferObject() override;

public:
  std::vector<double> _points;

private:
  struct Impl;
  std::unique_ptr<Impl> _impl;
};

} // namespace core
} // namespace cs
