#pragma once

#include <cs/core/core_common.h>

#include <cstdint>

namespace cs
{
    namespace core
    {
        enum class EntityType
        {
            Point,
            Surface,
            Shell,
            Vertex,
            Edge,
            Body,
        };

        class DECL_CS_CORE Entity
        {
        public:
            Entity();
            virtual ~Entity();

        private:
            int64_t _id;
            EntityType _entType;
        };
    } // namespace core

} // namespace cs
