#include "Point.h"
#include <algorithm>

using namespace std;

typedef vector<Point>::iterator iterator;

Point::Point(int x, int y,
      vector<Point>& input,
      vector<vector<Point> >& results,
      bool useBrute) : px(x), py(y)
{
    if(useBrute)
    {
        for(iterator iter1 = input.begin(); iter1 != input.end(); ++iter1)
        {
            int dx1 = iter1->getX() - px;
            int dy1 = iter1->getY() - py;

            vector<Point> newResult;
            newResult.push_back(*this);
            newResult.push_back(*iter1);

            for(iterator iter2 = iter1++; iter2 != input.end(); ++iter2)
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
    else if(!useBrute)
    {
        sort(input.begin(), input.end(), sortByAngle);

        for(iterator itr1 = input.begin(); itr1 != input.end(); ++itr1)
        {
            vector<Point> newResult;
            newResult.push_back(*itr1);

            for(iterator itr2 = itr1++; itr2 != input.end(); ++itr2)
                if(!sortByAngle(*itr1, *itr2) && !sortByAngle(*itr2, *itr1))
                    newResult.push_back(*itr2);
        }

        if(newResult.size() >= MIN_POINTS)
            results.push_back(newResult);
    }

    input.push_back(*this);
}
