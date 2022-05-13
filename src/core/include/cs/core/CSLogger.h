#pragma once

#include <cs/core/common.h>

#include <cs/base_fwd.h>

#include <memory>

namespace cs {
namespace core {

class CSLogger
{
public:
  // DECL_CS_CORE static std::unique_ptr<CSLogger> Create();

public:
  enum class Priority
  {
    Fatal,
    Critical,
    Error,
    Warning,
    Notice,
    Information,
    Debug,
    Trace,
  };

public:
  DECL_CS_CORE CSLogger();
  DECL_CS_CORE virtual ~CSLogger();

public:
  DECL_CS_CORE void SetLevel(const cs::base::CSString& level);
  DECL_CS_CORE void SetLevel(const Priority& level);

  DECL_CS_CORE void Fatal(const cs::base::CSString& message);
  DECL_CS_CORE void Critical(const cs::base::CSString& message);
  DECL_CS_CORE void Error(const cs::base::CSString& message);
  DECL_CS_CORE void Warning(const cs::base::CSString& message);
  DECL_CS_CORE void Notice(const cs::base::CSString& message);
  DECL_CS_CORE void Information(const cs::base::CSString& message);
  DECL_CS_CORE void Debug(const cs::base::CSString& message);
  DECL_CS_CORE void Trace(const cs::base::CSString& message);

  DECL_CS_CORE void Write(Priority priority, const cs::base::CSString& message);

private:
  struct Impl;
  std::unique_ptr<Impl> _impl;
};

} // namespace core
} // namespace cs
