#include "Modeler.h"

#include <cs/base.h>
#include <cs/core.h>

#include <vector>

using namespace cs::modeler;

struct Modeler::Impl
{
    std::vector<cs::core::Body*> _bodies;
};

Modeler::Modeler(/* args */)
    : _impl(std::make_unique<Impl>())
{}

Modeler::~Modeler()
{}

cs::core::Body& Modeler::CreateBox(const cs::base::CSVec3d& p1, const cs::base::CSVec3d& p2)
{
    cs::core::Body* pbody = CS_NEW cs::core::Body();
    _impl->_bodies.push_back(pbody);
    return *pbody;
}
