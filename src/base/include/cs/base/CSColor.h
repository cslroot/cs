#pragma once

#include <array>
#include <cs/base/CSString.h>
#include <cs/base/common.h>

namespace cs {
inline namespace base {

constexpr float ColorToFloat = 1.0f / 255.0f;
constexpr int ColorToInt = 255;

class CSColor
{
public:
  DECL_CS_BASE CSColor()
    : CSColor(0.0f, 0.0f, 0.0f)
  {}

  DECL_CS_BASE CSColor(float r, float g, float b)
    : CSColor(r, g, b, 1.0f)
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
    , _g(ColorToFloat * ((colorHexRGB & 0x00FF00) >> 8))
    , _b(ColorToFloat * ((colorHexRGB & 0x0000FF) >> 0))
  {}

  // "#ff0000" -> 1.0, 0.0, 0.0
  explicit DECL_CS_BASE CSColor(const CSString& colorHexStr)
  {
    auto tmp = colorHexStr.Replace('#', '\0');
    tmp = "0x" + tmp;
    unsigned int colorHexRGB = tmp.ParseUint();

    _r = ColorToFloat * ((colorHexRGB & 0xFF0000) >> 16);
    _g = ColorToFloat * ((colorHexRGB & 0x00FF00) >> 8);
    _b = ColorToFloat * ((colorHexRGB & 0x0000FF) >> 0);
  }

  DECL_CS_BASE virtual ~CSColor() = default;

public:
  DECL_CS_BASE uint32_t ToRGBA() const
  {
    return static_cast<uint32_t>(ColorToInt * _r) << 24 |
           static_cast<uint32_t>(ColorToInt * _g) << 16 |
           static_cast<uint32_t>(ColorToInt * _b) << 8 |
           static_cast<uint32_t>(ColorToInt * _a) << 0;
  }
  DECL_CS_BASE uint32_t ToRGB() const
  {
    return static_cast<uint32_t>(ColorToInt * _r) << 16 |
           static_cast<uint32_t>(ColorToInt * _g) << 8 |
           static_cast<uint32_t>(ColorToInt * _b) << 0;
  }

public:
  inline float R() const { return _r; }
  inline float G() const { return _g; }
  inline float B() const { return _b; }
  inline float A() const { return _a; }
  void SetRGB(uint32_t colorHexRGB)
  {
    _r = ColorToFloat * ((colorHexRGB & 0xFF0000) >> 16);
    _g = ColorToFloat * ((colorHexRGB & 0x00FF00) >> 8);
    _b = ColorToFloat * ((colorHexRGB & 0x0000FF) >> 0);
  }

private:
  float _r;
  float _g;
  float _b;
  float _a = 1.0;
};

} // namespace base
} // namespace cs
