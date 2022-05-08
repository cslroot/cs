#pragma once

#include <cs/render/render_common.h>
#include <cs/render_fwd.h>

namespace cs {
namespace render {

class Node
{
public:
  DECL_CS_RENDER Node() {}
  DECL_CS_RENDER virtual ~Node() {}

public:
private:
  std::vector<std::shared_ptr<Node>> _nodes;
};

} // namespace render
} // namespace cs
