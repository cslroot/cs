#include <cs/base.h>
#include <gtest/gtest.h>
#include <stdexcept>

using namespace cs;
using namespace cs::base;

TEST(TestCSString, default_param)
{
  CSString str;
  EXPECT_STREQ(str.c_str(), "");
}

TEST(TestCSString, ctor)
{
  CSString str("abc");
  EXPECT_STREQ(str.c_str(), "abc");
}

TEST(TestCSString, opePlus)
{
  CSString str1("abc");
  CSString str2("def");
  CSString str = str1 + str2;
  EXPECT_STREQ(str.c_str(), "abcdef");
}

TEST(TestCSString, replace)
{
  CSString str1("AbcabcA");
  CSString str = str1.Replace('A', 'X');
  EXPECT_STREQ(str.c_str(), "XbcabcX");

  CSString str2 = str1.Replace('A', '\0');
  EXPECT_STREQ(str2.c_str(), "bcabc");
}
