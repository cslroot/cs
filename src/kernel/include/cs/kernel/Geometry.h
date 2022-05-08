#pragma once

#include <cs/base_fwd.h>
#include <cs/kernel/Entity.h>
#include <cs/kernel/common.h>

namespace cs {
namespace kernel {

class Geometry : public Entity
{
public:
  DECL_CS_KERNEL Geometry() {}
  DECL_CS_KERNEL virtual ~Geometry() {}
};

class Geometry3d : public Geometry
{
public:
  DECL_CS_KERNEL Geometry3d() {}
  DECL_CS_KERNEL virtual ~Geometry3d() {}
};

class Point : public Geometry3d
{};
class Curve : public Geometry3d
{};
class Surface : public Geometry3d
{};

} // namespace kernel
} // namespace cs
