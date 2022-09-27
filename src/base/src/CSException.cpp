#include "CSException.h"

using namespace cs::base;

CSException::CSException() = default;
CSException::CSException(const cs::base::CSString& msg)
  : _msg(msg)
{}
CSException::~CSException() = default;
