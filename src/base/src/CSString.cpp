#include "CSString.h"

#include <algorithm>
#include <codecvt>
#include <iostream>
#include <locale>
#include <string>

using namespace cs::base;

namespace {
// char converter

}

CSString::CSString(/* args */) {}

CSString::CSString(const char* utf8string)
  : _str(utf8string)
{}

CSString::CSString(const std::string& utf8string)
  : _str(utf8string)
{}

CSString::CSString(const wchar_t* widestring)
{
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
  _str = converter.to_bytes(widestring);
}

CSString::CSString(const std::wstring& wstr)
{
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
  _str = converter.to_bytes(wstr.c_str());
}

CSString::CSString(const CSString& a)
  : _str(a._str)
{}

CSString::~CSString() {}

const char*
CSString::c_str() const
{
  return _str.c_str();
}

CSString&
CSString::operator+=(const CSString& rhs)
{
  _str += rhs._str;
  return *this;
}

CSString&
CSString::operator+=(const char* u8rhs)
{
  _str += u8rhs;
  return *this;
}

cs::base::CSString
operator+(const cs::base::CSString& str1, const cs::base::CSString& str2)
{
  CSString str(str1.c_str());
  str += str2;
  return str;
}

std::ostream&
operator<<(std::ostream& os, const CSString& str)
{
  os << str.c_str();
  return os;
}

CSString
CSString::Replace(const char target, const char rep) const
{
  CSString repString = *this;

  if (rep == '\0') {
    auto& str = repString._str;
    str.erase(std::remove(str.begin(), str.end(), target), str.end());
    repString = str;
  } else {
    std::replace(repString._str.begin(), repString._str.end(), target, rep);
  }

  return repString;
}

int
CSString::ParseInt() const
{
  return std::stoi(_str);
}