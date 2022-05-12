#include "arc.hpp"
#include "rmath.h"

namespace rv
{
    template<typename _Tp>
    inline constexpr rv::Arc<_Tp>::Arc() noexcept :
        Circle(),
        angleStart(_Tp(0)), 
        angleEnd(_Tp(0))
    {
    }

    template<typename _Tp>
    inline constexpr rv::Arc<_Tp>::Arc(_Tp x, _Tp y, _Tp radius, double _angleStart, double _angleEnd) noexcept :
        Circle(x, y, radius),
        angleStart(_angleStart),
        angleEnd(_angleEnd)
    {
    }

    template<typename _Tp>
    inline constexpr rv::Arc<_Tp>::Arc(const Point<_Tp>& center, _Tp _radius, double _angleStart, double _angleEnd) noexcept :
        Circle(center, radius),
        angleStart(_angleStart),
        angleEnd(_angleEnd)
    {
    }

    template<typename _Tp>
    inline constexpr rv::Arc<_Tp>::Arc(const Circle<_Tp>& circle, double _startAngle, double _endAngle) noexcept :
        Circle(circle),
        angleStart(_startAngle),
        angleEnd(_endAngle)
    {
    }

    template<typename _Tp>
    template<typename _Tp2>
    inline constexpr Arc<_Tp>::Arc(const Arc<_Tp2>& arc) noexcept
    {
        center = Point<_Tp>(arc.center);
        radius = _Tp(arc.radius);
        angleStart = arc.angleStart;
        angleEnd = arc.angleEnd;
    }

    template<typename _Tp>
    inline constexpr double Arc<_Tp>::angleSpan() const noexcept
    {
        double span = angleEnd - angleStart;

        //将角度跨度描述限制在[0,360]
        while (span < 0)
        {
            span += 2 * RV_PI;
        }
        if (span > 2 * RV_PI)
        {
            span = 2 * RV_PI;
        }

        return span;
    }

    template<typename _Tp>
    inline constexpr bool Arc<_Tp>::checkAngle(double angle) const noexcept
    {
        //将angle限制在[start,start+2pi]之中
        while (angle < angleStart)
        {
            angle += 2 * CV_PI;
        }
        while (angle > (angleStart + 2 * CV_PI))
        {
            angle -= 2 * CV_PI;
        }

        return ((angle >= angleStart) && (angle <= (angleStart + angleSpan())));
    }

    template<typename _Tp>
    template<typename _Tp2>
    inline constexpr Arc<_Tp>& Arc<_Tp>::operator=(const Arc<_Tp2>& arc) noexcept
    {
        center = Point<_Tp>(arc.center);
        radius = _Tp(arc.radius);
        angleStart = arc.angleStart;
        angleEnd = arc.angleEnd;
        return *this;
    }

    template<typename _Tp>
    constexpr bool operator==(const Arc<_Tp>& arc1, const Arc<_Tp>& arc2) noexcept
    {
        return (arc1.center == arc2.center) &&
            fuzzyCompare(arc1.radius, arc2.radius)&&
            fuzzyCompare(arc1.angleStart, arc2.angleStart)&&
            fuzzyCompare(arc1.angleSpan(), arc2.angleSpan());
    }

    template<typename _Tp>
    constexpr bool operator!=(const Arc<_Tp>& arc1, const Arc<_Tp>& arc2) noexcept
    {
        return (arc1.center != arc2.center) ||
            !fuzzyCompare(arc1.radius, arc2.radius) ||
            !fuzzyCompare(arc1.angleStart, arc2.angleStart) ||
            !fuzzyCompare(arc1.angleSpan(), arc2.angleSpan());
    }
}