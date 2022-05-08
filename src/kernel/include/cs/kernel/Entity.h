#pragma once

#include <cs/core/CSObject.h>
#include <cs/kernel/common.h>
#include <cstdint>

namespace cs {
namespace kernel {

enum class EntityType
{
  None,
  Point,
  Surface,
  Shell,
  Vertex,
  Edge,
  Body,

  // 2d entity
  Segment2d,
};

/**
 * @brief Entity is atomic object of kernel
 *
 */
class Entity : public cs::core::CSObject
{
public:
  DECL_CS_KERNEL Entity();
  DECL_CS_KERNEL virtual ~Entity();

private:
  int64_t _id;
  EntityType _entType;
};

} // namespace kernel
} // namespace cs
