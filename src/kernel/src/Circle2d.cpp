#include "kernel2d/Circle2d.h"

#include <cs/base/CSVector.h>
#include <cs/core/CSBufferObject.h>
#include <cs/math.h>

#include <memory>
#include <vector>

using namespace cs::base;
using namespace cs::core;
using namespace cs::math;
using namespace cs::kernel;

struct Circle2d::Impl
{
  CSVec2d _center;
  double _radius;
};

Circle2d::Circle2d()
  : _impl(std::make_unique<Impl>())
{}

Circle2d::Circle2d(const cs::base::CSVec2d& center, double radius)
  : _impl(std::make_unique<Impl>())
{
  _impl->_center = center;
  _impl->_radius = radius;
}

Circle2d::~Circle2d() {}

const cs::base::CSVec2d&
Circle2d::Center() const
{
  return _impl->_center;
}
const double&
Circle2d::Radius() const
{
  return _impl->_radius;
}
void
Circle2d::SetCenter(const cs::base::CSVec2d& center)
{
  _impl->_center = center;
}
void
Circle2d::SetRadius(double radius) const
{
  _impl->_radius = radius;
}

template<typename T>
struct array_deleter
{
  void operator()(T const* p) { delete[] p; }
};

std::shared_ptr<CSBufferObject>
Circle2d::GenerateBuffer() const
{
  std::shared_ptr<CSBufferObject> buffer = std::make_shared<CSBufferObject>();

  constexpr int CS_CIRCLE_DIVIDE = 20;
  constexpr double p = 2.0 * CSMath::CS_PI / CS_CIRCLE_DIVIDE;
  for (int i = 0; i <= CS_CIRCLE_DIVIDE; ++i) {
    auto index = i % CS_CIRCLE_DIVIDE;
    auto pos = _impl->_center +
               _impl->_radius * CSVec2d({ cs::math::CSMath::Cos(p * index),
                                          cs::math::CSMath::Sin(p * index) });
    buffer->_points.emplace_back(pos.x);
    buffer->_points.emplace_back(pos.y);
  }

  return buffer;
}
