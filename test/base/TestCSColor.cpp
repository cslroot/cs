#include <cs/base.h>
#include <gtest/gtest.h>
#include <stdexcept>

using namespace cs;
using namespace cs::base;

TEST(TestCSColor, ctorDefault)
{
  CSColor v;
  EXPECT_EQ(v.R(), 0.0F);
  EXPECT_EQ(v.G(), 0.0F);
  EXPECT_EQ(v.B(), 0.0F);
  EXPECT_EQ(v.A(), 1.0F);
}

TEST(TestCSColor, ctorWithRGB)
{
  CSColor v(1.0F, 0.5F, 0.0F);
  EXPECT_EQ(v.R(), 1.0F);
  EXPECT_EQ(v.G(), 0.5F);
  EXPECT_EQ(v.B(), 0.0F);
  EXPECT_EQ(v.A(), 1.0F);
}

TEST(TestCSColor, ctorWithRGBA)
{
  CSColor v(1.0F, 0.5F, 0.0F, 0.25F);
  EXPECT_EQ(v.R(), 1.0F);
  EXPECT_EQ(v.G(), 0.5F);
  EXPECT_EQ(v.B(), 0.0F);
  EXPECT_EQ(v.A(), 0.25F);
}

TEST(TestCSColor, ctorWithArray)
{
  CSColor v(std::array<float, 3>{ 1.0F, 0.5F, 0.0F });
  EXPECT_EQ(v.R(), 1.0F);
  EXPECT_EQ(v.G(), 0.5F);
  EXPECT_EQ(v.B(), 0.0F);
  EXPECT_EQ(v.A(), 1.0F);
}

TEST(TestCSColor, ctorWithRGBHex)
{
  CSColor v(0xff0100U);
  EXPECT_EQ(v.R(), 1.0F);
  EXPECT_EQ(v.G(), 1.0F / 255.0F);
  EXPECT_EQ(v.B(), 0.0F);
  EXPECT_EQ(v.A(), 1.0F);
}

TEST(TestCSColor, ctorWithRGBHexStr)
{
  CSColor v("ff0100");
  EXPECT_EQ(v.R(), 1.0F);
  EXPECT_EQ(v.G(), 1.0F / 255.0F);
  EXPECT_EQ(v.B(), 0.0F);
  EXPECT_EQ(v.A(), 1.0F);

  v = CSColor("#ff0100");
  EXPECT_EQ(v.R(), 1.0F);
  EXPECT_EQ(v.G(), 1.0F / 255.0F);
  EXPECT_EQ(v.B(), 0.0F);
  EXPECT_EQ(v.A(), 1.0F);
}

TEST(TestCSColor, ToRGBA)
{
  CSColor v((uint32_t)0xff0100);
  EXPECT_EQ(v.R(), 1.0F);
  EXPECT_EQ(v.G(), 1.0F / 255.0F);
  EXPECT_EQ(v.B(), 0.0F);

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
