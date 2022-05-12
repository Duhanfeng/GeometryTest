// CMakeProject2.cpp: 定义应用程序的入口点。
//

//#include <boost/geometry.hpp>
//#include <boost/geometry/geometries/point_xy.hpp>
//#include <boost/geometry/geometries/polygon.hpp>
//#include <boost/geometry/geometries/adapted/boost_polygon.hpp>

#include "rmath.h"
#include "wykobi/wykobi.hpp"
#include "geometry/geometry.hpp"

using namespace std;
//using namespace boost::geometry;
//
//namespace rv
//{
//    template<typename CoordinateType, typename CoordinateSystem = cs::cartesian>
//    using pointxy = boost::geometry::model::d2::point_xy<CoordinateType, CoordinateSystem>;
//
//}

int main()
{
    rv::Size<double> size(10.5, 20.2);
    std::cout << size.width << "," << size.height << std::endl;

    size *= 3;
    std::cout << size.width << "," << size.height << std::endl;

    size /= 2;
    std::cout << size.width << "," << size.height << std::endl;

    size = size * 2;
    std::cout << size.width << "," << size.height << std::endl;

    rv::Size<int> size2;
    size2 = size;
    std::cout << size2.width << "," << size2.height << std::endl;

    rv::Size<> size3;
    
    rv::Point<double> p1(30, 20);
    rv::Point<double> center(20, 20);

    rv::Point<double> p2 = p1.rotate(center, rv::deg2rad(45));
    std::cout << p2.x << "," << p2.y << "," << rv::rad2deg(center.angle(p2)) << std::endl;

    p2 = p1.rotate(center, rv::deg2rad(90));
    std::cout << p2.x << "," << p2.y << "," << rv::rad2deg(center.angle(p2)) << std::endl;

    //生成矩形
    rv::Rectangle<double> rect(p2, size);
    auto topLeft = rect.topLeft();
    std::cout << topLeft.x << "," << topLeft.y  << std::endl;

    std::vector<rv::Point<double>> points = rect.getPoints();
    std::cout << points.at(0).x << "," << points[0].y << std::endl;

    //圆
    rv::Circle<double> circle;

    //射线
    rv::Ray<double> ray;

    //圆弧
    rv::Arc<double> arc(10.1, 102.3, 1, 2, 3);
    rv::Arc<int> arc2(arc);

    //圆环
    rv::Annulus<double> annulus;

    //多边形
    rv::Polygon<double> polygon;
    polygon.push_back(p1);
    polygon.push_back(rv::Point<double>(10, 20));
    polygon.push_back(rv::Point<double>(10, 20));



 //   wykobi::line<double, 2> _line[4];
 //   _line[0] = wykobi::make_line<double>(1.0, 1.0, 2, 2);

 //   if (wykobi::intersect(_line[0], _line[1]))
 //   {
 //       wykobi::point2d<double> wp = wykobi::intersection_point(_line[0], _line[1]);
 //       
 //   }

    //typedef boost::polygon::rectangle_data<int> rect;
    //rect b = boost::polygon::construct<rect>(1, 2, 3, 4);

 //   std::cout << "Area (using Boost.Geometry): "
 //       << boost::geometry::area(b) << std::endl;
 //   
 //   std::cout << sizeof(rect) << "," << sizeof(rv::pointxy<double>) << std::endl;

 //   model::d2::point_xy<double> p1(1, 1), p2(2, 2);
 //   std::cout << "Distance p1-p2 is: " << distance(p1, p2) << std::endl;

 //   rv::pointxy<double> p3(1.0, 1), p4(2, 2);

 //   

 //   std::cout << "Distance p3-p4 is: " << distance(p3, p4) << std::endl;

	//cout << "Hello CMake." << endl;
	return 0;
}
