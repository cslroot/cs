#include "SimplePlugin.h"

#include <cs/core.h>

using namespace cs::plugins::simple;

extern "C" DECL_CS_PLUGIN_SIMPLE cs::core::ICSPlugin*
cs_create_plugin()
{
  return new SimplePlugin();
}

SimplePlugin::SimplePlugin() {}
SimplePlugin::~SimplePlugin() {}

SimplePlugin plugin;
