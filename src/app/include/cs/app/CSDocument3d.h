#pragma once

#include <cs/app/app_common.h>
#include <cs/app/csdocument.h>

namespace cs
{
    namespace app
    {
        class CSDocument3d : public CSDocument::Registrar<CSDocument3d>
        {
        public:
            DECL_CS_APP CSDocument3d(const cs::base::CSString&) {}
            DECL_CS_APP ~CSDocument3d() {}
        };
    } // namespace app

} // namespace cs
