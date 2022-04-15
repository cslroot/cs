#include "geometry2d/geometry2d.h"

#include <cs/base/csvector.h>
#include <cs/core/CSBufferObject.h>
#include <vector>
#include <memory>

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

LineSegment2d::LineSegment2d(const cs::base::CSVec2d& p1, const cs::base::CSVec2d& p2)
    : _impl(std::make_unique<Impl>())
{
    _impl->_p1 = p1;
    _impl->_p2 = p2;
}

LineSegment2d::~LineSegment2d()
{}

const cs::base::CSVec2d& LineSegment2d::StartPoint() const
{
    return _impl->_p1;
}
const cs::base::CSVec2d& LineSegment2d::EndPoint() const
{
    return _impl->_p2;
}


template< typename T >
struct array_deleter
{
    void operator ()(T const* p)
    {
        delete[] p;
    }
};

std::shared_ptr<CSBufferObject> LineSegment2d::GenerateBuffer() const
{
    std::shared_ptr<CSBufferObject> buffer = std::make_shared<CSBufferObject>();

    buffer->_points.emplace_back(_impl->_p1.x);
    buffer->_points.emplace_back(_impl->_p1.y);
    buffer->_points.emplace_back(_impl->_p2.x);
    buffer->_points.emplace_back(_impl->_p2.y);

    return buffer;
}

