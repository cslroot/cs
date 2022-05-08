#pragma once

#include <cs/render/render_common.h>

#include <cs/core_fwd.h>
#include <memory>

namespace cs {
namespace render {

class CSMaterial;

class CSDisplayableObject
{
private:
  /* data */
public:
  DECL_CS_RENDER CSDisplayableObject()
    : _visible(true)
    , _cachedMesh(nullptr)
  {}
  DECL_CS_RENDER virtual ~CSDisplayableObject() {}

public:
  DECL_CS_RENDER void Show() { _visible = true; }
  DECL_CS_RENDER void Hide() { _visible = false; }
  DECL_CS_RENDER bool GetVisible() const { return _visible; }

  DECL_CS_RENDER std::shared_ptr<cs::core::CSBufferObject> GetBuffer() const
  {
    return _cachedMesh;
  }
  DECL_CS_RENDER virtual void Test() {}

protected:
  DECL_CS_RENDER void setBuffer(std::shared_ptr<cs::core::CSBufferObject> _);

private:
  bool _visible;
  std::shared_ptr<cs::core::CSBufferObject> _cachedMesh;
};

class CSDisplayableObject2d : public CSDisplayableObject
{
public:
  DECL_CS_RENDER CSDisplayableObject2d(const cs::core::CSObject&,
                                       const CSMaterial&);
};

} // namespace render
} // namespace cs
