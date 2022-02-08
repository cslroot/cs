#include "entity.h"
#include <cstdint>

using namespace cs::core;

namespace {
    static int64_t id_counter = 0;
}

Entity::Entity()
    : _id(++id_counter)
    , _entType(EntityType::None)
{}
Entity::~Entity()
{}
