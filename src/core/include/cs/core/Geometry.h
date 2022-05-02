#pragma once

#include <cs/base_fwd.h>
#include <cs/core/Entity.h>
#include <cs/core/core_common.h>

namespace cs {
namespace core {
class Geometry : public Entity
{
public:
  DECL_CS_CORE Geometry() {}
  DECL_CS_CORE virtual ~Geometry() {}
};

class Geometry3d : public Geometry
{
public:
  DECL_CS_CORE Geometry3d() {}
  DECL_CS_CORE virtual ~Geometry3d() {}
};

class Point : public Geometry3d
{};
class Curve : public Geometry3d
{};
class Surface : public Geometry3d
{};
} // namespace core

} // namespace cs
