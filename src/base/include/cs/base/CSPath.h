#pragma once

#include <cs/base/common.h>
#include <cs/base_fwd.h>
#include <string>

namespace cs {
namespace base {

/**
 * @brief Path utility
 *
 */
class CSPath
{
public:
  DECL_CS_BASE static bool ExistsFile(const cs::base::CSString& path);
  DECL_CS_BASE static cs::base::CSString Extention(
    const cs::base::CSString& path);
};

} // namespace base
} // namespace cs
