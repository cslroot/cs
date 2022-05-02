#pragma once

#include <cs/app/app_common.h>
#include <cs/base_fwd.h>

#include <memory>

#include <cs/base/CSString.h>
#include <cs/base/ICSCollection.h>
#include <cs/base_fwd.h>

namespace cs {
namespace app {

class CSApp;
class CSDocument;

class CSDocumentCollection final : cs::base::ICSCollection<CSDocument>
{
public:
  DECL_CS_APP CSDocumentCollection(CSApp*);
  DECL_CS_APP ~CSDocumentCollection();

public:
  /**
   * @brief Get active document
   *
   * @return DECL_CS_APP&
   */
  DECL_CS_APP CSDocument* ActiveDocument() const;
  DECL_CS_APP void SetActiveDocument(CSDocument* pDoc);
  DECL_CS_APP CSDocument& OpenNewDocument(const cs::base::CSString& doc_id);

public:
  DECL_CS_APP void Clear() override;
  DECL_CS_APP size_t Size() const override;

private:
  CSDocument& Add(std::unique_ptr<CSDocument> doc) override;

private:
  struct Impl;
  std::unique_ptr<Impl> _impl;
};

} // namespace app
} // namespace cs
