#ifndef POINT_H
#define POINT_H

#include <vector>
#include <cmath>

using namespace std;

const unsigned int MIN_POINTS = 4;

class Point
{
    struct SortByAngle
    {
        bool opeartor() (Point p1, Point p2)
        {
            double dx1 = p1.px - x;
            double dx2 = p2.px - x;
            double dy1 = p1.py - y;
            double dy2 = p2.py - y;

            if(dx1 == 0)
                dy2 == abs(dy2);
            if(dx2 == 0)
                dy2 == abs(dy2);

            double angle1 = atan2(dx1, dy1);
            double angle2 = atan2(dx2, dy2);
            return (angle1 < angle2);
        }
    } sortByAngle;

public:
    Point(int x, int y) : px(x), py(y) {}
    Point(int x, int y,
          vector<Point>& input,
          vector<vector<Point> >& results,
          bool useBrute = false);

    int getX() const {return px;}
    int getY() const {return py;}
private:
    int px;
    int py;
};

#endif // POINT_H
