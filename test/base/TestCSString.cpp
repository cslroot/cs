#include <cs/base.h>
#include <gtest/gtest.h>
#include <stdexcept>

using namespace cs;
using namespace cs::base;

TEST(TestCSString, ctorDefault)
{
  CSString str;
  EXPECT_STREQ(str.c_str(), "");
}
TEST(TestCSString, CreateFromHex)
{
  void* pNull = nullptr;
  CSString str = CSString::CreateFromHex(pNull);
  EXPECT_STREQ(str.c_str(), "0000000000000000");
}
TEST(TestCSString, ctorStr)
{
  CSString str("abc");
  EXPECT_STREQ(str.c_str(), "abc");
}
TEST(TestCSString, ctorWStr)
{
  CSString str(L"abc");
  std::wstring wstr = L"def";
  CSString str2(wstr);

  EXPECT_STREQ(str.c_str(), "abc");
  EXPECT_STREQ(str2.c_str(), "def");

  CSString strNull(L"");
  EXPECT_STREQ(strNull.c_str(), "");
}
TEST(TestCSString, opePlus)
{
  CSString str1("abc");
  CSString str2("def");
  CSString str = str1 + str2;
  EXPECT_STREQ(str.c_str(), "abcdef");
}

TEST(TestCSString, opePlusEq)
{
  CSString str1("abc");
  CSString str2("def");
  CSString str;
  str += str1;
  str += str2;
  str += u8"ghi";
  EXPECT_STREQ(str.c_str(), "abcdefghi");
}

TEST(TestCSString, opeOstream)
{
  CSString str1("abc");
  CSString str2("def");
  std::ostringstream oss;
  oss << str1 << " " << str2;

  EXPECT_STREQ(oss.str().c_str(), "abc def");
}

TEST(TestCSString, replace)
{
  CSString str1("AbcabcA");
  CSString str = str1.Replace('A', 'X');
  EXPECT_STREQ(str.c_str(), "XbcabcX");
  EXPECT_STREQ(str1.c_str(), "AbcabcA");

  CSString str2 = str1.Replace('A', '\0');
  EXPECT_STREQ(str2.c_str(), "bcabc");

  // string version
  CSString str3 = str1.Replace("bc", "BC");
  EXPECT_STREQ(str3.c_str(), "ABCaBCA");
}

TEST(TestCSString, ParseInt)
{
  CSString str1("123");
  EXPECT_EQ(str1.ParseInt(), 123);

  CSString str2("0xF");
  EXPECT_EQ(str2.ParseInt(), 15);

  CSString str3("010");
  EXPECT_EQ(str3.ParseInt(), 8);
}

TEST(TestCSString, ParseUint)
{
  CSString str1("123");
  EXPECT_EQ(str1.ParseUint(), 123U);

  CSString str2("0xff");
  EXPECT_EQ(str2.ParseUint(), 255U);

  CSString str3("010");
  EXPECT_EQ(str3.ParseUint(), 8);
}
