#pragma once

#include <cs/base.h>
#include <cs/core.h>
#include <cs/kernel/common.h>

#include <memory>

namespace cs {
inline namespace kernel {

class CSKernel
{
public:
  DECL_CS_KERNEL CSKernel();
  DECL_CS_KERNEL virtual ~CSKernel();

public:
  DECL_CS_KERNEL bool IsInitialized() const;

private:
  struct Impl;
  std::unique_ptr<Impl> _impl;
};

} // namespace kernel
} // namespace cs
