#include <array>
#include <cs/kernel.h>
#include <gtest/gtest.h>
#include <stdexcept>

using namespace cs;
using namespace cs::kernel;

TEST(TestEntity, ctorDefault)
{
  Entity ent(EntityType::Point);
}
