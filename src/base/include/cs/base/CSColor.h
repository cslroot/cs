#pragma once

#include <array>
#include <cs/base/CSString.h>
#include <cs/base/base_common.h>

namespace cs {
namespace base {

constexpr float ColorToFloat = 1.0f / 255.0f;

class CSColor
{
public:
  DECL_CS_BASE CSColor()
    : CSColor(1.0f, 1.0f, 1.0f)
  {}

  DECL_CS_BASE CSColor(float r, float g, float b)
    : _r(r)
    , _g(g)
    , _b(b)
  {}

  DECL_CS_BASE CSColor(float r, float g, float b, float a)
    : _r(r)
    , _g(g)
    , _b(b)
    , _a(a)
  {}

  DECL_CS_BASE CSColor(
    const std::array<float, 3>& col) // cppcheck-suppress noExplicitConstructor
    : _r(col[0])
    , _g(col[1])
    , _b(col[2])
  {}

  explicit DECL_CS_BASE CSColor(uint32_t colorHexRGB)
    : _r(ColorToFloat * ((colorHexRGB & 0xFF0000) >> 16))
    , _g(ColorToFloat * ((colorHexRGB & 0xFF00) >> 8))
    , _b(ColorToFloat * ((colorHexRGB & 0xFF) >> 0))
  {}

  // "#ff0000" -> 1.0, 0.0, 0.0
  explicit DECL_CS_BASE CSColor(const CSString& colorHexStr)
  {
    auto tmp = colorHexStr.Replace('#', '\0');
    int colorHex = tmp.ParseInt();

    _r = ColorToFloat * ((colorHex & 0xFF0000) >> 16);
    _g = (ColorToFloat * ((colorHex & 0xFF00) >> 8));
    _b = (ColorToFloat * ((colorHex & 0xFF) >> 0));
  }

  DECL_CS_BASE virtual ~CSColor() {}

public:
  float R() const { return _r; }
  float G() const { return _g; }
  float B() const { return _b; }
  float A() const { return _a; }

private:
  float _r;
  float _g;
  float _b;
  float _a = 1.0;
};

} // namespace base
} // namespace cs
