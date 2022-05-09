#pragma once

#include <cs/app/common.h>

#include <memory>

namespace cs {
namespace app {

/**
 * @brief asbtract command base class
 *
 */
class CSCommand
{
public:
  DECL_CS_APP CSCommand();
  DECL_CS_APP virtual ~CSCommand();

public:
  DECL_CS_APP virtual bool CanExecute(void*) const;
  DECL_CS_APP virtual bool Execute(void*) = 0;

private:
  struct Impl;
  std::unique_ptr<Impl> _impl;
};

} // namespace app
} // namespace cs
