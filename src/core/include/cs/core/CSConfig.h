#pragma once

#include <cs/core/core_common.h>
#include <cs/core/csobject.h>
#include <cs/base_fwd.h>

namespace cs
{
    namespace core
    {
        class CSConfig : CSObject
        {
        public:
            CSConfig();
            virtual ~CSConfig();

        public:
            DECL_CS_CORE void SetValue(const cs::base::CSString& key, bool bValue);
            DECL_CS_CORE void SetValue(const cs::base::CSString& key, int iValue);
            DECL_CS_CORE void SetValue(const cs::base::CSString& key, double dValue);
            DECL_CS_CORE void SetValue(const cs::base::CSString& key, const cs::base::CSString& strValue);

            template<typename T>
            T GetValue(const cs::base::CSString& key) const;

        public:
            // return fixed path: %APPDATA%/cs/app.config.json
            DECL_CS_CORE static cs::base::CSString ConfigHomePath();

        private:
            struct Impl;
            std::unique_ptr<Impl> _impl;
        };

        template<>
        DECL_CS_CORE int CSConfig::GetValue<int>(const cs::base::CSString& key) const;
        template<>
        DECL_CS_CORE bool CSConfig::GetValue<bool>(const cs::base::CSString& key) const;
        template<>
        DECL_CS_CORE double CSConfig::GetValue<double>(const cs::base::CSString& key) const;
        template<>
        DECL_CS_CORE cs::base::CSString CSConfig::GetValue<cs::base::CSString>(const cs::base::CSString& key) const;


    } // namespace core

} // namespace cs
