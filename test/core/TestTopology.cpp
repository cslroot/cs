#include <cs/base.h>
#include <cs/core/Topology.h>
#include <gtest/gtest.h>
#include <stdexcept>

using namespace cs;
using namespace cs::core;

TEST(TestTopology, GetType)
{
  Vertex* v = CS_NEW Vertex();
  EXPECT_EQ(v->GetType(), TopologyType::Vertex);
}
