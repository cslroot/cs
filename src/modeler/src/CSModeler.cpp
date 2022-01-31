#include "CSModeler.h"

#include <cs/base.h>
#include <cs/core.h>

#include <vector>

using namespace cs::modeler;

struct CSModeler::Impl
{
    std::vector<cs::core::Body*> _bodies;
};

CSModeler::CSModeler(/* args */)
    : _impl(std::make_unique<Impl>())
{}

CSModeler::~CSModeler()
{}

cs::core::Body& CSModeler::CreateBox(const cs::base::CSVec3d& p1, const cs::base::CSVec3d& p2)
{
    cs::core::Body* pbody = CS_NEW cs::core::Body();
    _impl->_bodies.push_back(pbody);
    return *pbody;
}
