#include "region.h"

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
                shapeRegion = std::shared_ptr<GeometryRegion>(new GeometryRegion());
                *shapeRegion = *r.shapeRegion;
                break;
            case rv::RegionType::Contours:
                contours = std::shared_ptr<Contours<double>>(new Contours<double>(*r.contours));
                break;
            case rv::RegionType::PointSet:
                pointSet = std::shared_ptr<PointSet<double>>(new PointSet<double>(*r.pointSet));
                break;
            case rv::RegionType::Runs:
                runs = std::shared_ptr<Runs<double>>(new Runs<double>(*r.runs));
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
        cv::Mat mask = cv::Mat::zeros(rows, cols, CV_8UC1);

        switch (regionType)
        {
        case rv::RegionType::Geometry:
            if (shapeRegion == nullptr)
            {
                return cv::Mat();
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
            break;
        default:
            break;
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
        std::shared_ptr<Runs<_Tp>> runs(new Runs<_Tp>());
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

}
