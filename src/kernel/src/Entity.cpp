#include "Entity.h"
#include <cstdint>

using namespace cs::kernel;

namespace {

int64_t id_counter = 0;

} // namespace

Entity::Entity(EntityType entType)
  : _id(++id_counter)
  , _entType(entType)
  , _entSubType(0)
{}

Entity::~Entity() = default;

EntityType
Entity::Type() const
{
  return _entType;
}
int
Entity::SubType() const
{
  return _entSubType;
}
