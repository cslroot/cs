#pragma once

#include <cs/app/CSDocument.h>
#include <cs/app/common.h>

namespace cs {
namespace app {

class CSDocument3d : public CSDocument::Registrar<CSDocument3d>
{
public:
  explicit DECL_CS_APP CSDocument3d(const cs::base::CSString&) {}
  DECL_CS_APP ~CSDocument3d() {}

public:
  DECL_CS_APP virtual cs::base::CSString TypeName() const override;
};

} // namespace app
} // namespace cs
