#include "Renderer.h"

#include <cs/render.h>

using namespace cs::render;

Renderer::Renderer(/* args */)
  : _width(0)
  , _height(0)
{}

Renderer::~Renderer() = default;

void
Renderer::Render(const Scene& scene, const Camera& camera)
{}

void
Renderer::Resize(int width, int height)
{
  _width = width;
  _height = height;
}
