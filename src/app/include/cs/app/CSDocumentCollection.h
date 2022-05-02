#pragma once

#include <cs/app/app_common.h>
#include <cs/base_fwd.h>

#include <memory>

#include <cs/base/CSString.h>
#include <cs/base/ICSCollection.h>
#include <cs/base_fwd.h>

namespace cs {
namespace app {

class CSDocument;

class CSDocumentCollection : cs::base::ICSCollection<CSDocument>
{
private:
  /* data */
public:
  DECL_CS_APP CSDocumentCollection();
  DECL_CS_APP ~CSDocumentCollection();

public:
  DECL_CS_APP CSDocument& OpenNewDocument(const cs::base::CSString& doc_id);

public:
  void Clear() override;
  size_t Size() const override;

private:
  CSDocument& Add(std::unique_ptr<CSDocument> doc) override;

private:
  struct Impl;
  std::unique_ptr<Impl> _impl;
};

} // namespace app
} // namespace cs
