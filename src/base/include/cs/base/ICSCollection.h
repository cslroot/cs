#pragma once


#include <memory>

namespace cs
{
    namespace base
    {
        template<class T>
        class ICSCollection
        {
        public:
            virtual ~ICSCollection() {}
        public:
            virtual T& Add(std::unique_ptr<T> obj) = 0;
            virtual void Clear() = 0;
            virtual size_t Size() const = 0;


        };

    } // namespace base
} // namespace cs
