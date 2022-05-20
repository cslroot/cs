#include "CSObject.h"

#include <cs/base.h>

using namespace cs::base;
using namespace cs::core;

struct CSObject::Impl
{
  cs::base::CSString _name;
};

CSObject::CSObject()
  : _impl(std::make_unique<Impl>())
{}

CSObject::~CSObject() = default;

const cs::base::CSString&
CSObject::Name() const
{
  return _impl->_name;
}

void
CSObject::SetName(const cs::base::CSString& name)
{
  _impl->_name = name;
}
