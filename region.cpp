#include "region.h"
#include <memory>

namespace rv
{
    Region::Region() noexcept
    {

    }

    Region::Region(const Region& r, bool copyData) noexcept
    {
        regionType = r.regionType;

        if (!copyData)
        {
            switch (r.regionType)
            {
            case rv::RegionType::Geometry:
                shapeRegion = r.shapeRegion;
                break;
            case rv::RegionType::Contours:
                contours = r.contours;
                break;
            case rv::RegionType::PointSet:
                pointSet = r.pointSet;
                break;
            case rv::RegionType::Runs:
                runs = r.runs;
                break;
            default:
                break;
            }
        }
        else
        {
            switch (r.regionType)
            {
            case rv::RegionType::Geometry:
                shapeRegion = std::make_shared<GeometryRegion>(); 
                *shapeRegion = *r.shapeRegion;
                break;
            case rv::RegionType::Contours:
                contours = std::make_shared<Contours<double>>(*r.contours); 
                break;
            case rv::RegionType::PointSet:
                pointSet = std::make_shared<PointSet<double>>(*r.pointSet); 
                break;
            case rv::RegionType::Runs:
                runs = std::make_shared<Runs<short>>(*r.runs); 
                break;
            default:
                break;
            }
        }

    }

    Region::Region(const std::shared_ptr<Contours<double>>& contours) noexcept
    {
        regionType = RegionType::Contours;
        this->contours = contours;
    }

    Region::Region(const std::shared_ptr<PointSet<double>>& pointSet) noexcept
    {
        regionType = RegionType::PointSet;
        this->pointSet = pointSet;
    }

    Region::Region(const std::shared_ptr<Runs<short>>& runs) noexcept
    {
        regionType = RegionType::Runs;
        this->runs = runs;
    }

    Region::Region(cv::InputArray mask) noexcept
    {
        regionType = RegionType::Runs;
        this->runs = convertToRuns(mask);
    }

    Region Region::clone() const
    {
        return Region(*this, true);
    }

    bool Region::empty() const
    {
        return (regionType == RegionType::None);
    }

    void Region::clear()
    {
        shapeRegion = std::shared_ptr<GeometryRegion>();
        contours = std::shared_ptr<Contours<double>>();
        pointSet = std::shared_ptr<PointSet<double>>();
        runs = std::shared_ptr<Runs<short>>();
        regionType = RegionType::None;
    }

    cv::Mat Region::getRegionMask(int rows, int cols) const
    {
        cv::Mat mask;
        
        switch (regionType)
        {
        case rv::RegionType::Geometry:
            if (shapeRegion == nullptr)
            {
                return cv::Mat();
            }

            switch (shapeRegion->type)
            {
            case GeometryType::Line:
                mask = cv::Mat::zeros(rows, cols, CV_8UC1);
                cv::line(mask, converToCvPoint(shapeRegion->line.p1), converToCvPoint(shapeRegion->line.p2), {255, 255, 255}, 1, 8);
                break;
            case GeometryType::Circle:
                mask = cv::Mat::zeros(rows, cols, CV_8UC1);
                cv::circle(mask, converToCvPoint(shapeRegion->circle.center), shapeRegion->circle.radius, {255, 255, 255}, cv::FILLED, 8);
                break;
            case GeometryType::RotatedRect:
            {
                cv::Point2f pts[4];
                converToCvRotatedRect(shapeRegion->rotateRect).points(pts);
                cv::Point pts2[4];
                for (size_t i = 0; i < 4; i++)
                {
                    pts2[i] = pts[i];
                }
                mask = cv::Mat::zeros(rows, cols, CV_8UC1);
                cv::fillConvexPoly(mask, pts2, 4, { 255, 255, 255 });
                break;
            }
            case GeometryType::Polygon:

                break;
            default:
                break;
            }
            
            break;
        case rv::RegionType::Contours:
            if (contours == nullptr)
            {
                return cv::Mat();
            }


            break;
        case rv::RegionType::PointSet:
            if (pointSet == nullptr)
            {
                return cv::Mat();
            }
            break;
        case rv::RegionType::Runs:
            if (runs == nullptr)
            {
                return cv::Mat();
            }
            return drawRuns(runs, rows, cols);
        default:
            return cv::Mat();
        }

        return mask;
    }

    std::shared_ptr<Runs<short>> Region::convertToRuns(cv::InputArray mask)
    {
        using _Tp = short;

        if (mask.empty())
        {
            return std::shared_ptr<rv::Runs<_Tp>>();
        }

        cv::Mat cvMask = mask.getMat();

        _Tp _r = 0;
        _Tp _cb = 0;
        _Tp _ce = 0;

        //游程编码
        std::shared_ptr<Runs<_Tp>> runs = std::make_shared<Runs<_Tp>>(); 
        for (int r = 0; r < cvMask.rows; r++)
        {
            uchar* data = cvMask.ptr(r);
            bool isStart = false;
            for (int c = 0; c < cvMask.cols; c++)
            {
                if (!isStart)
                {
                    if (*data != 0)
                    {
                        isStart = true;
                        
                         _r = _Tp(r);
                        _cb = _Tp(c);
                    }
                }
                else
                {
                    //如果已经开始,而当前为0,则认为已经结束
                    if (*data == 0)
                    {
                        isStart = false;
                        _ce = _Tp(c - 1);
                    }
                }

                data++;
            }

            //如果查找到末尾,则保存末尾
            if (isStart)
            {
                _ce = _Tp(cvMask.cols - 1);
            }

            runs->emplace_back(Run<_Tp>(_r, _cb, _ce));
        }

        return runs;
    }

    rv::Region Region::mask2Region(cv::InputArray mask)
    {
        
        return rv::Region(convertToRuns(mask));
    }

    cv::Mat Region::drawRuns(std::shared_ptr<Runs<short>> runs, int rows, int cols)
    {
        cv::Mat mask = cv::Mat::zeros(rows, cols, CV_8UC1);

        if (runs == nullptr)
        {
            mask;
        }

        size_t _size = runs->size();
        for (size_t i = 0; i < _size; i++)
        {
            cv::line(mask, {(*runs)[i].r, (*runs)[i].cb}, {(*runs)[i].r, (*runs)[i].ce}, {255, 255, 255});
        }

        return mask;
    }
}
