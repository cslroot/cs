#pragma once

#include <cs/app/app_common.h>
#include <cs/app/csdocument.h>

namespace cs
{
    namespace app
    {
        class CSDocument2d : public CSDocument::Registrar<CSDocument2d>
        {
        public:
            DECL_CS_APP CSDocument2d(int x) {}
            DECL_CS_APP ~CSDocument2d() {}

        private:
        };


    } // namespace app

} // namespace cs
