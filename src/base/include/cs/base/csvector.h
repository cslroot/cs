#pragma once

#include <cs/base/base_common.h>
#include <string>
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <cmath>
#include <array>
#include <cassert>

namespace cs
{
    namespace base
    {
        template<typename T, int constSize> struct VecFloatStorage
        {
            T v[constSize];
        };

        template<typename T> struct VecFloatStorage<T, 2>
        {
            union
            {
                T v[2];
                struct { T x, y; };
            };
        };
        template<typename T> struct VecFloatStorage<T, 3>
        {
            union
            {
                T v[3];
                struct { T x, y, z; };
            };
        };
        template<typename T> struct VecFloatStorage<T, 4>
        {
            union
            {
                T v[4];
                struct { T x, y, z; };
            };
        };

        template<typename T, size_t N>
        class CSVector : public VecFloatStorage<T, N>
        {
        public:
            CSVector()
            {
                for (int i = 0; i < N; ++i) {
                    this->v[i] = 0.0;
                }
            }
            explicit CSVector(std::array<T, N>);

        public:
            CSVector<T, N>& operator+=(const CSVector<T, N>& rhs)
            {
                for (size_t i = 0; i < N; ++i)
                {
                    this->v[i] += rhs.v[i];
                }
                return *this;
            }
            CSVector<T, N>& operator-=(const CSVector<T, N>& rhs)
            {
                for (size_t i = 0; i < N; ++i)
                {
                    this->v[i] -= rhs.v[i];
                }
                return *this;
            }
            CSVector<T, N>& operator*=(T scale)
            {
                for (size_t i = 0; i < N; ++i)
                {
                    this->v[i] *= scale;
                }
                return *this;
            }
            CSVector<T, N>& operator/=(T div)
            {
                assert(div != 0.0);
                for (size_t i = 0; i < N; ++i)
                {
                    this->v[i] /= div;
                }
                return *this;
            }

            T length() const
            {
                T value = 0.0;
                for (size_t i = 0; i < N; ++i)
                {
                    value += this->v[i] * this->v[i];
                }
                return std::sqrt(value);
            }

        };

        // // pre instanciated types
        // typedef CSVector<double, 2> CSVec2d;
        // typedef CSVector<double, 3> CSVec3d;
        // typedef CSVector<double, 4> CSVec4d;
        // typedef CSVector<float, 2> CSVec2f;
        // typedef CSVector<float, 3> CSVec3f;
        // typedef CSVector<float, 4> CSVec4f;

#ifdef CS_BASE_EXPORT
        extern template class cs::base::CSVector<double, 2>;
        extern template class cs::base::CSVector<double, 3>;
        extern template class cs::base::CSVector<double, 4>;
        extern template class cs::base::CSVector<float, 2>;
        extern template class cs::base::CSVector<float, 3>;
        extern template class cs::base::CSVector<float, 4>;
#else
        template class DECL_CS_BASE cs::base::CSVector<double, 2>;
        template class DECL_CS_BASE cs::base::CSVector<double, 3>;
        template class DECL_CS_BASE cs::base::CSVector<double, 4>;
        template class DECL_CS_BASE cs::base::CSVector<float, 2>;
        template class DECL_CS_BASE cs::base::CSVector<float, 3>;
        template class DECL_CS_BASE cs::base::CSVector<float, 4>;

#endif

        using CSVec2d = cs::base::CSVector<double, 2>;

        class DECL_CS_BASE CSVec3d : public CSVector<double, 3>
        {
        public:
            CSVec3d() {}
            CSVec3d(double x_, double y_, double z_)
            {
                x = x_;
                y = y_;
                z = z_;
            }
        };
    } // namespace base

} // namespace cs
