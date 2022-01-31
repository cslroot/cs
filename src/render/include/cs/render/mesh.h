#pragma once

#include <cs/render/render_common.h>
#include <cs/render_fwd.h>
#include <cs/render/CSDisplayableObject.h>
#include <cs/base_fwd.h>
#include <cs/core_fwd.h>


namespace cs
{
    namespace render
    {
        class DECL_CS_RENDER Mesh : public CSDisplayableObject
        {
        private:
            /* data */
        public:
            Mesh(const cs::core::Entity& entity, const cs::render::Material& material) {}
            ~Mesh() {}
        };
    } // namespace render

} // namespace cs
