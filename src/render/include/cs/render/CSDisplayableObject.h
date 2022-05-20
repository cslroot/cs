#pragma once

#include <cs/render/Node.h>
#include <cs/render/common.h>

#include <cs/core_fwd.h>
#include <memory>

namespace cs {
namespace render {

class CSMaterial;

class CSDisplayableObject : public Node
{
public:
  using Ptr = std::shared_ptr<CSDisplayableObject>;

  DECL_CS_RENDER CSDisplayableObject(const cs::base::CSString& name)
    : Node(name)
    , _cachedMesh(nullptr)
  {}
  DECL_CS_RENDER
  CSDisplayableObject()
    : _cachedMesh(nullptr)
  {}
  DECL_CS_RENDER ~CSDisplayableObject() override = default;

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
