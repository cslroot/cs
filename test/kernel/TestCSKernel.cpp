#include <array>
#include <cs/kernel.h>
#include <gtest/gtest.h>
#include <stdexcept>

using namespace cs;
using namespace cs::kernel;

TEST(TestCSKernel, ctorDefault)
{
  CSKernel kernel;
}
TEST(TestCSKernel, IsInitialized)
{
  CSKernel kernel;
  bool initialized = kernel.IsInitialized();
  // EXPECT_EQ(kernel.IsInitialized(), true);
}
