#pragma once

#include <cs/core/core_common.h>
#include <cs/core/csobject.h>
#include <cstdint>

namespace cs
{
    namespace core
    {
        enum class EntityType
        {
            None,
            Point,
            Surface,
            Shell,
            Vertex,
            Edge,
            Body,
        };

        class DECL_CS_CORE Entity : public CSObject
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
