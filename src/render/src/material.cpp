#include "material.h"

#include <cs/base.h>

using namespace cs::render;

BasicMaterial::BasicMaterial(const cs::base::CSColor& color)
    : _color(color)
{}
