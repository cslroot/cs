#pragma once

#include <cs/render/render_common.h>
#include <cs/render_fwd.h>

namespace cs
{
    namespace render
    {
        class DECL_CS_RENDER Scene
        {
        private:
            /* data */
        public:
            Scene(/* args */);
            ~Scene();

        public:
            void Add(const cs::render::Mesh& mesh);
        };
    } // namespace render

} // namespace cs
