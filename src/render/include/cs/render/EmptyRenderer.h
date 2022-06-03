#pragma once

#include <cs/render/Renderer.h>
#include <cs/render_fwd.h>

namespace cs {
inline namespace render {

class EmptyRenderer : public Renderer
{
private:
  /* data */
public:
  DECL_CS_RENDER EmptyRenderer(/* args */) = default;
  DECL_CS_RENDER ~EmptyRenderer() override = default;
};

} // namespace render
} // namespace cs
