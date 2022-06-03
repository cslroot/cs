#pragma once

#include <cs/render/Renderer.h>
#include <cs/render/common.h>

#include <memory>

namespace cs {
inline namespace render {

class GLFWRenderer : public Renderer
{
public:
  DECL_CS_RENDER GLFWRenderer();
  DECL_CS_RENDER ~GLFWRenderer() override;

public:
  DECL_CS_RENDER void Init() override;
  DECL_CS_RENDER void Terminate() override;

  DECL_CS_RENDER void Render(const Scene& scene, const Camera& camera) override;
  DECL_CS_RENDER void Resize(int width, int height) override;
  DECL_CS_RENDER bool WindowShouldClose() override;

private:
  struct Impl;
  std::unique_ptr<Impl> _impl;
};

} // namespace render
} // namespace cs
