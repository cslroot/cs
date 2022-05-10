#include "CSApp.h"

#include <cs/base.h>
#include <cs/core.h>

#include "CSPluginManager.h"

#include "CSDocument.h"
#include "CSDocumentCollection.h"

#include <locale>
#include <memory>
#include <vector>

using namespace cs::app;
using namespace cs::core;

std::unique_ptr<CSApp> CSApp::_app;

CSApp&
CSApp::Instance()
{
  return *_app;
}

CSApp&
CSApp::Create(int argc, char** argv)
{
  CSApp::_app = std::make_unique<CSApp>(argc, argv);
  return *_app;
}

struct CSApp::Impl
{
  Impl(CSApp* pApp)
    : _docs(pApp)
  {}

  CSDocumentCollection _docs;
  CSConfig _config;
  CSLogger _log;
  cs::core::UUID _sessionID;
  CSPluginManager _pluginManager;
};

CSApp::CSApp(int argc, char** argv)
  : _impl(std::make_unique<CSApp::Impl>(this))
{
  cs_initialize(argc, argv);

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

CSDocumentCollection&
CSApp::Documents() const
{
  return _impl->_docs;
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
