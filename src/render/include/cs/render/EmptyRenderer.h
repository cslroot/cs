#pragma once

#include <cs/render/Renderer.h>
#include <cs/render_fwd.h>

namespace cs
{
    namespace render
    {
        class EmptyRenderer : public Renderer
        {
        private:
            /* data */
        public:
            DECL_CS_RENDER EmptyRenderer(/* args */) {}
            DECL_CS_RENDER ~EmptyRenderer() {}
        };

    } // namespace render

} // namespace cs
