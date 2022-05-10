#pragma once

#include <cs/app/common.h>
#include <cs/app_fwd.h>
#include <cs/core_fwd.h>

#include <memory>

namespace cs {
namespace app {

class CSApp
{
public:
  DECL_CS_APP CSApp(int argc, char** argv);
  DECL_CS_APP virtual ~CSApp();

public:
  DECL_CS_APP static CSApp& Instance();
  DECL_CS_APP static CSApp& Create(int argc, char** argv);

public:
  DECL_CS_APP CSDocumentCollection& Documents() const;
  DECL_CS_APP CSCommandCollection& Commands() const;

  DECL_CS_APP cs::core::CSConfig& Config() const;
  DECL_CS_APP cs::core::CSLogger& Log() const;
  DECL_CS_APP cs::core::UUID& SessionID() const;

  DECL_CS_APP cs::app::CSPluginManager& PluginManager() const;

public:
  // event
  DECL_CS_APP void EmitDocumentActivated(CSDocument&);
  DECL_CS_APP void EmitDocumentUnActivated(CSDocument&);

private:
  struct Impl;
  std::unique_ptr<Impl> _impl;

private:
  static std::unique_ptr<CSApp> _app;
};

} // namespace app
} // namespace cs
