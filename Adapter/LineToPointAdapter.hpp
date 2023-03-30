#include <stdafx.h>
#include <vector>

struct Point
{
    int x,y;
};

struct Line
{
    Point start,end;
};

struct VectorObject
{
    virtual std::vector<Line>::iterator begin()=0;
    virtual std::vector<Line>::iterator end()=0;
};

struct VectorRectangle:VectorObject
{
    VectorRectangle(int x, int y, int width,int height)
    {
        lines.emplace_back(Line{x,y},Point{x+width,y});
        lines.emplace_back(Line{x+width,y},Point{x+width,y+height});
        lines.emplace_back(Line{x,y},Point{x,y+height});
        lines.emplace_back(Line{x,y+height},Point{x+width,y+height});
    }
    
    std::vector<Line>::iterator begin() override {
        return lines.begin();
    }
    
    std::vector<Line>::iterator end() override {
        return lines.end();
    }

    private: 
    std::vector<Line> lines;
};

struct LineToPointAdapter
{
    typedef std::vector<Point> Points;
    LineToPointAdapter(Line& line){
        static int count = 0;
        int left = min(line.start.x, line.end.x);
        int right = max(line.start.x, line.end.x);
        int top = min(line.start.y, line.end.y);
        int bottom = max(line.start.y, line.end.y);
        int dx=right-left;
        int dy=line.end.y-line.start.y;
        if (dx==0)
        {
            for (int y = top; y <= bottom; ++y)
            {
                points.emplace_back(Point{left,y});
            }
            
        }else if (dy==0)
        {
            for (int x = left; x <= right; ++x)
            {
                points.emplace_back(Point{x,top});
            }
            
        }
        
    }

    virtual std::vector<Point>::iterator begin() {
        return points.begin();
    }
    
    virtual std::vector<Point>::iterator end() {
        return points.end();
    }

    private:
    Points points;
};
