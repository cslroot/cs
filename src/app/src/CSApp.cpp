#include "CSApp.h"

#include <cs/base.h>
#include <cs/core.h>

#include "CSPluginManager.h"

#include "CSDocument.h"
#include "CSDocumentCollection.h"

#include "CSCommand.h"
#include "CSCommandCollection.h"

#include <Poco/SingletonHolder.h>

#include <filesystem>
#include <locale>
#include <memory>
#include <vector>

#if defined(_WIN32)
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#ifndef STRICT
#define STRICT
#endif
#include <Windows.h>
#endif

namespace fs = std::filesystem;

using namespace cs::app;
using namespace cs::base;
using namespace cs::core;

CSApp&
CSApp::Instance()
{
  static Poco::SingletonHolder<CSApp> sh;
  return *sh.get();
}
void
CSApp::Reset()
{
}

struct CSApp::Impl
{
  explicit Impl(CSApp* pApp)
    : _docs(pApp)
    , _commands(pApp)
  {
  }

  bool _initialized = false;

  std::string _command;

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
  _impl->_command = argv[0];
  _impl->_initialized = true;

  return *this;
}

cs::base::CSString
CSApp::Path() const
{
  cs::base::CSString pathStr;

#if defined(_WIN32)
  // wchar_t path[FILENAME_MAX];
  // int n = GetModuleFileNameW(0, path, sizeof(path) / sizeof(wchar_t));
  // if (n > 0) {
  //   pathStr = CSString{ path };
  // } else {
  //   throw CSException("Cannot get application file name.");
  // }

  auto& command = _impl->_command;
  fs::path p(command);
  if (p.is_absolute()) {
    pathStr = p.string();
  } else {
    pathStr = fs::absolute(p).string();
  }

#elif defined(__APPLE__) || defined(__linux__)

  auto& command = _impl->_command;
  fs::path p(command);
  if (p.is_absolute()) {
    pathStr = p.string();
  } else {
    pathStr = fs::absolute(p).string();
  }
#else
  pathStr = _command;
#endif

  return pathStr;
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
{
}

void
CSApp::EmitDocumentUnActivated(CSDocument&)
{
}
