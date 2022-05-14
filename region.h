#pragma once

#include <vector>
#include <geometry/geometry.hpp>
#include <opencv2/opencv.hpp>

namespace rv
{
    enum class RegionType
    {
        None,
        Geometry,   //形状描述法
        Contours,   //轮廓集法(此方法无法描述轮廓和孔洞的关系)
        PointSet,   //离散点集法
        Runs,       //游程编码法
    };

    class GeometryRegion
    {
    public:
        GeometryType type = GeometryType::None;
        Circle<double> circle;
        Line<double> line;
        RotatedRect<double> rotateRect;
        Polygon<double> polygon;
    };

    class Region
    {

    public:
        Region() noexcept;
        Region(const Region& r, bool copyData = false) noexcept;

        Region(const cv::RotatedRect& rect) noexcept;
        template<typename _Tp1, typename _Tp2> Region(const cv::Point_<_Tp1>& p1, const cv::Point_<_Tp2>& p2) noexcept;
        template<typename _Tp> Region(const cv::Point_<_Tp>& center, double radius) noexcept;
        template<typename _Tp> Region(const cv::Rect_<_Tp>& rect) noexcept;
        template<typename _Tp> Region(const cv::Rect_<_Tp>& rect, double angle) noexcept;
        template<typename _Tp> Region(const Line<_Tp>& line) noexcept;
        template<typename _Tp> Region(const Circle<_Tp>& circle) noexcept;
        template<typename _Tp> Region(const Rectangle<_Tp>& rect) noexcept;
        template<typename _Tp> Region(const RotatedRect<_Tp>& rect) noexcept;

        Region(const std::shared_ptr<Contours<double>>& contours) noexcept;
        Region(const std::shared_ptr<PointSet<double>>& pointSet) noexcept;
        Region(const std::shared_ptr<Runs<short>>& runs) noexcept;

        Region(cv::InputArray mask) noexcept;

        //功能函数
        Region clone() const;
        bool empty() const;
        void clear();
        cv::Mat getRegionMask(int rows, int cols) const;        //以opencv的mask方式输出

        template<typename _Tp>
        static std::shared_ptr<Runs<_Tp>> convertToRuns(cv::InputArray mask);

    public:
        RegionType regionType = RegionType::None;               //决定region使用哪种解析方式
        std::shared_ptr<GeometryRegion> shapeRegion;
        std::shared_ptr<Contours<double>> contours;
        std::shared_ptr<PointSet<double>> pointSet;
        std::shared_ptr<Runs<short>> runs;
    };

}

#include "region.inl"