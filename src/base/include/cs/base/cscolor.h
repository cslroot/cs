#pragma once

#include <cs/base/base_common.h>
#include <cs/base/csstring.h>
#include <array>

namespace cs
{
    namespace base
    {
        class CSColor
        {
            const float ToFloat = 1.0f / 255.0f;
        public:
            DECL_CS_BASE CSColor(float r, float g, float b)
                : _r(r), _g(g), _b(b)
            {}

            DECL_CS_BASE CSColor(const std::array<float, 3>& col)   // cppcheck-suppress noExplicitConstructor
                : _r(col[0])
                , _g(col[1])
                , _b(col[2])
            {}

            explicit DECL_CS_BASE CSColor(uint32_t colorHex)
                : _r(ToFloat* ((colorHex & 0xFF0000) >> 16))
                , _g(ToFloat* ((colorHex & 0xFF00) >> 8))
                , _b(ToFloat* ((colorHex & 0xFF) >> 0))
            {}

            // "#ff0000" -> 1.0, 0.0, 0.0
            explicit DECL_CS_BASE CSColor(const CSString& colorHexStr)
            {
                auto tmp = colorHexStr.Replace('#', '\0');
                int colorHex = tmp.ParseInt();

                _r = ToFloat * ((colorHex & 0xFF0000) >> 16);
                _g = (ToFloat * ((colorHex & 0xFF00) >> 8));
                _b = (ToFloat * ((colorHex & 0xFF) >> 0));
            }

            DECL_CS_BASE virtual ~CSColor() {}

        public:

        private:
            float _r;
            float _g;
            float _b;
        };


    } // namespace base
} // namespace cs
