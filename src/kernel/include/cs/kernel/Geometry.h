#pragma once

#include <cs/base_fwd.h>
#include <cs/kernel/Entity.h>
#include <cs/kernel/common.h>

namespace cs {
namespace kernel {

class Geometry : public Entity
{
public:
  DECL_CS_KERNEL Geometry(EntityType entType)
    : Entity(entType)
  {}
  DECL_CS_KERNEL virtual ~Geometry() {}
};

class Geometry3d : public Geometry
{
  using BASE_CLASS = Geometry;

public:
  DECL_CS_KERNEL Geometry3d(EntityType entType)
    : BASE_CLASS(entType)
  {}
  DECL_CS_KERNEL virtual ~Geometry3d() {}
};

class Point : public Geometry3d
{
  using BASE_CLASS = Geometry3d;

public:
  DECL_CS_KERNEL Point()
    : BASE_CLASS(EntityType::Point)
  {}
};
class Curve : public Geometry3d
{
  using BASE_CLASS = Geometry3d;

public:
  DECL_CS_KERNEL Curve()
    : BASE_CLASS(EntityType::Curve)
  {}
};
class Surface : public Geometry3d
{
  using BASE_CLASS = Geometry3d;

public:
  DECL_CS_KERNEL Surface()
    : BASE_CLASS(EntityType::Surface)
  {}
};

} // namespace kernel
} // namespace cs
