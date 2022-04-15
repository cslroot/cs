#pragma once

#include <cs/core/core_common.h>
#include <cs/core/csobject.h>
#include <cs/base_fwd.h>

#include <memory>
#include <vector>

namespace cs
{
    namespace core
    {
        class CSBufferObject : CSObject
        {
        public:
            CSBufferObject();
            virtual ~CSBufferObject();

        public:
            std::vector<double> _points;

        private:
            struct Impl;
            std::unique_ptr<Impl> _impl;
        };
    } // namespace core

} // namespace cs
