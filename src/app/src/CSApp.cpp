#include "CSApp.h"

#include <cs/base.h>
#include <cs/core.h>

#include "CSPluginManager.h"

#include "CSDocument.h"
#include "CSDocumentCollection.h"

#include "CSCommand.h"
#include "CSCommandCollection.h"

#include <Poco/SingletonHolder.h>

#include <locale>
#include <memory>
#include <vector>

using namespace cs::app;
using namespace cs::core;

CSApp&
CSApp::Instance()
{
  static Poco::SingletonHolder<CSApp> sh;
  return *sh.get();
}

struct CSApp::Impl
{
  explicit Impl(CSApp* pApp)
    : _docs(pApp)
    , _commands(pApp)
  {}

  bool _initialized = false;

  CSDocumentCollection _docs;
  CSCommandCollection _commands;
  CSConfig _config;
  CSLogger _log;
  cs::core::UUID _sessionID;
  CSPluginManager _pluginManager;
};

CSApp::CSApp()
  : _impl(std::make_unique<CSApp::Impl>(this))
{

  std::locale::global(std::locale(
#if _WIN32 && !__MINGW32__ && !__CYGWIN__
    ".UTF-8"
#else
    ""
#endif
    ));

  //----- init with config ----
  auto loglevel = _impl->_config.GetValue<cs::base::CSString>("loglevel");
  _impl->_log.SetLevel(loglevel);
}

CSApp::~CSApp()
{
  cs_terminate();
}

CSApp&
CSApp::Initialize(int argc, char** argv)
{
  cs_initialize(argc, argv);
  _impl->_initialized = true;

  return *this;
}

CSDocumentCollection&
CSApp::Documents() const
{
  return _impl->_docs;
}
CSCommandCollection&
CSApp::Commands() const
{
  return _impl->_commands;
}

cs::core::CSConfig&
CSApp::Config() const
{
  return _impl->_config;
}

cs::core::CSLogger&
CSApp::Log() const
{
  return _impl->_log;
}

cs::core::UUID&
CSApp::SessionID() const
{
  return _impl->_sessionID;
}

cs::app::CSPluginManager&
CSApp::PluginManager() const
{
  return _impl->_pluginManager;
}

void
CSApp::EmitDocumentActivated(CSDocument&)
{}

void
CSApp::EmitDocumentUnActivated(CSDocument&)
{}
