#include "csapp.h"

#include <cs/core.h>

#include "csdocument.h"
#include "csdocumentcollection.h"

#include <vector>
#include <memory>

using namespace cs::app;

struct CSApp::Impl
{
    Impl()
    {
        static int ii = 0;
        ii++;
    }

    CSDocumentCollection _docs;
};


CSApp::CSApp(int argc, char** argv)
    : _impl(std::make_unique<CSApp::Impl>())
{
    cs_initialize(argc, argv);
}

CSApp::~CSApp()
{
    cs_terminate();
}

CSDocument& CSApp::OpenNewDocument()
{
    auto doc = std::make_shared<CSDocument>();
    _impl->_docs.Add(doc);
    return *doc;
}

CSDocumentCollection& CSApp::Documents() const
{
    return _impl->_docs;
}
