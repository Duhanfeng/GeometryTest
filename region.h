#pragma once

#include <vector>
#include <opencv2/opencv.hpp>
#include <geometry/geometry.hpp>

namespace rv
{
    class Region
    {

    };

    enum class RegionType
    {
        None,
        Geometry,   //形状描述法
        Contour,    //轮廓集法
        Runs,       //游程编码法
    };

    class GeometryRegion
    {
        GeometryType type;

    };
}

