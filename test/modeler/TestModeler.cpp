#include <array>
#include <cs/math.h>
#include <cs/modeler.h>
#include <gtest/gtest.h>
#include <stdexcept>

using namespace cs;
using namespace cs::math;
using namespace cs::modeler;

TEST(TestCSModeler, ctorDefault)
{
  CSModeler modeler;
}

TEST(TestCSModeler, CreateBox)
{
  CSModeler modeler;
  CSVec3d p1({ 0, 0, 0 });
  CSVec3d p2({ 1.0, 2.0, 3.0 });
  modeler.CreateBox(p1, p2);
}
