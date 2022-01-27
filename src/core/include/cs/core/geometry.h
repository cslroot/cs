#pragma once

#include <cs/core/core_common.h>
#include <cs/core/entity.h>

namespace cs
{
    namespace core
    {
        class DECL_CS_CORE Geometry : public Entity
        {
        public:
            Geometry() {}
            virtual ~Geometry() {}
        };
    } // namespace core

} // namespace cs
