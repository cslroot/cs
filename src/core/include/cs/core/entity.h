#pragma once

#include <cs/core/core_common.h>

#include <cstdint>

namespace cs
{
    namespace core
    {
        class DECL_CS_CORE Entity
        {
        public:
            Entity();
            virtual ~Entity();

        private:
            int64_t _id;
        };
    } // namespace core

} // namespace cs
