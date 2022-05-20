#include "CSQuaternion.h"

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

using namespace cs::math;

struct CSQuaternion::Impl
{
  glm::dquat _quat;
};

CSQuaternion::CSQuaternion()
  : _impl(std::make_unique<Impl>())
{}

CSQuaternion::~CSQuaternion() = default;
