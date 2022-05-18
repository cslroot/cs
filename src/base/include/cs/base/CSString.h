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
  DECL_CS_BASE bool empty() const { return _str.empty(); }
  DECL_CS_BASE size_t length() const { return _str.length(); }

  DECL_CS_BASE CSString& operator+=(const char* u8rhs);
  DECL_CS_BASE CSString& operator+=(const CSString& rhs);

  /**
   * @brief "AbcAbc" Replace('A', 'X') => "XbcXbc"
   *
   * @param target char to be replaced
   * @param rep char replace to. remove char when special char '\0' is specified
   * @return new replaced string
   */
  DECL_CS_BASE CSString Replace(const char target, const char rep) const;
  /**
   * @brief replace all target string to rep
   *
   * @param target
   * @param rep
   * @return DECL_CS_BASE
   */
  DECL_CS_BASE CSString Replace(const CSString& target,
                                const CSString& rep) const;

  /**
   * @brief "123" -> 123, "0x10" -> 16
   * @return parsed value
   */
  DECL_CS_BASE int ParseInt() const;
  /**
   * @brief "123" -> 123U, "0x10" -> 16U
   * @return parsed value
   */
  DECL_CS_BASE unsigned int ParseUint() const;

private:
  std::string _str;
};

} // namespace base
} // namespace cs

DECL_CS_BASE cs::base::CSString
operator+(const cs::base::CSString& str1, const cs::base::CSString& str2);
DECL_CS_BASE std::ostream&
operator<<(std::ostream& os, const cs::base::CSString& str);
