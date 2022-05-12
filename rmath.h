#pragma once

#include <iostream>

namespace rv
{
#ifdef CV_PI
#define RV_PI CV_PI
#else
#define RV_PI (3.1415926535897932384626433832795)
#endif

    template<typename _Tp>
    constexpr inline bool fuzzyCompare(_Tp p1, _Tp p2)
    {
        return p1 == p2;
    }

    inline bool fuzzyCompare(double p1, double p2) noexcept
    {
        return std::abs(p1 - p2) <= 1.0E-07;
    }

    inline bool fuzzyCompare(float p1, float p2) noexcept
    {
        return std::abs(p1 - p2) <= 1.0E-05f;
    }

    constexpr inline bool isNull(double d) noexcept
    {
        return d == 0.0;
    }

    //弧度转角度
    template<typename _Tp>
    constexpr inline double rad2deg(_Tp rad)
    {
        return double(rad) * 180.0 / 3.141592653589;
    }

    constexpr inline float rad2deg(float rad)
    {
        return float(rad * 180.0f / 3.141592653589);
    }

    //角度转弧度
    template<typename _Tp>
    constexpr inline double deg2rad(_Tp deg)
    {
        return double(deg) * 3.141592653589 / 180.0;
    }

    constexpr inline float deg2rad(float deg)
    {
        return float(deg * 3.141592653589 / 180);
    }

    //点位绕点旋转
    template<typename _Tp>
    inline void rotatePoint(_Tp cx, _Tp cy, _Tp p1x, _Tp p1y, double radian, _Tp& p2x, _Tp& p2y)
    {
        p2x = _Tp((p1x - cx) * std::cos(radian) - (p1y - cy) * std::sin(radian) + cx);
        p2y = _Tp((p1x - cx) * std::sin(radian) + (p1y - cy) * std::cos(radian) + cy);
    }

}
