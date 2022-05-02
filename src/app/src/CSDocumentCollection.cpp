#include "CSDocumentCollection.h"

#include "CSApp.h"
#include "CSDocument.h"

#include <cs/base.h>

#include <algorithm>
#include <vector>

using namespace cs::app;
using namespace cs::base;

struct CSDocumentCollection::Impl
{
  std::vector<std::unique_ptr<CSDocument>> _docs;
  CSDocument* _pActiveDocument = nullptr;
  CSApp* _pApp = nullptr;
};

CSDocumentCollection::CSDocumentCollection(CSApp* pOwnerApp)
  : _impl(std::make_unique<Impl>())
{
  assert(pOwnerApp);
}

CSDocumentCollection::~CSDocumentCollection() {}

CSDocument*
CSDocumentCollection::ActiveDocument() const
{
  return _impl->_pActiveDocument;
}

void
CSDocumentCollection::SetActiveDocument(CSDocument* pDoc)
{
  if (_impl->_pActiveDocument) {
    _impl->_pApp->EmitDocumentUnActivated(*pDoc);
  }
  _impl->_pActiveDocument = pDoc;
  if (pDoc) {
    _impl->_pApp->EmitDocumentActivated(*pDoc);
  }
}

CSDocument&
CSDocumentCollection::OpenNewDocument(const cs::base::CSString& doc_id)
{
  static int nDoc = 0;
  std::unique_ptr<CSDocument> pDoc = CSDocument::Create(doc_id.c_str(), doc_id);
  this->SetActiveDocument(pDoc.get());
  return this->Add(std::move(pDoc));
}

CSDocument&
CSDocumentCollection::Add(std::unique_ptr<CSDocument> doc)
{
  auto idx = _impl->_docs.size();
  _impl->_docs.emplace_back(std::move(doc));
  return *_impl->_docs[idx];
}

void
CSDocumentCollection::Clear()
{
  _impl->_docs.clear();
  _impl->_pActiveDocument = nullptr;
}

size_t
CSDocumentCollection::Size() const
{
  return _impl->_docs.size();
}
