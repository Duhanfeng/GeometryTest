#pragma once

#include "point.hpp"
#include "circle.hpp"

namespace rv
{
    template<typename _Tp = double>
    class Arc : public Circle<_Tp>
    {
    public:

        //构造
        constexpr Arc() noexcept;
        constexpr Arc(_Tp x, _Tp y, _Tp radius, double angleStart, double angleEnd) noexcept;
        constexpr Arc(const Point<_Tp>& center, _Tp radius, double angleStart, double angleEnd) noexcept;
        constexpr Arc(const Circle<_Tp>& circle, double angleStart, double angleEnd) noexcept;
        template<typename _Tp2> constexpr Arc(const Arc<_Tp2>& arc) noexcept;

        //功能函数
        inline constexpr double angleSpan() const noexcept;             //获取角度跨度
        inline constexpr bool checkAngle(double angle) const noexcept;  //检查某个角度在圆环有效角度上

        //符号重载
        template<typename _Tp2> inline constexpr Arc& operator= (const Arc<_Tp2>&) noexcept;  //类型转换

        //核心数据
        double angleStart;  //起始角度
        double angleEnd;    //终止角度(定义:永远从起始角度顺时针旋转到终止角度)

    };

    //符号重载
    template<typename _Tp> inline constexpr bool operator==(const Arc<_Tp>&, const Arc<_Tp>&) noexcept;
    template<typename _Tp> inline constexpr bool operator!=(const Arc<_Tp>&, const Arc<_Tp>&) noexcept;
    template<typename _Tp> inline constexpr const Arc<_Tp> operator*(const Arc<_Tp>&, double) noexcept;
    template<typename _Tp> inline constexpr const Arc<_Tp> operator*(double, const Arc<_Tp>&) noexcept;
    template<typename _Tp> inline constexpr const Arc<_Tp> operator/(const Arc<_Tp>&, double);

}

#include "arc.inl"