#pragma once

#include "common.h"
#include <cs/core/ICSPlugin.h>

namespace cs {
namespace plugins {
namespace simple {

extern "C" DECL_CS_PLUGIN_SIMPLE cs::core::ICSPlugin*
cs_create_plugin();

class DECL_CS_PLUGIN_SIMPLE SimplePlugin final : public cs::core::ICSPlugin
{
public:
  SimplePlugin();
  ~SimplePlugin() override;

public:
  int Version() const override { return 0; }
  cs::base::CSString Name() const override { return "SimplePlugin"; }

  void Initialize(int argc, char** argv) override {}
  void Terminate() override {}
};

} // namespace simple
} // namespace plugins
} // namespace cs
