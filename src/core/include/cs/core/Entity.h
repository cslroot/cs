#pragma once

#include <cs/core/CSObject.h>
#include <cs/core/core_common.h>
#include <cstdint>

namespace cs {
namespace core {
enum class EntityType
{
  None,
  Point,
  Surface,
  Shell,
  Vertex,
  Edge,
  Body,
};

class Entity : public CSObject
{
public:
  DECL_CS_CORE Entity();
  DECL_CS_CORE virtual ~Entity();

private:
  int64_t _id;
  EntityType _entType;
};
} // namespace core

} // namespace cs
