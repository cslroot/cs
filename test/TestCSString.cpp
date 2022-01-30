#include <cs/base.h>
#include <stdexcept>
#include <gtest/gtest.h>

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

