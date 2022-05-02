#include "Scene.h"

#include "Mesh.h"

using namespace cs::render;

struct Scene::Impl
{
  CSDisplayableObject* _rootObj = nullptr;
};

Scene::Scene(/* args */)
  : _impl(std::make_unique<Impl>())
{}

Scene::~Scene() {}

void
Scene::Add(CSDisplayableObject* mesh)
{
  _impl->_rootObj = mesh;
}

CSDisplayableObject*
Scene::RootObject() const
{
  return _impl->_rootObj;
}
