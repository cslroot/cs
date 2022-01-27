#pragma once

#include <cs/app/app_common.h>

#include <memory>

namespace cs
{
    namespace app
    {
        class CSDocument;
        class CSDocumentCollection;

        class DECL_CS_APP CSApp
        {
        public:
            CSApp(int argc, char** argv);
            virtual ~CSApp();

        public:
            CSDocument& OpenNewDocument();
            CSDocumentCollection& Documents() const;

        private:
            struct Impl;
            std::unique_ptr<Impl> _impl;
        };


    } // namespace app

} // namespace cs
