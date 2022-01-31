#include <cs/base.h>
#include <cs/core/topology.h>
#include <stdexcept>
#include <gtest/gtest.h>

using namespace cs;
using namespace cs::core;


TEST(TestTopology, GetType)
{
    Vertex* v = CS_NEW Vertex();
    EXPECT_EQ(v->GetType(), TopologyType::Vertex);
}

