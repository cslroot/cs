#include <cs/base.h>
#include <cs/kernel/Topology.h>
#include <gtest/gtest.h>
#include <stdexcept>

using namespace cs;
using namespace cs::core;
using namespace cs::kernel;

TEST(TestTopology, GetType)
{
  Vertex v;
  EXPECT_EQ(v.TopologyType(), TopologyTypes::Vertex);
}
