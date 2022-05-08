#pragma once

#include <cs/base_fwd.h>
#include <cs/render/render_common.h>

namespace cs {
namespace render {

class DECL_CS_RENDER CSMaterial
{
private:
  /* data */
public:
  CSMaterial(/* args */) {}
  ~CSMaterial() {}
};

class DECL_CS_RENDER BasicMaterial : public CSMaterial
{
public:
  explicit BasicMaterial(const cs::base::CSColor& color);

private:
  const cs::base::CSColor& _color;
};

class DECL_CS_RENDER DrawingMaterial : public CSMaterial
{
public:
  explicit DrawingMaterial(const cs::base::CSColor& color);

private:
  const cs::base::CSColor& _color;
};

} // namespace render
} // namespace cs
