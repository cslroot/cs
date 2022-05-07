#include "CSApp.h"

#include <cs/core.h>

#include "CSDocument.h"
#include "CSDocumentCollection.h"

#include <locale>
#include <memory>
#include <vector>

using namespace cs::app;
using namespace cs::core;

struct CSApp::Impl
{
  Impl(CSApp* pApp)
    : _docs(pApp)
    , _log(cs::core::CSLogger::Create())
  {}

  CSDocumentCollection _docs;
  CSConfig _config;
  std::unique_ptr<CSLogger> _log;
  cs::core::UUID _sessionID;
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
  return *_impl->_log;
}

cs::core::UUID&
CSApp::SessionID() const
{
  return _impl->_sessionID;
}

void
CSApp::EmitDocumentActivated(CSDocument&)
{}

void
CSApp::EmitDocumentUnActivated(CSDocument&)
{}
