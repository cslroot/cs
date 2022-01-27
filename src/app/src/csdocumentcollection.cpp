#include "csdocumentcollection.h"
#include "csdocument.h"

#include <cs/base.h>

#include <vector>

using namespace cs::app;
using namespace cs::base;

struct CSDocumentCollection::Impl
{
    std::vector<std::shared_ptr<CSDocument>> _docs;
};

CSDocumentCollection::CSDocumentCollection()
    : _impl(std::make_unique<Impl>())
{}

CSDocumentCollection::~CSDocumentCollection()
{}

void CSDocumentCollection::Add(std::shared_ptr<CSDocument>& doc)
{
    _impl->_docs.push_back(doc);
}

void CSDocumentCollection::Clear()
{
    _impl->_docs.clear();
}
size_t CSDocumentCollection::Size() const
{
    return _impl->_docs.size();
}
