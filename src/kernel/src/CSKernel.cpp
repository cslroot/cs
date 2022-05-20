#include "CSKernel.h"

#include <cs/base.h>
#include <cs/core.h>

#include <vector>

using namespace cs::kernel;

struct CSKernel::Impl
{
  bool _initialized = false;
};

CSKernel::CSKernel(/* args */)
  : _impl(std::make_unique<Impl>())
{}

CSKernel::~CSKernel() = default;

bool
CSKernel::IsInitialized() const
{
  return _impl->_initialized;
}
