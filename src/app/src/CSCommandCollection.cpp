#include "CSCommandCollection.h"

#include "CSApp.h"
#include "CSCommand.h"

#include <cs/base.h>

#include <algorithm>
#include <cassert>
#include <vector>

using namespace cs::app;
using namespace cs::base;

struct CSCommandCollection::Impl
{
  std::vector<std::unique_ptr<CSCommand>> _docs;
  CSCommand* _pActiveDocument = nullptr;
  CSApp* _pApp = nullptr;
};

CSCommandCollection::CSCommandCollection(CSApp* pOwnerApp)
  : _impl(std::make_unique<Impl>())
{
  assert(pOwnerApp);
}

CSCommandCollection::~CSCommandCollection() {}

CSCommand&
CSCommandCollection::Add(std::unique_ptr<CSCommand> doc)
{
  auto idx = _impl->_docs.size();
  _impl->_docs.emplace_back(std::move(doc));
  return *_impl->_docs[idx];
}

void
CSCommandCollection::Clear()
{
  _impl->_docs.clear();
  _impl->_pActiveDocument = nullptr;
}

size_t
CSCommandCollection::Size() const
{
  return _impl->_docs.size();
}
