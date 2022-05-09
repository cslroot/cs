#pragma once

#include <cs/render/common.h>
#include <cs/render_fwd.h>

#include <cs/base/CSString.h>

#include <memory>
#include <vector>

namespace cs {
namespace render {

class Node
{
public:
  DECL_CS_RENDER Node();
  DECL_CS_RENDER virtual ~Node();

public:
  DECL_CS_RENDER void Show() { _visible = true; }
  DECL_CS_RENDER void Hide() { _visible = false; }
  DECL_CS_RENDER bool GetVisible() const { return _visible; }

  DECL_CS_RENDER const cs::base::CSString& Name() const { return _name; }
  DECL_CS_RENDER void SetName(const cs::base::CSString& name) { _name = name; }

private:
  cs::base::CSString _name;
  bool _visible;
  std::vector<std::shared_ptr<Node>> _children;
};

} // namespace render
} // namespace cs
