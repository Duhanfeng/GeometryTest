// CMakeProject2.cpp: 定义应用程序的入口点。
//

//#include <boost/geometry.hpp>
//#include <boost/geometry/geometries/point_xy.hpp>
//#include <boost/geometry/geometries/polygon.hpp>
//#include <boost/geometry/geometries/adapted/boost_polygon.hpp>

#include "rmath.h"
#include "wykobi/wykobi.hpp"
#include "geometry/geometry.hpp"
#include <array>
#include <list>
#include <QDebug>
#include "adapted/adapted_qt.hpp"
#include "adapted/adapted_cv.hpp"
#include "region.h"


using namespace std;
//using namespace boost::geometry;
//
//namespace rv
//{
//    template<typename CoordinateType, typename CoordinateSystem = cs::cartesian>
//    using pointxy = boost::geometry::model::d2::point_xy<CoordinateType, CoordinateSystem>;
//
//}



template<
    typename _Tp = double,                                          //类型
    template<typename, typename> class Container = std::vector,     //容器
    template<typename> class Allocator = std::allocator             //构造器
>
class Polygon : public Container<rv::Point<_Tp>, Allocator<rv::Point<_Tp>>>
{
    typedef Container<rv::Point<_Tp>, Allocator<rv::Point<_Tp>>> base_type;
public:

    //构造
    constexpr Polygon() noexcept : base_type() {}
    template <typename Iterator> constexpr Polygon(Iterator begin, Iterator end) noexcept : base_type(begin, end) {}
    constexpr Polygon(std::initializer_list<rv::Point<_Tp>> l) noexcept : base_type(l.begin(), l.end()) {}

    //功能封装

};

void geometryTest();
void qtTest();
void cvTest();
void regionTest();

int main()
{
    geometryTest();
    qtTest();
    cvTest();
    regionTest();

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

	return 0;
}

void qtTest()
{
    std::cout << "qtTest------------" << std::endl;

    //点
    rv::Point<double> point(20.1, 13.5);
    QPointF p = converToQPointF(point);
    std::cout << p.x() << "," << p.y() << std::endl;

    //多边形
    rv::Rectangle<double> rect(100, 100, 80, 50);
    QPolygon polygon = converToQPolygon(rect);
    qDebug() << polygon;

    rv::RotatedRect<double> rect2(100, 100, 80, 50, rv::deg2rad(10));
    QPolygon polygon2 = converToQPolygon(rect2);
    qDebug() << polygon2;

}

void cvTest()
{
    rv::Size<double> size(250, 250);
    rv::Point<double> point(100, 200);
    rv::Rectangle<double> rect(250, 250, 50, 80);
    rv::RotatedRect<double> rect2(250, 250, 50, 80, rv::deg2rad(10));

    converToCvSize(size);
    converToCvPoint(point);
    converToCvRect(rect);
    converToCvRotatedRect(rect2);

    converToCvSizeF(size);
    converToCvPointF(point);
    converToCvRectF(rect);
    //converToCvRotatedRect(rect2);

    rect2 = converToRotatedRect(converToCvRotatedRect(rect2));

}

void geometryTest()
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
    std::cout << topLeft.x << "," << topLeft.y << std::endl;

    std::vector<rv::Point<double>> points = rect.getPoints();
    std::cout << points.at(0).x << "," << points[0].y << std::endl;

    //圆
    rv::Circle<double> circle;

    //射线
    rv::Ray<double> ray;

    //圆弧
    rv::Arc<double> arc(10.1, 102.3, 1, 2, 3);
    rv::Arc<int> arc2(arc);

    rv::Arc<double> arc3 = arc.move(5, 10.2);
    rv::Arc<double> arc4 = arc.rotate({0,0}, rv::deg2rad(10));

    //圆环
    rv::Annulus<double> annulus;

    //多边形
    rv::Polygon<double> polygon;
    polygon.push_back(p1);
    polygon.push_back(rv::Point<double>(10, 20));
    polygon.push_back(rv::Point<double>(10, 20));

    polygon *= 3;
    polygon /= 3;
    polygon = polygon * 3;
    polygon = polygon / 3;

    rv::Polygon<double> polygon2 = polygon.move(1, 2);
    rv::Polygon<double> polygon3 = polygon.rotate(rv::Point<double>(0, 0), rv::deg2rad(-20));
    rv::Polygon<int> polygon4(polygon3);

    std::array<double, 4> p41 = { 0, 0, 0, 0 };
    p41[0] = 3;

    //行程编码
    rv::Runs<short> runs;
    runs.emplace_back(rv::Run<>{10, 20, 20});
    runs.move(20, 30);

    runs *= 3;
    runs /= 5;
    rv::Runs<short> runs2 = runs * 5;
    runs2 = runs / 3;
    rv::Runs<double> run3 = runs2;

    //轮廓
    rv::Contours<double> contours;
    contours.emplace_back(polygon);
    contours.emplace_back(polygon2);
    contours.emplace_back(polygon3);
    contours.emplace_back(polygon4);

    rv::Contours<double> contours2 = contours.rotate({ 0, 0 }, 1);



}

void regionTest()
{

}