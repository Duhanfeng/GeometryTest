#include "polygon.hpp"
#include "rmath.h"

namespace rv
{
    template<typename _Tp>
    template<typename _Tp2>
    inline constexpr rv::Polygon<_Tp>::Polygon(const Polygon<_Tp2>& polygon) noexcept
    {
        for (auto itor = polygon.cbegin(); itor != polygon.cend(); itor++)
        {
            this->push_back(Point<_Tp>(_Tp(itor->x), _Tp(itor->y)));
        }
    }

    template<typename _Tp>
    template<typename _Tp2>
    inline constexpr Polygon<_Tp>& Polygon<_Tp>::operator=(const Polygon<_Tp2>&) noexcept
    {
        for (auto itor = polygon.cbegin(); itor != polygon.cend(); itor++)
        {
            this->push_back(Point<_Tp>(_Tp(itor->x), _Tp(itor->y)));
        }
        return *this;
    }

    template<typename _Tp>
    inline constexpr Polygon<_Tp> Polygon<_Tp>::move(_Tp dx, _Tp dy) const noexcept
    {
        Polygon<_Tp> polygon;
        for (auto itor = this->cbegin(); itor != this->cend(); itor++)
        {
            polygon.push_back(Point<_Tp>(itor->x + dx, itor->y + dy));
        }

        return polygon;
    }

    template<typename _Tp>
    inline constexpr Polygon<_Tp> Polygon<_Tp>::rotate(const Point<_Tp>& center, double radian) const noexcept
    {
        Polygon<_Tp> polygon;
        for (auto itor = this->cbegin(); itor != this->cend(); itor++)
        {
            polygon.push_back(itor->rotate(center, radian));
        }

        return polygon;
    }

    template<typename _Tp>
    inline constexpr Polygon<_Tp> Polygon<_Tp>::scale(double ratio) const noexcept
    {
        Polygon<_Tp> polygon;
        for (auto itor = this->cbegin(); itor != this->cend(); itor++)
        {
            polygon.push_back(*itor * ratio);
        }

        return polygon;
    }

    template<typename _Tp>
    inline constexpr Polygon<_Tp>& Polygon<_Tp>::operator*=(double c) noexcept
    {
        for (auto itor = this->cbegin(); itor != this->cend(); itor++)
        {
            *itor = *itor * c;
        }
    }

    template<typename _Tp>
    inline constexpr Polygon<_Tp>& Polygon<_Tp>::operator/=(double c)
    {
        for (auto itor = this->cbegin(); itor != this->cend(); itor++)
        {
            *itor = *itor / c;
        }
    }

    template<typename _Tp>
    inline constexpr bool operator==(const Polygon<_Tp>& polygon1, const Polygon<_Tp>& polygon2) noexcept
    {
        if (polygon1.size() != polygon2.size())
        {
            return false;
        }

        auto itor1 = polygon1->cbegin();
        auto itor2 = polygon2->cbegin();

        for (; itor1 != polygon1.cend(); itor1++, itor2++)
        {
            if (*itor1 != *itor2)
            {
                return false;
            }
        }

        return true;
    }

    template<typename _Tp>
    inline constexpr bool operator!=(const Polygon<_Tp>& polygon1, const Polygon<_Tp>& polygon2) noexcept
    {
        return !(polygon1 == polygon2);
    }

    template<typename _Tp>
    inline constexpr const Polygon<_Tp> operator*(const Polygon<_Tp>& polygon, double c) noexcept
    {
        Polygon<_Tp> polygon2;
        for (auto itor = polygon->cbegin(); itor != polygon->cend(); itor++)
        {
            polygon2.push_back(*itor * c);
        }

        return polygon2;
    }

    template<typename _Tp>
    inline constexpr const Polygon<_Tp> operator*(double c, const Polygon<_Tp>& polygon) noexcept
    {
        Polygon<_Tp> polygon2;
        for (auto itor = polygon->cbegin(); itor != polygon->cend(); itor++)
        {
            polygon2.push_back(*itor * c);
        }

        return polygon2;
    }

    template<typename _Tp>
    inline constexpr const Polygon<_Tp> operator/(const Polygon<_Tp>& polygon, double c)
    {
        Polygon<_Tp> polygon2;
        for (auto itor = polygon->cbegin(); itor != polygon->cend(); itor++)
        {
            polygon2.push_back(*itor / c);
        }

        return polygon2;
    }
}
