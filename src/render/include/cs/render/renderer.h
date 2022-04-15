#pragma once

#include <cs/render/render_common.h>
#include <cs/render_fwd.h>

namespace cs
{
    namespace render
    {
        class Renderer
        {
        private:
            /* data */
        public:
            Renderer(/* args */);
            ~Renderer();

        public:
            DECL_CS_RENDER virtual void Init() {}
            DECL_CS_RENDER virtual void Terminate() {}
            DECL_CS_RENDER virtual void Render(const Scene& scene, const Camera& camera);
            DECL_CS_RENDER virtual void Resize(int width, int height);
            DECL_CS_RENDER virtual bool WindowShouldClose() { return false; }

        private:
            int _width;
            int _height;

        };

        class DECL_CS_RENDER GLRenderer : public Renderer
        {};
    } // namespace render

} // namespace cs
