#pragma once

#include <cs/render/render_common.h>
#include <cs/render_fwd.h>

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

        public:
            void Render(const Scene& scene, const Camera& camera);
        };

        class DECL_CS_RENDER GLRenderer : public Renderer
        {};

    } // namespace render

} // namespace cs
