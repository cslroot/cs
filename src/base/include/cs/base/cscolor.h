#pragma once

#include <cs/base/base_common.h>

#include <array>

namespace cs
{
    namespace base
    {
        class CSColor
        {
        public:
            DECL_CS_BASE CSColor(float r, float g, float b)
                : _r(r), _g(g), _b(b)
            {}

            DECL_CS_BASE CSColor(const std::array<float, 3>& col)
                : _r(col[0])
                , _g(col[1])
                , _b(col[2])
            {}

            DECL_CS_BASE virtual ~CSColor() {}

        public:

        private:
            float _r;
            float _g;
            float _b;
        };


    } // namespace base
} // namespace cs
