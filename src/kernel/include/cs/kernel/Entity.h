#pragma once

#include <cs/core/CSObject.h>
#include <cs/kernel/common.h>
#include <cstdint>

namespace cs {
namespace kernel {

enum class EntityType
{
  None = 0,

  Point,
  Curve,
  Surface,

  Vertex,
  CoEdge,
  Edge,
  Loop,
  Wire,
  Face,
  Shell,
  Lump,
  Body,
  Last = Body
};

/**
 * @brief Entity is atomic object of kernel
 *
 */
class Entity : public cs::core::CSObject
{
public:
  DECL_CS_KERNEL Entity(EntityType entType);
  DECL_CS_KERNEL ~Entity() override;

public:
  DECL_CS_KERNEL EntityType Type() const;
  DECL_CS_KERNEL int SubType() const;

private:
  int64_t _id;
  EntityType _entType;
  int _entSubType;
};

} // namespace kernel
} // namespace cs
