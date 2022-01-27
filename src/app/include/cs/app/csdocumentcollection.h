#pragma once

#include <cs/app/app_common.h>
#include <cs/base_fwd.h>
#include <memory>

#include <cs/base/ICSCollection.h>

namespace cs
{
    namespace app
    {
        class CSDocument;
        class CSDocumentCollection : cs::base::ICSCollection<CSDocument>
        {
        private:
            /* data */
        public:
            DECL_CS_APP CSDocumentCollection();
            DECL_CS_APP ~CSDocumentCollection();

        public:
            void Add(std::shared_ptr<CSDocument>& doc) override;
            void Clear() override;
            size_t Size() const override;

        private:
            struct Impl;
            std::unique_ptr<Impl> _impl;
        };


    } // namespace app

} // namespace cs
