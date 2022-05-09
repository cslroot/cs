#pragma once

#include <cs/app/common.h>
#include <cs/core_fwd.h>

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
  DECL_CS_APP cs::core::CSConfig& Config() const;
  DECL_CS_APP cs::core::CSLogger& Log() const;
  DECL_CS_APP cs::core::UUID& SessionID() const;

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
