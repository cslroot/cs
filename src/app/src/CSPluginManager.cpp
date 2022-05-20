#include "CSPluginManager.h"

#include "CSApp.h"
#include <cs/base.h>
#include <cs/core.h>

#include <Poco/Glob.h>
#include <Poco/Path.h>
#include <Poco/SharedLibrary.h>

#include <unordered_map>
#include <vector>

using namespace cs::app;
using namespace cs::core;

struct CSPluginManager::Impl
{
  std::unordered_map<std::string, cs::core::ICSPlugin*> _plugins;
  std::vector<std::unique_ptr<Poco::SharedLibrary>> _libs;
};

CSPluginManager::CSPluginManager()
  : _impl(std::make_unique<Impl>())
{}

CSPluginManager::~CSPluginManager()
{
  for (auto& p : _impl->_plugins) {
    delete p.second;
  }
  _impl->_plugins.clear();

  _impl->_libs.clear();
}

void
CSPluginManager::LoadAll()
{
  using Poco::Glob;
  using Poco::Path;
  using Poco::SharedLibrary;
  auto pwd = Path(Path::current());
  auto pluginHome = pwd.append("plugins");
  std::set<std::string> files;
  auto targetPath = pluginHome.append("*" + Poco::SharedLibrary::suffix());
  CSApp::Instance().Log().Information(targetPath.toString());
  Glob::glob(targetPath, files);

  for (const auto& f : files) {
    CSApp::Instance().Log().Information(f);
    std::unique_ptr<SharedLibrary> plibrary =
      std::make_unique<SharedLibrary>(f); // will also load the library

    auto func =
      static_cast<ICSPluginEntryFunc>(plibrary->getSymbol("cs_create_plugin"));
    auto* pPlugin = func();
    auto name = pPlugin->Name();

    _impl->_plugins[name.str()] = std::move(pPlugin);
    _impl->_libs.push_back(std::move(plibrary));
  }
}

cs::core::ICSPlugin*
CSPluginManager::GetPlugin(const cs::base::CSString& pluginName)
{

  if (_impl->_plugins.find(pluginName.str()) == _impl->_plugins.end()) {
    return nullptr;
  }

  return _impl->_plugins[pluginName.str()];
  // auto& pp = _impl->_plugins;
  // return pp.empty() ? nullptr : pp.front();
}
