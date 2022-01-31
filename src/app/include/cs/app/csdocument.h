#pragma once

#include <cs/app/app_common.h>
#include <cs/base_fwd.h>
#include <cs/modeler_fwd.h>
#include <cs/core/csobject.h>

#include <memory>

namespace cs
{
    namespace app
    {
        class CSDocument : public cs::core::CSObject
        {
        private:
            /* data */
        public:
            DECL_CS_APP CSDocument();
            DECL_CS_APP ~CSDocument();

        public:
            DECL_CS_APP void SaveAs(const cs::base::CSString& filepath);

        public:
            DECL_CS_APP cs::modeler::CSModeler& Modeler() const;

        private:
            struct Impl;
            std::unique_ptr<Impl> _impl;
        };


    } // namespace app

} // namespace cs
