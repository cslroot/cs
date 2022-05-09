#include "Node.h"

#include <cs/base.h>

using namespace cs::base;
using namespace cs::render;

Node::Node()
  : _visible(true)
  , _name(CSString::CreateFromHex(this))
{}

Node::~Node() {}
