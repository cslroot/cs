#pragma once

#include <cs/render/common.h>

namespace cs {
namespace render {

class DECL_CS_RENDER Camera
{
private:
  /* data */
public:
  Camera(/* args */);
  ~Camera();
};

class DECL_CS_RENDER OrthoCamera : public Camera
{};
class DECL_CS_RENDER PerspectiveCamera : public Camera
{};

} // namespace render
} // namespace cs
