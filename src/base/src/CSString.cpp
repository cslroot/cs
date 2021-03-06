#include "CSString.h"

#include <algorithm>
#include <codecvt>
#include <iomanip>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>

#ifdef _WIN32
#include <Windows.h>
#endif

using namespace cs::base;

namespace {

std::string
wideToUtf8(const std::wstring& wstr)
{
  if (wstr.empty()) {
    return {};
  }

#ifdef _WIN32
  int size_needed = WideCharToMultiByte(CP_UTF8,
                                        0,
                                        &wstr[0],
                                        static_cast<DWORD>(wstr.size()),
                                        nullptr,
                                        0,
                                        nullptr,
                                        nullptr);
  std::string strTo(size_needed, 0);
  WideCharToMultiByte(CP_UTF8,
                      0,
                      &wstr[0],
                      static_cast<DWORD>(wstr.size()),
                      &strTo[0],
                      size_needed,
                      nullptr,
                      nullptr);
  return strTo;
#else
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
  return converter.to_bytes(wstr.c_str());
#endif
}

std::wstring
utf8toWide(const std::string& strU8)
{
  if (strU8.empty()) {
    return {};
  }
#ifdef _WIN32
  int size_needed = MultiByteToWideChar(
    CP_UTF8, 0, &strU8[0], static_cast<DWORD>(strU8.size()), nullptr, 0);
  std::wstring wstrTo(size_needed, 0);
  MultiByteToWideChar(CP_UTF8,
                      0,
                      &strU8[0],
                      static_cast<DWORD>(strU8.size()),
                      &wstrTo[0],
                      size_needed);
  return wstrTo;
#else
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
  return converter.from_bytes(strU8.c_str());
#endif
}
} // namespace

CSString
CSString::CreateFromHex(void* p)
{
  std::stringstream ss;
  ss.imbue(std::locale::classic());
  ss << std::setfill('0') << std::setw(sizeof(p) * 2) << std::hex
     << reinterpret_cast<int64_t>(
          p); // pointer type is converted as "0x00000000" on macos, so the
              // result was unexpected string "00000000000000x0" ...
  std::string s = ss.str(); // "10"
  return s;
}

CSString::CSString(/* args */) = default;

CSString::CSString(const char* utf8string)
  : _str(utf8string)
{}

CSString::CSString(const std::string& utf8string)
  : _str(utf8string)
{}

CSString::CSString(const wchar_t* widestring)
{
  _str = wideToUtf8(widestring);
}

CSString::CSString(const std::wstring& wstr)
{
  _str = wideToUtf8(wstr);
}

CSString::CSString(const CSString& a) = default;

CSString::~CSString() = default;

const char*
CSString::c_str() const
{
  return _str.c_str();
}

std::string
CSString::str() const
{
  return _str;
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
  CSString repString;

  if (rep == '\0') {
    std::string tmp;
    std::remove_copy(_str.begin(), _str.end(), std::back_inserter(tmp), target);
    repString = tmp;
  } else {
    repString = *this;
    auto& s = repString._str;
    std::replace(s.begin(), s.end(), target, rep);
  }

  return repString;
}

CSString
CSString::Replace(const CSString& target, const CSString& rep) const
{
  CSString repString = *this;
  auto& s = repString._str;
  if (!target.empty()) {
    std::string::size_type pos = 0;
    while ((pos = s.find(target.str(), pos)) != std::string::npos) {
      s.replace(pos, target.length(), rep.str());
      pos += rep.length();
    }
  }
  return repString;
}

int
CSString::ParseInt() const
{
  return std::stoi(_str, nullptr, 0);
}

unsigned int
CSString::ParseUint() const
{
  return std::stoul(_str, nullptr, 0);
}
