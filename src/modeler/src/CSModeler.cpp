#include "CSModeler.h"

#include <cs/base.h>
#include <cs/core.h>
#include <cs/kernel.h>

#include <memory>
#include <vector>

using namespace cs::modeler;

struct CSModeler::Impl
{
  std::vector<std::unique_ptr<cs::kernel::Body>> _bodies;
};

CSModeler::CSModeler(/* args */)
  : _impl(std::make_unique<Impl>())
{}

CSModeler::~CSModeler() = default;

cs::kernel::Body&
CSModeler::CreateBox(const cs::math::CSVec3d& p1, const cs::math::CSVec3d& p2)
{
  auto pbody = std::make_unique<cs::kernel::Body>();
  auto& ref = _impl->_bodies.emplace_back(std::move(pbody));
  return *ref;
}
