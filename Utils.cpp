#include "Point.h"
#include <list>
#include <algorithm>

using namespace std;

typedef list<Point>::iterator Iterator;

bool readFromFile(const char* fileName, list<Point>& input)
{
    ifstream file(fileName);
    int num_input = 0;

    if(!file.is_open())
        return 0;

    file >> num_input;

    for(int i = 0; i != num_input; ++i)
    {
        if(file.eof())
            return 0;

        int x, y;
        file >> x >> y;

        input.push_back(Point(x, y));
    }

    return 1;
}

void print(const Point& point)
{
    cout << "x: " << point.getX() << " y: " << point.getY() << "    ";
}

void printResult(const vector<Point>& points)
{
    for_each(points.begin(), points.end(), print);
    cout << endl;
}

void runBrute(list<Point>& input,
              list<list<Point> >& results)
{
    if(result.size() < 2) return;
    for(Iterator iter1 = input.begin(); iter1 != input.end(); ++iter1)
        for(Iterator iter2 = iter + 1; iter2 != input.end(); ++iter2)
        {
            int dx1 = iter1->getX() - iter2->getX();
            int dy1 = iter1->getY() - iter2->getY();
        }

}

void runFast(const vector<Point>& input,
             vector<vector<Point> >& results)
{

}
