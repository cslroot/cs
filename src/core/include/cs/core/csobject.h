#pragma once

#include <cs/core/core_common.h>
#include <cs/base_fwd.h>
#include <memory>


namespace cs
{
    namespace core
    {
        class CSObject
        {
        public:
            DECL_CS_CORE CSObject();
            DECL_CS_CORE virtual ~CSObject();

        public:
            DECL_CS_CORE const cs::base::CSString& Name() const;
            DECL_CS_CORE void SetName(const cs::base::CSString& name);

        private:
            struct Impl;
            std::unique_ptr<Impl> _impl;
        };
    } // namespace core

} // namespace cs
