#pragma once

#include <cs/base/common.h>
#include <string>

namespace cs {
namespace base {
class CSString
{
public:
  DECL_CS_BASE CSString();
  DECL_CS_BASE CSString(
    const char* utf8string); // cppcheck-suppress noExplicitConstructor
  DECL_CS_BASE CSString(
    const std::string& utf8string); // cppcheck-suppress noExplicitConstructor
  DECL_CS_BASE explicit CSString(const wchar_t* wstring);
  DECL_CS_BASE explicit CSString(const std::wstring& wstring);
  DECL_CS_BASE CSString(const CSString& a);
  DECL_CS_BASE virtual ~CSString();

public:
  DECL_CS_BASE static CSString CreateFromHex(void* p);

public:
  DECL_CS_BASE const char* c_str() const;
  DECL_CS_BASE std::string str() const;
  DECL_CS_BASE CSString& operator+=(const char* u8rhs);
  DECL_CS_BASE CSString& operator+=(const CSString& rhs);

  // "AbcAbc" Replace('A', 'X') => "XbcXbc"
  DECL_CS_BASE CSString Replace(const char target, const char rep) const;

  DECL_CS_BASE int ParseInt() const;

private:
  std::string _str;
};

} // namespace base
} // namespace cs

DECL_CS_BASE cs::base::CSString
operator+(const cs::base::CSString& str1, const cs::base::CSString& str2);
DECL_CS_BASE std::ostream&
operator<<(std::ostream& os, const cs::base::CSString& str);
