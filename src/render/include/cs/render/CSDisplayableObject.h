#pragma once

#include <cs/render/render_common.h>

namespace cs
{
    namespace render
    {
        class DECL_CS_RENDER CSDisplayableObject
        {
        private:
            /* data */
        public:
            CSDisplayableObject(/* args */) : _visible(true) {}
            ~CSDisplayableObject() {}

        public:
            void Show() { _visible = true; }
            void Hide() { _visible = false; }

        private:
            bool _visible;
        };
    } // namespace render

} // namespace cs
