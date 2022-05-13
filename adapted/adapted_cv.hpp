#pragma once

#include <opencv2/opencv.hpp>

template <typename _Tp>
inline constexpr cv::Size converToCvSize(const rv::Size<_Tp>& size) noexcept;

template <typename _Tp>
inline constexpr cv::Size2f converToCvSizeF(const rv::Size<_Tp>& size) noexcept;



template <typename _Tp>
inline constexpr cv::Point converToCvPoint(const rv::Point<_Tp>& point) noexcept;

template <typename _Tp>
inline constexpr cv::Point2f converToCvPointF(const rv::Point<_Tp>& point) noexcept;



template <typename _Tp>
inline constexpr cv::Rect converToCvRect(const rv::Rectangle<_Tp>& rect) noexcept;

template <typename _Tp>
inline constexpr cv::Rect2f converToCvRectF(const rv::Rectangle<_Tp>& rect) noexcept;



template <typename _Tp>
inline constexpr cv::RotatedRect converToCvRotatedRect(const rv::Rectangle<_Tp>& rect) noexcept;

template <typename _Tp>
inline constexpr cv::RotatedRect converToCvRotatedRect(const rv::RotatedRect<_Tp>& rect) noexcept;


#include "adapted_cv.inl"