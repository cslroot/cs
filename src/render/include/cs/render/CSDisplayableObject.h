#pragma once

#include <cs/render/common.h>
#include <cs/render/node.h>

#include <cs/core_fwd.h>
#include <memory>

namespace cs {
namespace render {

class CSMaterial;

class CSDisplayableObject : public Node
{
private:
  /* data */
public:
  DECL_CS_RENDER CSDisplayableObject()
    : _cachedMesh(nullptr)
  {}
  DECL_CS_RENDER virtual ~CSDisplayableObject() {}

public:
  DECL_CS_RENDER std::shared_ptr<cs::core::CSBufferObject> GetBuffer() const
  {
    return _cachedMesh;
  }
  DECL_CS_RENDER virtual void Test() {}

protected:
  DECL_CS_RENDER void setBuffer(std::shared_ptr<cs::core::CSBufferObject> _);

private:
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
