#include "CSMath.h"

#include <vector>

using namespace cs::math;

struct CSMath::Impl
{};

CSMath::CSMath(/* args */)
  : _impl(std::make_unique<Impl>())
{}

CSMath::~CSMath() {}
