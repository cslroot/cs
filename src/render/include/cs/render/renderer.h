#pragma once

#include <cs/render/render_common.h>

namespace cs
{
    namespace render
    {
        class DECL_CS_RENDER Renderer
        {
        private:
            /* data */
        public:
            Renderer(/* args */);
            ~Renderer();
        };

        class DECL_CS_RENDER GLRenderer : public Renderer
        {};

    } // namespace render

} // namespace cs
