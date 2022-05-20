#include "kernel2d/Segment2d.h"

#include <cs/core/CSBufferObject.h>
#include <cs/math.h>
#include <memory>
#include <vector>

using namespace cs::base;
using namespace cs::core;
using namespace cs::kernel;
using namespace cs::math;

struct Segment2d::Impl
{
  CSVec2d _p1;
  CSVec2d _p2;
};

Segment2d::Segment2d()
  : _impl(std::make_unique<Impl>())
{}

Segment2d::Segment2d(const cs::math::CSVec2d& p1, const cs::math::CSVec2d& p2)
  : _impl(std::make_unique<Impl>())
{
  _impl->_p1 = p1;
  _impl->_p2 = p2;
}

Segment2d::~Segment2d() = default;

const cs::math::CSVec2d&
Segment2d::StartPoint() const
{
  return _impl->_p1;
}
const cs::math::CSVec2d&
Segment2d::EndPoint() const
{
  return _impl->_p2;
}

template<typename T>
struct array_deleter
{
  void operator()(T const* p) { delete[] p; }
};

std::shared_ptr<CSBufferObject>
Segment2d::GenerateBuffer() const
{
  std::shared_ptr<CSBufferObject> buffer = std::make_shared<CSBufferObject>();

  buffer->_points.emplace_back(_impl->_p1.x);
  buffer->_points.emplace_back(_impl->_p1.y);
  buffer->_points.emplace_back(_impl->_p2.x);
  buffer->_points.emplace_back(_impl->_p2.y);

  return buffer;
}
