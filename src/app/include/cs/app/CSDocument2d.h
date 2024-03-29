#pragma once

#include <cs/app/CSDocument.h>
#include <cs/app/common.h>

namespace cs {
inline namespace app {

class CSDocument2d : public CSDocument::Registrar<CSDocument2d>
{
public:
  explicit DECL_CS_APP CSDocument2d(const cs::base::CSString& docName);
  DECL_CS_APP ~CSDocument2d() override;

public:
  DECL_CS_APP cs::base::CSString TypeName() const override;

private:
};

} // namespace app
} // namespace cs
