#include "Factory.h"
using namespace std;

enum class PointType
{
    cartesian,
    polar
};

class Point
{
    private:
        class PointFactory{
            PointFactory(){}
            public:
            static Point NewCartesian(float x, float y){
                return {x,y};
            }

            static Point NewPolar(float r, float theta){
                return {r*cos(theta), r*sin(theta)};
            }
        };

        Point(float x, float y):x(x),y(y){}
        float x,y;
    public:
        friend ostream &operator << (ostream &os, const Point &p)
        {
            os << "x: "<< p.x<<" y: "<<p.y;
            return os;
        }

        static PointFactory Factory;
};    




void factory_test()
{
    auto p = Point::Factory::NewPolar(5, M_PI_4);
    cout << "("<<p<<")";

    
}