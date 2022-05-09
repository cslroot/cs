#pragma once

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
  DECL_CS_RENDER void Add(CSDisplayableObject* mesh);
  DECL_CS_RENDER void Update();
  DECL_CS_RENDER CSDisplayableObject* RootObject() const;

private:
  struct Impl;
  std::unique_ptr<Impl> _impl;
};

} // namespace render
} // namespace cs
