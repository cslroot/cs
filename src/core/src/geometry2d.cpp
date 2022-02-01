#include "geometry2d.h"

#include <cs/base/csvector.h>


using  namespace cs::base;
using  namespace cs::core;

struct LineSegment2d::Impl
{
    CSVec2d _p1;
    CSVec2d _p2;
};


LineSegment2d::LineSegment2d()
    : _impl(std::make_unique<Impl>())
{}
LineSegment2d::~LineSegment2d()
{}
