#include <cs/base.h>
#include <gtest/gtest.h>
#include <stdexcept>

using namespace cs;
using namespace cs::base;

TEST(TestCSColor, default_param)
{
  CSColor v;
  EXPECT_EQ(v.R(), 0.0f);
  EXPECT_EQ(v.G(), 0.0f);
  EXPECT_EQ(v.B(), 0.0f);
  EXPECT_EQ(v.A(), 1.0f);
}

TEST(TestCSColor, ctor_with_rgb)
{
  CSColor v(1.0f, 0.5f, 0.0f);
  EXPECT_EQ(v.R(), 1.0f);
  EXPECT_EQ(v.G(), 0.5f);
  EXPECT_EQ(v.B(), 0.0f);
  EXPECT_EQ(v.A(), 1.0f);
}

TEST(TestCSColor, ctor_with_rgba)
{
  CSColor v(1.0f, 0.5f, 0.0f, 0.25f);
  EXPECT_EQ(v.R(), 1.0f);
  EXPECT_EQ(v.G(), 0.5f);
  EXPECT_EQ(v.B(), 0.0f);
  EXPECT_EQ(v.A(), 0.25f);
}

TEST(TestCSColor, ctor_with_array)
{
  CSColor v({ 1.0f, 0.5f, 0.0f });
  EXPECT_EQ(v.R(), 1.0f);
  EXPECT_EQ(v.G(), 0.5f);
  EXPECT_EQ(v.B(), 0.0f);
  EXPECT_EQ(v.A(), 1.0f);
}

TEST(TestCSColor, ctor_with_rgbHex)
{
  CSColor v(0xff0100U);
  EXPECT_EQ(v.R(), 1.0f);
  EXPECT_EQ(v.G(), 1.0f / 255.0f);
  EXPECT_EQ(v.B(), 0.0f);
  EXPECT_EQ(v.A(), 1.0f);
}

TEST(TestCSColor, ctor_with_rgbHexStr)
{
  CSColor v("ff0100");
  EXPECT_EQ(v.R(), 1.0f);
  EXPECT_EQ(v.G(), 1.0f / 255.0f);
  EXPECT_EQ(v.B(), 0.0f);
  EXPECT_EQ(v.A(), 1.0f);

  v = CSColor("#ff0100");
  EXPECT_EQ(v.R(), 1.0f);
  EXPECT_EQ(v.G(), 1.0f / 255.0f);
  EXPECT_EQ(v.B(), 0.0f);
  EXPECT_EQ(v.A(), 1.0f);
}

TEST(TestCSColor, ToRGBA)
{
  CSColor v((uint32_t)0xff0100);
  EXPECT_EQ(v.R(), 1.0f);
  EXPECT_EQ(v.G(), 1.0f / 255.0f);
  EXPECT_EQ(v.B(), 0.0f);

  auto rgba = v.ToRGBA();
  EXPECT_EQ(rgba, 0xff0100ffU);

  v.SetRGB(0xffffff);
  EXPECT_EQ(v.ToRGBA(), 0xffffffffU);
}

TEST(TestCSColor, ToRGB)
{
  CSColor v(0xffffffU);
  auto rgb = v.ToRGB();
  EXPECT_EQ(rgb, 0xffffffU);
}
