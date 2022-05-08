#pragma once

#include <cs/base/base_common.h>
#include <cs/math.h>

#include <array>
#include <cassert>
#include <cstddef>
#include <string>
#include <type_traits>

namespace cs {
namespace base {

template<typename T, int constSize>
struct VecFloatStorage
{
  T v[constSize];
};

template<typename T>
struct VecFloatStorage<T, 2>
{
  union
  {
    T v[2];
    struct
    {
      T x, y;
    };
  };
};
template<typename T>
struct VecFloatStorage<T, 3>
{
  union
  {
    T v[3];
    struct
    {
      T x, y, z;
    };
  };
};
template<typename T>
struct VecFloatStorage<T, 4>
{
  union
  {
    T v[4];
    struct
    {
      T x, y, z;
    };
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
  // allow implicit construction (e.g. `CSVector v = {1.0, 2.0};`)
  CSVector(const std::array<T, N>& p2d)
  {
    for (int i = 0; i < N; ++i) {
      this->v[i] = p2d[i];
    }
  }
  // explicit CSVector(T v0) { this->v[0] = v0; }
  // explicit CSVector(T v0, T v1)
  // {
  //   this->v[0] = v0;
  //   this->v[1] = v1;
  // }

  // CSVector(T v0, T v1, T v2) { assert(false); }
  // template<typename TT>
  // CSVector<TT, 3>(T v0, T v1, T v2)
  // {
  //   this->v[0] = v0;
  //   this->v[1] = v1;
  //   this->v[2] = v2;
  // }

public:
  CSVector<T, N>& operator+=(const CSVector<T, N>& rhs)
  {
    for (size_t i = 0; i < N; ++i) {
      this->v[i] += rhs.v[i];
    }
    return *this;
  }
  CSVector<T, N>& operator-=(const CSVector<T, N>& rhs)
  {
    for (size_t i = 0; i < N; ++i) {
      this->v[i] -= rhs.v[i];
    }
    return *this;
  }
  CSVector<T, N>& operator*=(T scale)
  {
    for (size_t i = 0; i < N; ++i) {
      this->v[i] *= scale;
    }
    return *this;
  }
  CSVector<T, N>& operator/=(T div)
  {
    assert(div != 0.0);
    for (size_t i = 0; i < N; ++i) {
      this->v[i] /= div;
    }
    return *this;
  }

  T length() const
  {
    T value = 0.0;
    for (size_t i = 0; i < N; ++i) {
      value += this->v[i] * this->v[i];
    }
    return cs::math::CSMath::Sqrt(value);
  }
};

template<typename T, size_t N>
inline CSVector<T, N>
operator*(T scale, CSVector<T, N> vec)
{
  return vec *= scale;
}

template<typename T, size_t N>
inline CSVector<T, N>
operator+(CSVector<T, N> vec1, const CSVector<T, N>& vec2)
{
  return vec1 += vec2;
}

using CSVec2d = CSVector<double, 2>;
using CSVec3d = CSVector<double, 3>;

// // pre instanciated types
// typedef CSVector<double, 2> CSVec2d;
// typedef CSVector<double, 3> CSVec3d;
// typedef CSVector<double, 4> CSVec4d;
// typedef CSVector<float, 2> CSVec2f;
// typedef CSVector<float, 3> CSVec3f;
// typedef CSVector<float, 4> CSVec4f;

// #ifdef BUILD_CS_BASE_LIB
// extern template class cs::base::CSVector<double, 2>;
// extern template class cs::base::CSVector<double, 3>;
// extern template class cs::base::CSVector<double, 4>;
// extern template class cs::base::CSVector<float, 2>;
// extern template class cs::base::CSVector<float, 3>;
// extern template class cs::base::CSVector<float, 4>;
// #else
// // template class DECL_CS_BASE cs::base::CSVector<double, 2>;
// // template class DECL_CS_BASE cs::base::CSVector<double, 3>;
// // template class DECL_CS_BASE cs::base::CSVector<double, 4>;
// // template class DECL_CS_BASE cs::base::CSVector<float, 2>;
// // template class DECL_CS_BASE cs::base::CSVector<float, 3>;
// // template class DECL_CS_BASE cs::base::CSVector<float, 4>;
// #endif

// class DECL_CS_BASE CSVec2d : public CSVector<double, 2>
// {
// public:
//   CSVec2d() {}
//   CSVec2d(double x_, double y_)
//     : CSVector<double, 2>({ x_, y_ })
//   {}
//   CSVec2d(std::array<double, 2> p)
//     : CSVector<double, 2>(p)
//   {}
// };

// class DECL_CS_BASE CSVec3d : public CSVector<double, 3>
// {
// public:
//   CSVec3d() {}
//   CSVec3d(double x_, double y_, double z_)
//   {
//     x = x_;
//     y = y_;
//     z = z_;
//   }
// };

} // namespace base
} // namespace cs
