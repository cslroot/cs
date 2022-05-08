#pragma once

#include <cs/kernel/Entity.h>
#include <cs/kernel/common.h>

namespace cs {
namespace kernel {

enum class TopologyType
{
  INVALID,
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

class Topology : public Entity
{
public:
  DECL_CS_KERNEL Topology(EntityType entType)
    : Entity(entType)
  {}
  DECL_CS_KERNEL virtual ~Topology() {}

public:
  DECL_CS_KERNEL virtual TopologyType GetType() const = 0;
};

class Vertex : public Topology
{
  using BASE_CLASS = Topology;

public:
  DECL_CS_KERNEL Vertex()
    : BASE_CLASS(EntityType::Vertex)
  {}

  DECL_CS_KERNEL virtual TopologyType GetType() const override
  {
    return TopologyType::Vertex;
  }
};

class CoEdge : public Topology
{
  using BASE_CLASS = Topology;

public:
  DECL_CS_KERNEL CoEdge()
    : BASE_CLASS(EntityType::CoEdge)
  {}
  DECL_CS_KERNEL virtual TopologyType GetType() const override
  {
    return TopologyType::CoEdge;
  }
};

class Edge : public Topology
{
  using BASE_CLASS = Topology;

public:
  DECL_CS_KERNEL Edge()
    : BASE_CLASS(EntityType::Edge)
  {}

  DECL_CS_KERNEL virtual TopologyType GetType() const override
  {
    return TopologyType::Edge;
  }
};

class Loop : public Topology
{
  using BASE_CLASS = Topology;

public:
  DECL_CS_KERNEL Loop()
    : BASE_CLASS(EntityType::Loop)
  {}
  DECL_CS_KERNEL virtual TopologyType GetType() const override
  {
    return TopologyType::Loop;
  }
};

class Face : public Topology
{
  using BASE_CLASS = Topology;

public:
  DECL_CS_KERNEL Face()
    : BASE_CLASS(EntityType::Face)
  {}
  DECL_CS_KERNEL virtual TopologyType GetType() const override
  {
    return TopologyType::Face;
  }
};

class Shell : public Topology
{
  using BASE_CLASS = Topology;

public:
  DECL_CS_KERNEL Shell()
    : BASE_CLASS(EntityType::Shell)
  {}
  DECL_CS_KERNEL virtual TopologyType GetType() const override
  {
    return TopologyType::Shell;
  }
};

class Lump : public Topology
{
  using BASE_CLASS = Topology;

public:
  DECL_CS_KERNEL Lump()
    : BASE_CLASS(EntityType::Lump)
  {}
  DECL_CS_KERNEL virtual TopologyType GetType() const override
  {
    return TopologyType::Lump;
  }
};

class Wire : public Topology
{
  using BASE_CLASS = Topology;

public:
  DECL_CS_KERNEL Wire()
    : BASE_CLASS(EntityType::Wire)
  {}
  DECL_CS_KERNEL virtual TopologyType GetType() const override
  {
    return TopologyType::Wire;
  }
};

class Body : public Topology
{
  using BASE_CLASS = Topology;

public:
  DECL_CS_KERNEL Body()
    : BASE_CLASS(EntityType::Body)
  {}
  DECL_CS_KERNEL virtual TopologyType GetType() const override
  {
    return TopologyType::Body;
  }
};

} // namespace kernel
} // namespace cs
