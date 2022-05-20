#include "CSBufferObject.h"

using namespace cs::core;

struct CSBufferObject::Impl
{};

CSBufferObject::CSBufferObject()
  : _impl(std::make_unique<Impl>())
{}
CSBufferObject::~CSBufferObject() = default;
