#include "Entity.h"
#include <cstdint>

using namespace cs::kernel;

namespace {
static int64_t id_counter = 0;
}

Entity::Entity(EntityType entType)
  : _id(++id_counter)
  , _entType(entType)
{}

Entity::~Entity() {}
