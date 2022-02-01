#pragma once

#include <cs/core/core_common.h>
#include <cs/core/geometry.h>
#include <cs/base_fwd.h>

#include <memory>

namespace cs
{
    namespace core
    {
        class DECL_CS_CORE Geometry2d : public Geometry
        {
        public:
            Geometry2d() {}
            virtual ~Geometry2d() {}
        };

        class  LineSegment2d : public Geometry2d
        {
        public:
            DECL_CS_CORE LineSegment2d();
            DECL_CS_CORE virtual ~LineSegment2d();
        private:
            struct Impl;
            std::unique_ptr<Impl> _impl;
        };
    } // namespace core

} // namespace cs
