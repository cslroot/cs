#include "Scene.h"

#include "Mesh.h"

using namespace cs::render;

struct Scene::Impl
{
  CSDisplayableObject::Ptr _root = std::make_shared<CSDisplayableObject>("/");
};

Scene::Scene(/* args */)
  : _impl(std::make_unique<Impl>())
{}

Scene::~Scene() {}

void
Scene::Add(Node::Ptr mesh)
{
  _impl->_root->AddChild(mesh);
}

void
Scene::Update()
{
  // _impl->_root->update();
}

CSDisplayableObject::Ptr
Scene::RootObject() const
{
  return _impl->_root;
}
