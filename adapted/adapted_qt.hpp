#pragma once

#include <geometry/geometry.hpp>
#include <QWidget>

/* ----------------------- rv转qt ----------------------- */

template <typename _Tp>
inline constexpr QSize converToQSize(const rv::Size<_Tp>& size) noexcept;

template <typename _Tp>
inline constexpr QSizeF converToQSizeF(const rv::Size<_Tp>& size) noexcept;


template <typename _Tp>
inline constexpr QPoint converToQPoint(const rv::Point<_Tp>& point) noexcept;

template <typename _Tp>
inline constexpr QPointF converToQPointF(const rv::Point<_Tp>& point) noexcept;


template <typename _Tp>
inline constexpr QLine converToQLine(const rv::Line<_Tp>& line) noexcept;

template <typename _Tp>
inline constexpr QLineF converToQLineF(const rv::Line<_Tp>& line) noexcept;


template <typename _Tp>
inline constexpr QRect converToQRect(const rv::Rectangle<_Tp>& rect) noexcept;

template <typename _Tp>
inline constexpr QRectF converToQRectF(const rv::Rectangle<_Tp>& rect) noexcept;


template <typename _Tp>
inline constexpr QPolygon converToQPolygon(const rv::Rectangle<_Tp>& rect) noexcept;

template <typename _Tp>
inline constexpr QPolygon converToQPolygon(const rv::RotatedRect<_Tp>& rect) noexcept;

template <typename _Tp>
inline constexpr QPolygonF converToQPolygonF(const rv::Rectangle<_Tp>& rect) noexcept;

template <typename _Tp>
inline constexpr QPolygonF converToQPolygonF(const rv::RotatedRect<_Tp>& rect) noexcept;


/* ----------------------- qt转rv ----------------------- */

inline constexpr rv::Size<int> converToSize(const QSize& size) noexcept;
inline constexpr rv::Size<int> converToSize(const QSizeF& size) noexcept;

inline constexpr rv::Size<double> converToSizeF(const QSize& size) noexcept;
inline constexpr rv::Size<double> converToSizeF(const QSizeF& size) noexcept;

inline constexpr rv::Point<int> converToPoint(const QPoint& point) noexcept;
inline constexpr rv::Point<int> converToPoint(const QPointF& point) noexcept;

inline constexpr rv::Point<double> converToPointF(const QPoint& point) noexcept;
inline constexpr rv::Point<double> converToPointF(const QPointF& point) noexcept;

inline constexpr rv::Rectangle<int> converToRect(const QRect& rect) noexcept;
inline constexpr rv::Rectangle<int> converToRect(const QRectF& rect) noexcept;

inline constexpr rv::Rectangle<double> converToRectF(const QRect& rect) noexcept;
inline constexpr rv::Rectangle<double> converToRectF(const QRectF& rect) noexcept;


#include "adapted_qt.inl"