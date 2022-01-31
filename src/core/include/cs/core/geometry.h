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

        class DECL_CS_CORE Point : public Geometry
        {};
        class DECL_CS_CORE Curve : public Geometry
        {};
        class DECL_CS_CORE Surface : public Geometry
        {};
    } // namespace core

} // namespace cs
