#include "CSDisplayableObject.h"

#include <cs/base.h>
#include <cs/core.h>
#include <cs/render/material.h>

using namespace cs::render;


void CSDisplayableObject::setBuffer(std::shared_ptr<cs::core::CSBufferObject> _)
{
    _cachedMesh = _;
}

CSDisplayableObject2d::CSDisplayableObject2d(const cs::core::CSObject& obj_, const CSMaterial& mat_)
{
    this->setBuffer(obj_.GenerateBuffer());
}
