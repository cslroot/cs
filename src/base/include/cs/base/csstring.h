#pragma once

#include <cs/base/base_common.h>
#include <string>

namespace cs
{
    namespace base
    {
        class CSString
        {
        public:
            DECL_CS_BASE CSString();
            DECL_CS_BASE CSString(const char* utf8string);  // cppcheck-suppress noExplicitConstructor
            DECL_CS_BASE explicit CSString(const wchar_t* wstring);
            DECL_CS_BASE explicit CSString(const std::wstring& wstring);
            DECL_CS_BASE CSString(const CSString& a);
            DECL_CS_BASE virtual ~CSString();

        public:
            const char* c_str() const;
            CSString& operator+=(const char* u8rhs);
            CSString& operator+=(const CSString& rhs);

        private:
            std::string _str;
        };

    } // namespace base

} // namespace cs
