#include "qt_addpted.hpp"


template <typename _Tp>
inline constexpr QSize converToQSize(const rv::Size<_Tp>& size) noexcept
{
    return QSize(size.width, size.height);
}

template <typename _Tp>
inline constexpr QSizeF converToQSizeF(const rv::Size<_Tp>& size) noexcept
{
    return QSizeF(size.width, size.height);
}

template <typename _Tp>
inline constexpr QPoint converToQPoint(const rv::Point<_Tp>& point) noexcept
{
    return QPoint(point.x, point.y);
}

template <typename _Tp>
inline constexpr QPointF converToQPointF(const rv::Point<_Tp>& point) noexcept
{
    return QPointF(point.x, point.y);
}

template <typename _Tp>
inline constexpr QLine converToQLine(const rv::Line<_Tp>& line) noexcept
{
    return QLine(converToQPoint(line.p1), converToQPoint(line.p2));
}

template <typename _Tp>
inline constexpr QLineF converToQLineF(const rv::Line<_Tp>& line) noexcept
{
    return QLineF(converToQPointF(line.p1), converToQPointF(line.p2));
}

template <typename _Tp>
inline constexpr QRect converToQRect(const rv::Rectangle<_Tp>& rect) noexcept
{
    return QRect(converToQPoint(rect.topLeft()), converToQSize(rect.size));
}

template <typename _Tp>
inline constexpr QRectF converToQRectF(const rv::Rectangle<_Tp>& rect) noexcept
{
    return QRectF(converToQPointF(rect.topLeft()), converToQSizeF(rect.size));
}

template <typename _Tp>
inline constexpr QPolygon converToQPolygon(const rv::Rectangle<_Tp>& rect) noexcept
{
    QVector<QPoint> polygon;
    polygon << converToQPoint(rect.topLeft()) << converToQPoint(rect.topRight()) << converToQPoint(rect.bottomRight()) << converToQPoint(rect.bottomLeft());

    return QPolygon(polygon);
}

template <typename _Tp>
inline constexpr QPolygon converToQPolygon(const rv::RotatedRect<_Tp>& rect) noexcept
{
    QVector<QPoint> polygon;
    polygon << converToQPoint(rect.topLeft()) << converToQPoint(rect.topRight()) << converToQPoint(rect.bottomRight()) << converToQPoint(rect.bottomLeft());

    return QPolygon(polygon);
}

template <typename _Tp>
inline constexpr QPolygonF converToQPolygonF(const rv::Rectangle<_Tp>& rect) noexcept
{
    QVector<QPoint> polygon;
    polygon << converToQPointF(rect.topLeft()) << converToQPointF(rect.topRight()) << converToQPointF(rect.bottomRight()) << converToQPointF(rect.bottomLeft());

    return QPolygonF(polygon);
}

template <typename _Tp>
inline constexpr QPolygonF converToQPolygonF(const rv::RotatedRect<_Tp>& rect) noexcept
{
    QVector<QPointF> polygon;
    polygon << converToQPointF(rect.topLeft()) << converToQPointF(rect.topRight()) << converToQPointF(rect.bottomRight()) << converToQPointF(rect.bottomLeft());

    return QPolygonF(polygon);
}
