#include "adapted_cv.hpp"

template <typename _Tp>
inline constexpr cv::Size converToCvSize(const rv::Size<_Tp>& size) noexcept
{
    return cv::Size((int)size.width, (int)size.height);
}

template <typename _Tp>
inline constexpr cv::Size2f converToCvSizeF(const rv::Size<_Tp>& size) noexcept
{
    return cv::Size2f((float)size.width, (float)size.height);
}

template <typename _Tp>
inline constexpr cv::Point converToCvPoint(const rv::Point<_Tp>& point) noexcept
{
    return cv::Point((int)point.x, (int)point.y);
}

template <typename _Tp>
inline constexpr cv::Point2f converToCvPointF(const rv::Point<_Tp>& point) noexcept
{
    return cv::Point2f((float)point.x, (float)point.y);
}

template <typename _Tp>
inline constexpr cv::Rect converToCvRect(const rv::Rectangle<_Tp>& rect) noexcept
{
    return cv::Rect(converToCvPoint(rect.topLeft()), converToCvSize(rect.size));
}

template <typename _Tp>
inline constexpr cv::Rect2f converToCvRectF(const rv::Rectangle<_Tp>& rect) noexcept
{
    return cv::Rect2f(converToCvPointF(rect.topLeft()), converToCvSizeF(rect.size));
}

template <typename _Tp>
inline constexpr cv::RotatedRect converToCvRotatedRect(const rv::Rectangle<_Tp>& rect) noexcept
{
    return cv::RotatedRect(converToCvPoint(rect.center), converToCvSize(rect.size), 0);
}

template <typename _Tp>
inline constexpr cv::RotatedRect converToCvRotatedRect(const rv::RotatedRect<_Tp>& rect) noexcept
{
    return cv::RotatedRect(converToCvPoint(rect.center), converToCvSize(rect.size), rv::rad2deg(rect.angle));
}
