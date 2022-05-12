#include "circle.hpp"
#include "circle.hpp"
#include "rmath.h"

namespace rv
{
    template<typename _Tp>
    inline constexpr rv::Circle<_Tp>::Circle() noexcept : center(), radius()
    {
    }

    template<typename _Tp>
    inline constexpr rv::Circle<_Tp>::Circle(_Tp x, _Tp y, _Tp _radius) noexcept :
        center(x, y),
        radius(_radius)
    {
    }

    template<typename _Tp>
    inline constexpr rv::Circle<_Tp>::Circle(const Point<_Tp>& center, _Tp _radius) noexcept :
        center(_center), 
        radius(_radius)
    {
    }

    template<typename _Tp>
    template<typename _Tp2>
    inline constexpr Circle<_Tp>::Circle(const Circle<_Tp2>& rect) noexcept
    {
        center = _Tp(rect.center);
        radius = _Tp(rect.radius);
    }

    template<typename _Tp>
    template<typename _Tp2>
    inline constexpr Circle<_Tp>& Circle<_Tp>::operator=(const Circle<_Tp2>& rect) noexcept
    {
        center = _Tp(rect.center);
        radius = _Tp(rect.radius);
        return *this;
    }

    template<typename _Tp>
    inline constexpr bool Circle<_Tp>::isNull() const noexcept
    {
        return isNull(radius);
    }

    template<typename _Tp>
    inline constexpr _Tp Circle<_Tp>::area() const noexcept
    {
        return _Tp(RV_PI * radius * radius);
    }

    template<typename _Tp>
    inline constexpr _Tp Circle<_Tp>::perimeter() const noexcept
    {
        return _Tp(RV_PI * radius * 2);
    }

    template<typename _Tp>
    inline constexpr Circle<_Tp> Circle<_Tp>::move(_Tp dx, _Tp dy) const noexcept
    {
        return Circle<_Tp>(center.move(dx, dy), radius);
    }

    template<typename _Tp>
    inline constexpr Circle<_Tp> Circle<_Tp>::rotate(const Point<_Tp>& _center, double radian) const noexcept
    {
        return Circle<_Tp>(center.rotate(_center, radian), radius);
    }

    template<typename _Tp>
    inline constexpr Circle<_Tp>& Circle<_Tp>::operator*=(double c) noexcept
    {
        center *= c;
        radius *= c;
        return *this;
    }

    template<typename _Tp>
    inline constexpr Circle<_Tp>& Circle<_Tp>::operator/=(double c)
    {
        center /= c;
        radius /= c;
        return *this;
    }

    template<typename _Tp>
    inline constexpr bool operator==(const Circle<_Tp>& rect1, const Circle<_Tp>& rect2) noexcept
    {
        return (rect1.center == rect2.center) && fuzzyCompare(rect1.radius, rect2.radius);
    }

    template<typename _Tp>
    inline constexpr bool operator!=(const Circle<_Tp>& rect1, const Circle<_Tp>& rect2) noexcept
    {
        return (rect1.center != rect2.center) || !fuzzyCompare(rect1.radius, rect2.radius);
    }

    template<typename _Tp>
    inline constexpr const Circle<_Tp> operator*(const Circle<_Tp>& rect, double c) noexcept
    {
        return Circle<_Tp>(rect.center * c, rect.radius * c);
    }

    template<typename _Tp>
    inline constexpr const Circle<_Tp> operator*(double c, const Circle<_Tp>& rect) noexcept
    {
        return Circle<_Tp>(rect.center * c, rect.radius * c);
    }

    template<typename _Tp>
    inline constexpr const Circle<_Tp> operator/(const Circle<_Tp>& rect, double c)
    {
        return Circle<_Tp>(rect.center / c, rect.radius / c);
    }

    template<typename _Tp>
    inline constexpr Point<_Tp> Circle<_Tp>::centerLeft() const noexcept
    {
        return Point<_Tp>(center.x - radius, center.y);
    }

    template<typename _Tp>
    inline constexpr Point<_Tp> Circle<_Tp>::centerTop() const noexcept
    {
        return Point<_Tp>(center.x, center.y - radius);
    }

    template<typename _Tp>
    inline constexpr Point<_Tp> Circle<_Tp>::centerRight() const noexcept
    {
        return Point<_Tp>(center.x + radius, center.y);
    }

    template<typename _Tp>
    inline constexpr Point<_Tp> Circle<_Tp>::centerBottom() const noexcept
    {
        return Point<_Tp>(center.x, center.y + radius);
    }

    template<typename _Tp>
    inline constexpr _Tp Circle<_Tp>::left() const noexcept
    {
        return center.x - radius;
    }

    template<typename _Tp>
    inline constexpr _Tp Circle<_Tp>::top() const noexcept
    {
        return center.y - radius;
    }

    template<typename _Tp>
    inline constexpr _Tp Circle<_Tp>::right() const noexcept
    {
        return center.x + radius;
    }

    template<typename _Tp>
    inline constexpr _Tp Circle<_Tp>::bottom() const noexcept
    {
        return center.y + radius;
    }
}