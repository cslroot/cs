#pragma once

#include <cs/core/core_common.h>
#include <cs/core/entity.h>
#include <cs/base_fwd.h>

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

        class DECL_CS_CORE Geometry3d : public Geometry
        {
        public:
            Geometry3d() {}
            virtual ~Geometry3d() {}
        };

        class DECL_CS_CORE Point : public Geometry3d
        {};
        class DECL_CS_CORE Curve : public Geometry3d
        {};
        class DECL_CS_CORE Surface : public Geometry3d
        {};
    } // namespace core

} // namespace cs
