#include <cs/base/csstring.h>

#include <iostream>
#include <string>
#include <locale>
#include <codecvt>

using namespace cs::base;

namespace {
    // char converter

}

CSString::CSString(/* args */)
{}

CSString::CSString(const char* utf8string)
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

CSString::~CSString()
{}

const char* CSString::c_str() const
{
    return _str.c_str();
}

CSString& CSString::operator+=(const CSString& rhs)
{
    _str += rhs._str;
    return *this;
}

CSString& CSString::operator+=(const char* u8rhs)
{
    _str += u8rhs;
    return *this;
}
