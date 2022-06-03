#pragma once

#include <cs/app/CSDocument.h>
#include <cs/app/common.h>

namespace cs {
inline namespace app {

class CSDocument3d : public CSDocument::Registrar<CSDocument3d>
{
public:
  explicit DECL_CS_APP CSDocument3d(const cs::base::CSString&){};
  DECL_CS_APP ~CSDocument3d() override = default;

public:
  DECL_CS_APP cs::base::CSString TypeName() const override;
};

} // namespace app
} // namespace cs
