#include "runs.hpp"
#include "rmath.h"

namespace rv
{
    template<typename _Tp>
    template<typename _Tp2>
    inline constexpr rv::Runs<_Tp>::Runs(const Runs<_Tp2>& runs) noexcept
    {
        size_t _size = runs.size();
        for (size_t i = 0; i < _size; i++)
        {
            this->emplace_back(runs[i]);
        }
    }

    template<typename _Tp>
    template<typename _Tp2>
    inline constexpr Runs<_Tp>& Runs<_Tp>::operator=(const Runs<_Tp2>& runs) noexcept
    {
        this->clear();
        size_t _size = runs.size();
        for (size_t i = 0; i < _size; i++)
        {
            this->emplace_back(runs[i]);
        }
        return *this;
    }

    template<typename _Tp>
    inline constexpr Runs<_Tp> Runs<_Tp>::move(_Tp dx, _Tp dy) const noexcept
    {
        Runs<_Tp> runs;

        size_t _size = this->size();
        for (size_t i = 0; i < _size; i++)
        {
            runs.emplace_back(Run<_Tp>((*this)[i].r + dy, (*this)[i].cb + dx, (*this)[i].ce + dx));
        }

        return runs;
    }

    template<typename _Tp>
    inline constexpr Runs<_Tp> Runs<_Tp>::scale(double ratio) const noexcept
    {

        return *this * ratio;
    }

    template<typename _Tp>
    inline constexpr Runs<_Tp>& Runs<_Tp>::operator*=(double c) noexcept
    {
        size_t _size = size();
        for (size_t i = 0; i < _size; i++)
        {
            (*this)[i] *= c;
        }

        return *this;
    }

    template<typename _Tp>
    inline constexpr Runs<_Tp>& Runs<_Tp>::operator/=(double c)
    {
        size_t _size = size();
        for (size_t i = 0; i < _size; i++)
        {
            (*this)[i] /= c;
        }

        return *this;
    }

    template<typename _Tp>
    inline constexpr bool operator==(const Runs<_Tp>& runs1, const Runs<_Tp>& runs2) noexcept
    {
        if (runs1.size() != runs2.size())
        {
            return false;
        }

        if (runs1.size() == 0)
        {
            return true;
        }

        size_t _size = runs1.size();
        for (size_t i = 0; i < _size; i++)
        {
            if (runs1[i] != runs2[i])
            {
                return false;
            }
        }

        return true;
    }

    template<typename _Tp>
    inline constexpr bool operator!=(const Runs<_Tp>& runs1, const Runs<_Tp>& runs2) noexcept
    {
        return !(runs1 == runs2);
    }

    template<typename _Tp>
    inline constexpr const Runs<_Tp> operator*(const Runs<_Tp>& runs, double c) noexcept
    {
        Runs<_Tp> runs2;

        size_t _size = runs.size();
        for (size_t i = 0; i < _size; i++)
        {
            runs2.emplace_back(runs[i] * c);
        }

        return runs2;
    }

    template<typename _Tp>
    inline constexpr const Runs<_Tp> operator*(double c, const Runs<_Tp>& runs) noexcept
    {
        Runs<_Tp> runs2;

        size_t _size = runs.size();
        for (size_t i = 0; i < _size; i++)
        {
            runs2.emplace_back(runs[i] * c);
        }

        return runs2;
    }

    template<typename _Tp>
    inline constexpr const Runs<_Tp> operator/(const Runs<_Tp>& runs, double c)
    {
        Runs<_Tp> runs2;

        size_t _size = runs.size();
        for (size_t i = 0; i < _size; i++)
        {
            runs2.emplace_back(runs[i] / c);
        }

        return runs2;
    }
}
