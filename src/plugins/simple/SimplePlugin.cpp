#include "SimplePlugin.h"

#include <cs/core.h>

using namespace cs::plguins::simple;

extern "C" DECL_CS_PLUGINS_SIMPLE cs::core::ICSPlugin*
cs_create_plugin()
{
  return new SimplePlugin();
}

SimplePlugin::SimplePlugin() {}
SimplePlugin::~SimplePlugin() {}

SimplePlugin plugin;
