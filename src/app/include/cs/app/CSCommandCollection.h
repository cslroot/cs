#pragma once

#include <cs/app/common.h>
#include <cs/app_fwd.h>
#include <cs/base_fwd.h>

#include <memory>

#include <cs/base/CSString.h>
#include <cs/base/ICSCollection.h>
#include <cs/base_fwd.h>

namespace cs {
namespace app {

class CSCommandCollection final : public cs::base::ICSCollection<CSCommand>
{
public:
  DECL_CS_APP CSCommandCollection(CSApp*);
  DECL_CS_APP ~CSCommandCollection();

public:
public:
  DECL_CS_APP void Clear() override;
  DECL_CS_APP size_t Size() const override;

private:
  CSCommand& Add(std::unique_ptr<CSCommand> doc) override;

private:
  struct Impl;
  std::unique_ptr<Impl> _impl;
};

} // namespace app
} // namespace cs
