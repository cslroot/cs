#pragma once

#include <cs/modeler/modeler_common.h>
#include <cs/base.h>
#include <cs/core.h>

#include <memory>

namespace cs
{
    namespace modeler
    {
        class DECL_CS_MODELER Modeler
        {
        public:
            Modeler();
            virtual ~Modeler();

        public:

            cs::core::Body& CreateBox(const cs::base::CSVec3d& p1, const cs::base::CSVec3d& p2);

        private:
            struct Impl;
            std::unique_ptr<Impl> _impl;
        };

    } // namespace modeler

} // namespace cs
