#pragma once

#include <cs/render/CSDisplayableObject.h>
#include <cs/render/common.h>
#include <cs/render_fwd.h>

#include <memory>

namespace cs {
namespace render {

class Scene
{
private:
  /* data */
public:
  DECL_CS_RENDER Scene(/* args */);
  DECL_CS_RENDER ~Scene();

public:
  DECL_CS_RENDER void Add(Node::Ptr mesh);
  DECL_CS_RENDER void Update();
  DECL_CS_RENDER CSDisplayableObject::Ptr RootObject() const;

private:
  struct Impl;
  std::unique_ptr<Impl> _impl;
};

} // namespace render
} // namespace cs
