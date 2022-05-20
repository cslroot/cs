#include <cassert>
#include <iostream>

#include "cs_core.h"

namespace {
bool _initialized = false;
} // namepsace anonymous

bool
cs_initialize(int argc, char** argv)
{
  assert(argc > 0);
  for (int i = 0; i < argc; ++i) {
    std::cout << argv[i] << std::endl;
  }
  std::cout << "initialized" << std::endl;
  _initialized = true;
  return _initialized;
}

bool
cs_terminate()
{
  _initialized = false;
  return true;
}

bool
cs_is_initialized()
{
  return _initialized;
}
