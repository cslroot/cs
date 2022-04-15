#pragma once

#include <cs/core/core_common.h>
#include <cs/core/geometry.h>
#include <cs/base_fwd.h>

#include <memory>

namespace cs
{
    namespace core
    {
        class CSBufferObject;

        class DECL_CS_CORE Geometry2d : public Geometry
        {
        public:
            Geometry2d() {}
            virtual ~Geometry2d() {}
        };

        class LineSegment2d : public Geometry2d
        {
        public:
            DECL_CS_CORE LineSegment2d();
            DECL_CS_CORE LineSegment2d(const cs::base::CSVec2d& p1, const cs::base::CSVec2d& p2);
            DECL_CS_CORE virtual ~LineSegment2d();

            DECL_CS_CORE const cs::base::CSVec2d& StartPoint() const;
            DECL_CS_CORE const cs::base::CSVec2d& EndPoint() const;

            DECL_CS_CORE virtual std::shared_ptr<CSBufferObject> GenerateBuffer() const override;
        private:
            struct Impl;
            std::unique_ptr<Impl> _impl;
        };
    } // namespace core

} // namespace cs
