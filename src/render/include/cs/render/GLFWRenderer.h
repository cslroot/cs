#pragma once

#include <cs/render/render_common.h>
#include <cs/render/Renderer.h>

#include <memory>

namespace cs
{
    namespace render
    {
        class  GLFWRenderer : public Renderer
        {
        public:
            DECL_CS_RENDER GLFWRenderer();
            DECL_CS_RENDER ~GLFWRenderer();
        public:
            DECL_CS_RENDER virtual void Init() override;
            DECL_CS_RENDER virtual void Terminate() override;

            DECL_CS_RENDER void Render(const Scene& scene, const Camera& camera) override;
            DECL_CS_RENDER virtual void Resize(int width, int height) override;
            DECL_CS_RENDER virtual bool WindowShouldClose() override;

        private:
            struct Impl;
            std::unique_ptr<Impl> _impl;
        };

    } // namespace render

} // namespace cs
