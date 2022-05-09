#pragma once

#include <cs/base_fwd.h>
#include <cs/core/common.h>
#include <memory>

namespace cs {
namespace core {
class CSBufferObject;

/**
 * @brief atomic object manipulated by F/W
 *
 */
class CSObject
{
public:
  DECL_CS_CORE CSObject();
  DECL_CS_CORE virtual ~CSObject();

public:
  DECL_CS_CORE const cs::base::CSString& Name() const;
  DECL_CS_CORE void SetName(const cs::base::CSString& name);

  DECL_CS_CORE virtual std::shared_ptr<CSBufferObject> GenerateBuffer() const
  {
    return nullptr;
  };

private:
  struct Impl;
  std::unique_ptr<Impl> _impl;
};
} // namespace core

} // namespace cs
