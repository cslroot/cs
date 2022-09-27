#pragma once

#include <cs/base/CSString.h>
#include <cs/base/common.h>

#include <exception>

namespace cs {
namespace base {

class DECL_CS_BASE CSException : public std::exception
{
public:
  CSException();
  explicit CSException(const cs::base::CSString& msg);
  virtual ~CSException();

  const cs::base::CSString& Message() const { return _msg; }

private:
  int _id = 0;
  cs::base::CSString _msg;
};

} // namespace base
} // namespace cs
