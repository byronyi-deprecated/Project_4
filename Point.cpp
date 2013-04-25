#include "Point.h"
#include <iostream>

#define PI 3.1415926535897932384626433832795028831971 //less digit cause bugs when do comparison!!!!

using namespace std;

typedef vector<Point>::iterator Iterator;

struct SortByAngle
{
    SortByAngle(Point p) : basePoint(p) {}

    bool operator()(Point p1, Point p2)
    {
        int dx1 = p1.getX() - basePoint.getX();
        int dx2 = p2.getX() - basePoint.getX();
        int dy1 = p1.getY() - basePoint.getY();
        int dy2 = p2.getY() - basePoint.getY();

        double angle1 = atan2(dx1, dy1);
        double angle2 = atan2(dx2, dy2);

        if(angle1 < 0) angle1 += PI;
        if(angle2 < 0) angle2 += PI;

        return (angle1 < angle2);
    }
    Point basePoint;
};

struct IsColinear
{
    IsColinear(Point p) : basePoint(p) {}

    bool operator()(vector<Point>& result)
    {
        if(result.size() < 2)
            return false;

        Iterator iter = result.begin();
        int dx1 = iter->getX() - basePoint.getX();
        int dy1 = iter->getY() - basePoint.getY();

        ++iter;

        int dx2 = iter->getX() - basePoint.getX();
        int dy2 = iter->getY() - basePoint.getY();

        long long xy1 = dx2 * dy1;
        long long xy2 = dx1 * dy2;

        if(xy1 == xy2) {
            result.push_back(basePoint);
            return true;
        }
        else return false;
    }

    Point basePoint;
};

void Point::findCandidate(vector<Point>& input,
                          vector<vector<Point> >& results,
                          bool useBrute)
{
    if(input.empty()) return;

    IsColinear isColinear(*this);

    for(vector<vector<Point> >::iterator iter = results.begin(); iter != results.end(); ++iter)
        if(isColinear(*iter)) return;

    if(useBrute)
    {
        for(Iterator iter1 = input.begin(); iter1 != input.end(); ++iter1)
        {
            int dx1 = iter1->getX() - px;
            int dy1 = iter1->getY() - py;

            vector<Point> newResult;
            newResult.push_back(*this);
            newResult.push_back(*iter1);

            for(Iterator iter2 = iter1 + 1; iter2 != input.end(); ++iter2)
            {
                int dx2 = iter2->getX() - px;
                int dy2 = iter2->getY() - py;

                long long xy1 = dx2 * dy1;
                long long xy2 = dx1 * dy2;

                if(xy1 == xy2)
                    newResult.push_back(*iter2);
            }

            if(newResult.size() >= MIN_POINTS)
                results.push_back(newResult);
        }
    }
    else
    {
        SortByAngle sortByAngle(*this);
        sort(input.begin(), input.end(), sortByAngle);

        for(Iterator iter1 = input.begin(); iter1 != input.end(); ++iter1)
        {
            vector<Point> newResult;
            newResult.push_back(*this);
            newResult.push_back(*iter1);

            for(Iterator iter2 = iter1 + 1; iter2 != input.end(); ++iter2) {

                if((!sortByAngle(*iter1, *iter2)) && (!sortByAngle(*iter2, *iter1))) {

                    newResult.push_back(*iter2);
                    iter1 = iter2;

                }
                else
                    break;
            }

            if(newResult.size() >= MIN_POINTS)
                results.push_back(newResult);
        }

    }
}
