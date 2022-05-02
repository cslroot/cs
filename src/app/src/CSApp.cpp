#include "CSApp.h"

#include <cs/core.h>

#include "CSDocument.h"
#include "CSDocumentCollection.h"

#include <memory>
#include <vector>

using namespace cs::app;

struct CSApp::Impl
{
  Impl(CSApp* pApp)
    : _docs(pApp)
  {}

  CSDocumentCollection _docs;
};

CSApp::CSApp(int argc, char** argv)
  : _impl(std::make_unique<CSApp::Impl>(this))
{
  cs_initialize(argc, argv);
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

void
CSApp::EmitDocumentActivated(CSDocument&)
{}
void
CSApp::EmitDocumentUnActivated(CSDocument&)
{}
