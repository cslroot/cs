#include "CSSheet.h"

#include <cs/base.h>
#include <cs/core.h>
#include <cs/kernel.h>

#include <vector>

using namespace cs::drawing;

struct CSSheet::Impl
{
  std::vector<cs::kernel::Body*> _bodies;
};

CSSheet::CSSheet(/* args */)
  : _impl(std::make_unique<Impl>())
{}

CSSheet::~CSSheet() {}
