#pragma once

#include <cs/app/app_common.h>

#include <memory>

namespace cs {
namespace app {

class CSDocument;
class CSDocumentCollection;

class CSApp
{
public:
  DECL_CS_APP CSApp(int argc, char** argv);
  DECL_CS_APP virtual ~CSApp();

public:
  DECL_CS_APP CSDocumentCollection& Documents() const;

public:
  // event
  DECL_CS_APP void EmitDocumentActivated(CSDocument&);
  DECL_CS_APP void EmitDocumentUnActivated(CSDocument&);

private:
  struct Impl;
  std::unique_ptr<Impl> _impl;
};

} // namespace app
} // namespace cs
