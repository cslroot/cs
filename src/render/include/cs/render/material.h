#pragma once

#include <cs/render/render_common.h>
#include <cs/base_fwd.h>

namespace cs
{
    namespace render
    {
        class DECL_CS_RENDER Material
        {
        private:
            /* data */
        public:
            Material(/* args */) {}
            ~Material() {}
        };

        class DECL_CS_RENDER BasicMaterial : public Material
        {
        public:
            explicit BasicMaterial(const cs::base::CSColor& color);

        private:
            const cs::base::CSColor& _color;
        };
    } // namespace render

} // namespace cs
