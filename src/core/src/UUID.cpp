#include "UUID.h"

#include <cs/base/CSString.h>

#include <Poco/UUID.h>
#include <Poco/UUIDGenerator.h>

using namespace cs::core;

namespace {}

struct UUID::Impl
{
  Poco::UUID _uuid;
};

UUID::UUID()
  : _impl(std::make_unique<Impl>())
{
  Poco::UUIDGenerator uuidgen;
  _impl->_uuid = uuidgen.create();
}

UUID::~UUID() = default;

cs::base::CSString
UUID::ToString() const
{
  return _impl->_uuid.toString();
}
