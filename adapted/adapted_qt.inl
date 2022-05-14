#include "adapted_qt.hpp"
#include <QVector>


/* ----------------------- rv转qt ----------------------- */

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


/* ----------------------- qt转rv ----------------------- */

inline constexpr rv::Size<int> converToSize(const QSize& size) noexcept
{
    return rv::Size<int>((int)size.width(), (int)size.height());
}

inline constexpr rv::Size<int> converToSize(const QSizeF& size) noexcept
{
    return rv::Size<int>((int)size.width(), (int)size.height());
}


inline constexpr rv::Size<double> converToSizeF(const QSize& size) noexcept
{
    return rv::Size<double>((double)size.width(), (double)size.height());
}

inline constexpr rv::Size<double> converToSizeF(const QSizeF& size) noexcept
{
    return rv::Size<double>((double)size.width(), (double)size.height());
}


inline constexpr rv::Point<int> converToPoint(const QPoint& point) noexcept
{
    return rv::Point<int>((int)point.x(), (int)point.y());
}

inline constexpr rv::Point<int> converToPoint(const QPointF& point) noexcept
{
    return rv::Point<int>((int)point.x(), (int)point.y());
}


inline constexpr rv::Point<double> converToPointF(const QPoint& point) noexcept
{
    return rv::Point<double>((double)point.x(), (double)point.y());
}

inline constexpr rv::Point<double> converToPointF(const QPointF& point) noexcept
{
    return rv::Point<double>((double)point.x(), (double)point.y());
}

inline constexpr rv::Rectangle<int> converToRect(const QRect& rect) noexcept
{
    return rv::Rectangle<int>(converToPoint(rect.center()), converToSize(rect.size()));
}

inline constexpr rv::Rectangle<int> converToRect(const QRectF& rect) noexcept
{
    return rv::Rectangle<int>(converToPoint(rect.center()), converToSize(rect.size()));
}


inline constexpr rv::Rectangle<double> converToRectF(const QRect& rect) noexcept
{
    return rv::Rectangle<double>(converToPointF(rect.center()), converToSizeF(rect.size()));
}

inline constexpr rv::Rectangle<double> converToRectF(const QRectF& rect) noexcept
{
    return rv::Rectangle<double>(converToPointF(rect.center()), converToSizeF(rect.size()));
}

