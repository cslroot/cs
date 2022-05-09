#pragma once

#include <cs/app/CSDocument.h>
#include <cs/app/common.h>

namespace cs {
namespace app {

class CSDocument2d : public CSDocument::Registrar<CSDocument2d>
{
public:
  explicit DECL_CS_APP CSDocument2d(const cs::base::CSString&);
  DECL_CS_APP ~CSDocument2d();

private:
};

} // namespace app
} // namespace cs
