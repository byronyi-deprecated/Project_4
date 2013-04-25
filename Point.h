#ifndef POINT_H
#define POINT_H

#include <vector>
#include <cmath>
#include <algorithm>
#include <QPoint>

using namespace std;

const unsigned int MIN_POINTS = 4;

class Point
{
public:
    Point(int x, int y) : px(x), py(y) {}

    void findCandidate(vector<Point>& input,
                       vector<vector<Point> >& results,
                       bool useBrute = false);

    int getX() const {return px;}
    int getY() const {return py;}
    const QPoint toQPoint() {return QPoint(px, py);}
private:
    int px;
    int py;
};

#endif // POINT_H
