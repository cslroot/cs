#include "CSPath.h"

#include "CSString.h"

#include <filesystem>

using namespace cs::base;
namespace fs = std::filesystem;

bool
CSPath::ExistsFile(const cs::base::CSString& path)
{
  return fs::exists(path.str());
}

cs::base::CSString
CSPath::Extention(const cs::base::CSString& path)
{
  return fs::path(path.str()).extension().string();
}
