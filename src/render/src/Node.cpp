#include "Node.h"

#include <cs/base.h>

using namespace cs::base;
using namespace cs::render;

Node::Node(const cs::base::CSString& name)
  : _visible(true)
  , _name(name)
{}

Node::Node()
  : Node(CSString::CreateFromHex(this))
{}

Node::~Node() {}

void
Node::AddChild(Node::Ptr pNode)
{
  this->_children.emplace_back(pNode);
  pNode->SetParent(shared_from_this());
}

void
Node::AddChildren(const std::vector<std::shared_ptr<Node>>& pNodes)
{
  for (auto& pNode : pNodes) {
    this->_children.emplace_back(pNode);
    pNode->SetParent(shared_from_this());
  }
}
