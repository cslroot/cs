#pragma once

#include <cs/base/CSString.h>
#include <cs/base_fwd.h>
#include <cs/core/common.h>
#include <memory>

namespace cs {
namespace core {

class ICSPlugin
{
public:
  virtual ~ICSPlugin() {}

public:
  virtual int Version() const = 0;
  virtual cs::base::CSString Name() const = 0;

  virtual void Initialize(int argc, char** argv) = 0;
  virtual void Terminate() = 0;
};

} // namespace core
} // namespace cs

typedef cs::core::ICSPlugin* (*ICSPluginEntryFunc)(); // function pointer typ
