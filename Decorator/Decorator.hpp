#include <string>
#include <sstream>
using namespace std;

struct Shape
{
    virtual string str() const =0;
};

struct Circle:Shape
{
    float radius;
    Circle(){}
    Circle(float radius):radius(radius){}

    void resize(float factor){radius*=factor;}

    string str() const override{
        ostringstream oss;
        oss<<"A circle of radius "<<radius;
        return oss.str();
    }
};

struct Square:Shape
{
    float side;
    Square(){}
    Square(float side):side(side){}

    string str() const override{
        ostringstream oss;
        oss<<"A Square with side "<<side;
        return oss.str();
    }
};

//Our decorator
struct ColoredShape:Shape
{
    Shape& shape;
    string color;
    ColoredShape(Shape&shape, const string &color):shape(shape),color(color){}
    string str() const override{
        ostringstream oss;
        oss<<shape.str()<<" has the color"<<color;
        return oss.str();
    }
};
