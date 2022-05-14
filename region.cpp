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
    }

    Region Region::clone() const
    {
        return Region();
    }

    bool Region::empty() const
    {
        return false;
    }

    void Region::clear()
    {
    }

    cv::Mat Region::getRegionMask(int rows, int cols) const
    {
        return cv::Mat();
    }

}
