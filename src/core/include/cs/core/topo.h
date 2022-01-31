#pragma once

#include <cs/core/core_common.h>
#include <cs/core/entity.h>

namespace cs
{
    namespace core
    {
        enum class TopologyType
        {
            INVALID,
            Vertex,
            CoEdge,
            Edge,
            Loop,
            Wire,
            Face,
            Shell,
            Lump,
            Body,
            Last = Body
        };

        class DECL_CS_CORE Topology : public Entity
        {
        public:
            Topology() {}
            virtual ~Topology() {}

        public:
            virtual TopologyType GetType() const = 0;
        };

        class DECL_CS_CORE Vertex : public Topology
        {
        public:
            virtual TopologyType GetType() const override { return TopologyType::Vertex; }
        };

        class DECL_CS_CORE CoEdge : public Topology
        {
        public:
            virtual TopologyType GetType() const override { return TopologyType::CoEdge; }
        };

        class DECL_CS_CORE Edge : public Topology
        {
        public:
            virtual TopologyType GetType() const override { return TopologyType::Edge; }
        };

        class DECL_CS_CORE Loop : public Topology
        {
        public:
            virtual TopologyType GetType() const override { return TopologyType::Loop; }
        };

        class DECL_CS_CORE Face : public Topology
        {
        public:
            virtual TopologyType GetType() const override { return TopologyType::Face; }
        };

        class DECL_CS_CORE Shell : public Topology
        {
        public:
            virtual TopologyType GetType() const override { return TopologyType::Shell; }
        };

        class DECL_CS_CORE Lump : public Topology
        {
        public:
            virtual TopologyType GetType() const override { return TopologyType::Lump; }
        };

        class DECL_CS_CORE Wire : public Topology
        {
        public:
            virtual TopologyType GetType() const override { return TopologyType::Wire; }
        };

        class DECL_CS_CORE Body : public Topology
        {
        public:
            virtual TopologyType GetType() const override { return TopologyType::Body; }
        };
    } // namespace core

} // namespace cs
