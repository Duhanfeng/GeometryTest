#pragma once

#include <opencv2/opencv.hpp>

/* ----------------------- rv转cv ----------------------- */

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


/* ----------------------- cv转rv ----------------------- */

rv::Size<int> converToSize(cv::Size size);
rv::Size<int> converToSize(cv::Size2f size);
rv::Size<double> converToSizeF(cv::Size size);
rv::Size<double> converToSizeF(cv::Size2f size);

rv::Point<int> converToPoint(cv::Point point);
rv::Point<int> converToPoint(cv::Point2f point);
rv::Point<double> converToPointF(cv::Point point);
rv::Point<double> converToPointF(cv::Point2f point);

rv::Rectangle<int> converToRect(cv::Rect rect);
rv::Rectangle<int> converToRect(cv::Rect2f rect);
rv::Rectangle<double> converToRectF(cv::Rect rect);
rv::Rectangle<double> converToRectF(cv::Rect2f rect);

rv::RotatedRect<int> converToRotatedRect(cv::RotatedRect rect);
rv::RotatedRect<double> converToRotatedRectF(cv::RotatedRect rect);

#include "adapted_cv.inl"