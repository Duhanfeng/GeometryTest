#pragma once

#include <memory>
#include <vector>
#include <initializer_list>
#include "point.hpp"

namespace rv
{
    template<
        typename _Tp = double,                                          //类型
        template<typename, typename> class Container = std::vector,     //容器
        template<typename> class Allocator = std::allocator             //构造器
    >
    class Polygon : public Container<Point<_Tp>, Allocator<Point<_Tp>>>
    {
        typedef Container<Point<_Tp>, Allocator<Point<_Tp>>> base_type;

    public:

        //构造
        constexpr Polygon() noexcept : base_type() {}
        template <typename Iterator> constexpr Polygon(Iterator begin, Iterator end) noexcept : base_type(begin, end) {}
        constexpr Polygon(std::initializer_list<Point<_Tp>> l) noexcept : base_type(l.begin(), l.end()) {}

        //功能函数
        inline constexpr Polygon move(_Tp dx, _Tp dy) const noexcept;
        //inline constexpr Polygon rotate(const Point<_Tp>& center, double radian) const noexcept;

    };

    template<typename _Tp,template<typename, typename> class Container,template<typename> class Allocator>
    inline constexpr Polygon<_Tp, Container, Allocator> Polygon<_Tp, Container, Allocator>::move(_Tp dx, _Tp dy) const noexcept
    {
        Polygon<_Tp, Container, Allocator> polygon;

        std::initializer_list<Point<_Tp>> a;

        //for (auto itr = this->template cbegin(); itr != this->template cend(); itr++)
        //{
        //    

        //}

        return polygon;
    }


}

//#include "polygon.inl"