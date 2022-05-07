#pragma once

#include <cs/core/Entity.h>
#include <cs/core/core_common.h>

namespace cs {
namespace core {

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
  DECL_CS_CORE Topology() {}
  DECL_CS_CORE virtual ~Topology() {}

public:
  DECL_CS_CORE virtual TopologyType GetType() const = 0;
};

class Vertex : public Topology
{
public:
  DECL_CS_CORE virtual TopologyType GetType() const override
  {
    return TopologyType::Vertex;
  }
};

class CoEdge : public Topology
{
public:
  DECL_CS_CORE virtual TopologyType GetType() const override
  {
    return TopologyType::CoEdge;
  }
};

class Edge : public Topology
{
public:
  DECL_CS_CORE virtual TopologyType GetType() const override
  {
    return TopologyType::Edge;
  }
};

class Loop : public Topology
{
public:
  DECL_CS_CORE virtual TopologyType GetType() const override
  {
    return TopologyType::Loop;
  }
};

class Face : public Topology
{
public:
  DECL_CS_CORE virtual TopologyType GetType() const override
  {
    return TopologyType::Face;
  }
};

class Shell : public Topology
{
public:
  DECL_CS_CORE virtual TopologyType GetType() const override
  {
    return TopologyType::Shell;
  }
};

class Lump : public Topology
{
public:
  DECL_CS_CORE virtual TopologyType GetType() const override
  {
    return TopologyType::Lump;
  }
};

class Wire : public Topology
{
public:
  DECL_CS_CORE virtual TopologyType GetType() const override
  {
    return TopologyType::Wire;
  }
};

class Body : public Topology
{
public:
  DECL_CS_CORE virtual TopologyType GetType() const override
  {
    return TopologyType::Body;
  }
};
} // namespace core

} // namespace cs
