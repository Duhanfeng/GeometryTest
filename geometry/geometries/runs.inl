#include "runs.hpp"
#include "rmath.h"

namespace rv
{
    template<typename _Tp>
    template<typename _Tp2>
    inline constexpr rv::Runs<_Tp>::Runs(const Runs<_Tp2>& runs) noexcept : base_type()
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
    inline constexpr void Runs<_Tp>::readFormImage(unsigned char* data, int width, int height)
    {
        this->clear();

        _Tp _r = 0;
        _Tp _cb = 0;
        _Tp _ce = 0;

        for (int r = 0; r < height; r++)
        {
            bool isStart = false;

            for (int c = 0; c < width; c++)
            {
                if (!isStart)
                {
                    if (*data != 0)
                    {
                        isStart = true;
                        
                        _r = _Tp(r);
                        _cb = _Tp(c);
                    }
                }
                else
                {
                    //如果已经开始,而当前为0,则认为已经结束
                    if (*data == 0)
                    {
                        isStart = false;
                        _ce = _Tp(c - 1);
                    }
                }

                data++;
            }

            //如果查找到末尾,则保存末尾
            if (isStart)
            {
                _ce = _Tp(width - 1);
            }

            this->emplace_back(Run<_Tp>(_r, _cb, _ce));
        }

    }

    template<typename _Tp>
    inline constexpr Runs<_Tp>& Runs<_Tp>::operator*=(double c) noexcept
    {
        size_t _size = this->size();
        for (size_t i = 0; i < _size; i++)
        {
            (*this)[i] *= c;
        }

        return *this;
    }

    template<typename _Tp>
    inline constexpr Runs<_Tp>& Runs<_Tp>::operator/=(double c)
    {
        size_t _size = this->size();
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
