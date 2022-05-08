#include "CSModeler.h"

#include <cs/base.h>
#include <cs/core.h>
#include <cs/kernel.h>

#include <vector>

using namespace cs::modeler;

struct CSModeler::Impl
{
  std::vector<cs::kernel::Body*> _bodies;
};

CSModeler::CSModeler(/* args */)
  : _impl(std::make_unique<Impl>())
{}

CSModeler::~CSModeler() {}

cs::kernel::Body&
CSModeler::CreateBox(const cs::math::CSVec3d& p1, const cs::math::CSVec3d& p2)
{
  cs::kernel::Body* pbody = CS_NEW cs::kernel::Body();
  _impl->_bodies.push_back(pbody);
  return *pbody;
}
