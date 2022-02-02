#include "csdocumentcollection.h"
#include "csdocument.h"

#include <cs/base.h>

#include <vector>

using namespace cs::app;
using namespace cs::base;

struct CSDocumentCollection::Impl
{
    std::vector<std::unique_ptr<CSDocument>> _docs;
};

CSDocumentCollection::CSDocumentCollection()
    : _impl(std::make_unique<Impl>())
{}

CSDocumentCollection::~CSDocumentCollection()
{}


CSDocument& CSDocumentCollection::OpenNewDocument(const cs::base::CSString& doc_id)
{
    static int nDoc = 0;
    std::unique_ptr<CSDocument> doc = CSDocument::Create(doc_id.c_str(), doc_id);
    return this->Add(std::move(doc));
}


CSDocument& CSDocumentCollection::Add(std::unique_ptr<CSDocument> doc)
{
    auto idx = _impl->_docs.size();
    _impl->_docs.emplace_back(std::move(doc));
    return *_impl->_docs[idx];
}

void CSDocumentCollection::Clear()
{
    _impl->_docs.clear();
}
size_t CSDocumentCollection::Size() const
{
    return _impl->_docs.size();
}
