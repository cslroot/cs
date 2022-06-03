#pragma once

#include <cs/kernel/common.h>

#include <cs/base/CSColor.h>

namespace cs {
inline namespace kernel {

constexpr int LAYER_ID_UNSET = -1;

class Geometry2dProperty
{
public:
  DECL_CS_KERNEL Geometry2dProperty() = default;
  DECL_CS_KERNEL ~Geometry2dProperty() = default;

public:
  DECL_CS_KERNEL int LayerID() const { return _layerID; }
  DECL_CS_KERNEL void SetLayerID(int layerID) { _layerID = layerID; }

  DECL_CS_KERNEL cs::base::CSColor Color() const { return _color; }
  DECL_CS_KERNEL void SetColor(const cs::base::CSColor& color)
  {
    _color = color;
  }

private:
  int _layerID = LAYER_ID_UNSET;
  cs::base::CSColor _color;
};

} // namespace core
} // namespace cs
