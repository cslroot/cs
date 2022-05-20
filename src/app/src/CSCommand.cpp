#include "CSCommand.h"

using namespace cs::app;

namespace {}

struct CSCommand::Impl
{};

CSCommand::CSCommand()
  : _impl(std::make_unique<Impl>())
{}

CSCommand::~CSCommand() = default;

bool
CSCommand::CanExecute(void*) const
{
  return true;
}
