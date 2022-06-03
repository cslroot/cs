#pragma once

#include <cs/app/common.h>
#include <cs/app_fwd.h>
#include <cs/core_fwd.h>

#include <memory>

namespace cs {
inline namespace app {

/**
 * @brief Application level instance. Singleton
 *
 */
class CSApp
{
public:
  DECL_CS_APP CSApp();
  DECL_CS_APP virtual ~CSApp();

  DECL_CS_APP static CSApp& Instance();
  DECL_CS_APP static void Reset();

  DECL_CS_APP CSApp& Initialize(int argc, char** argv);

  DECL_CS_APP CSDocumentCollection& Documents() const;
  DECL_CS_APP CSCommandCollection& Commands() const;
  DECL_CS_APP cs::core::CSConfig& Config() const;
  DECL_CS_APP cs::core::CSLogger& Log() const;
  DECL_CS_APP cs::core::UUID& SessionID() const;
  DECL_CS_APP cs::app::CSPluginManager& PluginManager() const;

  // event
  DECL_CS_APP void EmitDocumentActivated(CSDocument&);
  DECL_CS_APP void EmitDocumentUnActivated(CSDocument&);

private:
  struct Impl;
  std::unique_ptr<Impl> _impl;
};

} // namespace app
} // namespace cs
