#pragma once

#include <cs/base_fwd.h>
#include <cs/core_fwd.h>
#include <cs/kernel_fwd.h>
#include <cs/render/CSDisplayableObject.h>
#include <cs/render/common.h>
#include <cs/render_fwd.h>

namespace cs {
namespace render {

class Mesh : public CSDisplayableObject
{
private:
  /* data */
public:
  DECL_CS_RENDER Mesh(const cs::kernel::Entity& entity,
                      const cs::render::CSMaterial& material)
  {}
  DECL_CS_RENDER virtual ~Mesh() {}
};

} // namespace render
} // namespace cs
