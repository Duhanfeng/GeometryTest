#pragma once

#include <memory>
#include <vector>
#include <initializer_list>
#include "point.hpp"
#include "run.hpp"

namespace rv
{
    template<typename _Tp = short>
    class Runs : public std::vector<Run<_Tp>>
    {
        typedef std::vector<Run<_Tp>> base_type;

    public:

        //构造
        constexpr Runs() noexcept : base_type() {}
        template <typename Iterator> constexpr Runs(Iterator begin, Iterator end) noexcept : base_type(begin, end) {}
        constexpr Runs(std::initializer_list<Run<_Tp>> l) noexcept : base_type(l.begin(), l.end()) {}
        template<typename _Tp2> constexpr Runs(const Runs<_Tp2>& polygon) noexcept;

        //功能函数
        inline constexpr Runs move(_Tp dx, _Tp dy) const noexcept;
        inline constexpr Runs scale(double ratio) const noexcept;

        //符号重载
        inline constexpr Runs& operator*=(double c) noexcept;
        inline constexpr Runs& operator/=(double c);
        template<typename _Tp2> inline constexpr Runs& operator= (const Runs<_Tp2>&) noexcept;  //类型转换

    };

    //符号重载
    template<typename _Tp> inline constexpr bool operator==(const Runs<_Tp>&, const Runs<_Tp>&) noexcept;
    template<typename _Tp> inline constexpr bool operator!=(const Runs<_Tp>&, const Runs<_Tp>&) noexcept;
    template<typename _Tp> inline constexpr const Runs<_Tp> operator*(const Runs<_Tp>&, double) noexcept;
    template<typename _Tp> inline constexpr const Runs<_Tp> operator*(double, const Runs<_Tp>&) noexcept;
    template<typename _Tp> inline constexpr const Runs<_Tp> operator/(const Runs<_Tp>&, double);

}

#include "runs.inl"