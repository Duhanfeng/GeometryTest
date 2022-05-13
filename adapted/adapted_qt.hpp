#pragma once

#include <geometry/geometry.hpp>
#include <QWidget>

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

#include "adapted_qt.inl"