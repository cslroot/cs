#pragma once

#include <cs/app/common.h>

#include <memory>

namespace cs {
inline namespace app {

/**
 * @brief abstract command base class
 *
 */
class CSCommand
{
public:
  DECL_CS_APP CSCommand();
  DECL_CS_APP virtual ~CSCommand();

  DECL_CS_APP virtual bool CanExecute(void* parameter) const;
  DECL_CS_APP virtual bool Execute(void* parameter) = 0;

private:
  struct Impl;
  std::unique_ptr<Impl> _impl;
};

} // namespace app
} // namespace cs
