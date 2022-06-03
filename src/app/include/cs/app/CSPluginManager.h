#pragma once

#include <cs/app/common.h>
#include <cs/base_fwd.h>
#include <cs/core_fwd.h>
#include <memory>

namespace cs {
inline namespace app {

class CSPluginManager
{
public:
  DECL_CS_APP CSPluginManager();
  DECL_CS_APP ~CSPluginManager();

public:
  DECL_CS_APP void LoadAll();
  DECL_CS_APP cs::core::ICSPlugin* GetPlugin(
    const cs::base::CSString& pluginName);

private:
  struct Impl;
  std::unique_ptr<Impl> _impl;
};

} // namespace app
} // namespace cs
