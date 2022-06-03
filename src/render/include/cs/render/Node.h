#pragma once

#include <cs/render/common.h>
#include <cs/render_fwd.h>

#include <cs/base/CSString.h>

#include <memory>
#include <vector>

namespace cs {
inline namespace render {

class Node : public std::enable_shared_from_this<Node>
{
public:
  using Ptr = std::shared_ptr<Node>;

  DECL_CS_RENDER
  Node();
  DECL_CS_RENDER Node(const cs::base::CSString& name);
  DECL_CS_RENDER virtual ~Node();

public:
  DECL_CS_RENDER void Show() { _visible = true; }
  DECL_CS_RENDER void Hide() { _visible = false; }
  DECL_CS_RENDER bool GetVisible() const { return _visible; }

  DECL_CS_RENDER const cs::base::CSString& Name() const { return _name; }
  DECL_CS_RENDER void SetName(const cs::base::CSString& name) { _name = name; }

  DECL_CS_RENDER Node* Parent() const { return _parent.lock().get(); };
  DECL_CS_RENDER void SetParent(std::weak_ptr<Node> parent)
  {
    _parent = parent;
  };

  DECL_CS_RENDER std::vector<Node::Ptr>& Children() { return _children; };
  DECL_CS_RENDER void AddChild(Node::Ptr& pNode);
  DECL_CS_RENDER void AddChildren(const std::vector<Node::Ptr>& pNodes);

private:
  cs::base::CSString _name;
  bool _visible;
  std::weak_ptr<Node> _parent;
  std::vector<Node::Ptr> _children;
};

} // namespace render
} // namespace cs
