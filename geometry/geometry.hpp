#pragma once

#include "geometries/size.hpp"
#include "geometries/point.hpp"
#include "geometries/line.hpp"
#include "geometries/rectangle.hpp"
#include "geometries/rotatedRect.hpp"

/*
0.尺寸,Size
1.点,Point
2.直线,Line
3.矩形,Rectangle(位置+尺寸)
4.旋转矩形,RotatedRect
5.圆,Circle
6.圆弧,CircularArc
7.圆环,Annulus
8.圆弧环,Annulus2
9.多边形,Polygon
10.射线,Ray,(基准点+方向)
11.位置,Pose()
12.点集(离散),PointSet
13.线集
*/

enum class GeometryType
{
    None,
    Point,
    Line,
    Rectangle,
    RotatedRect,
    Circle,
    CircularArc,
    Annulus,
    Annulus2,
    Polygon,
    Ray,
    Pose,
    PointSet,
    Lines,
};
