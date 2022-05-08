#pragma once

#include <cs/base_fwd.h>
#include <cs/core/core_common.h>
#include <memory>

namespace cs {
namespace core {

class UUID
{
public:
  DECL_CS_CORE UUID();
  DECL_CS_CORE virtual ~UUID();

public:
  DECL_CS_CORE cs::base::CSString ToString() const;

private:
  struct Impl;
  std::unique_ptr<Impl> _impl;
};

} // namespace core
} // namespace cs