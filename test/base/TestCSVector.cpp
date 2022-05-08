#include <cs/math.h>
#include <gtest/gtest.h>
#include <stdexcept>

using namespace cs;
using namespace cs::math;

TEST(TestCSVector, default_param)
{
  CSVec3d v;
  EXPECT_EQ(v.x, 0.0);
  EXPECT_EQ(v.y, 0.0);
  EXPECT_EQ(v.z, 0.0);
}

TEST(TestCSVector, param)
{
  CSVec3d v({ 1.0, 2.0, 3.0 });
  EXPECT_EQ(v.x, 1.0);
  EXPECT_EQ(v.y, 2.0);
  EXPECT_EQ(v.z, 3.0);
}

TEST(TestCSVector, param_array)
{
  CSVec3d v = { { 1.0, 2.0, 3.0 } };
  EXPECT_EQ(v.x, 1.0);
  EXPECT_EQ(v.y, 2.0);
  EXPECT_EQ(v.z, 3.0);
}

TEST(TestCSVector, opepluseq)
{
  CSVec3d v({ 1.0, 2.0, 3.0 });
  CSVec3d v2({ 4.0, 5.0, 6.0 });
  v += v2;

  EXPECT_EQ(v.x, 5.0);
  EXPECT_EQ(v.y, 7.0);
  EXPECT_EQ(v.z, 9.0);
}

TEST(TestCSVector, opescale)
{
  CSVec3d v({ 1, 2, 3 });
  v *= 2;

  EXPECT_EQ(v.x, 2.0);
  EXPECT_EQ(v.y, 4.0);
  EXPECT_EQ(v.z, 6.0);
}

TEST(TestCSVector, opediv)
{
  CSVec3d v({ 1, 2, 3 });
  v /= 2;

  EXPECT_EQ(v.x, 0.5);
  EXPECT_EQ(v.y, 1.0);
  EXPECT_EQ(v.z, 1.5);
}

TEST(TestCSVector, length)
{
  CSVec3d v({ 0.0, 0.0, 0.0 });
  EXPECT_EQ(v.length(), 0.0);

  v = CSVec3d({ 1.0, 1.0, 0.0 });
  EXPECT_EQ(v.length(), std::sqrt(2));
}
