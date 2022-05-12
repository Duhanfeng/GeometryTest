#pragma once

#include "geometries/size.hpp"
#include "geometries/point.hpp"
#include "geometries/line.hpp"
#include "geometries/rectangle.hpp"
#include "geometries/rotatedRect.hpp"
#include "geometries/circle.hpp"
#include "geometries/arc.hpp"
#include "geometries/annulus.hpp"
#include "geometries/ray.hpp"
#include "geometries/pose.hpp"

/*
0.尺寸,Size
1.点,Point
2.直线,Line
3.矩形,Rectangle
4.旋转矩形,RotatedRect
5.圆,Circle
6.圆弧,Arc
7.圆环,Annulus
8.多边形,Polygon
9.射线,Ray
10.位置,Pose
11.点集(离散),PointSet
11.轮廓,Contour
12.线集
*/

enum class GeometryType
{
    None,
    Point,
    Line,
    Rectangle,
    RotatedRect,
    Circle,
    Arc,
    Annulus,
    Polygon,
    Ray,
    Pose,
    PointSet,
    Contour,
    Lines,
};
