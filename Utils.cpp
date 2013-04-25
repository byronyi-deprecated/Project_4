#include "Point.h"
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

void Print(const Point& point) {
    cout << "x: " << point.getX() << " y: " << point.getY() << "    ";
}

void PrintResult(const vector<Point>& points)
{
    for_each(points.begin(), points.end(), Print);
    cout << endl;
}

void openFile(int argc, char* argv[], vector<Point>& input)
{
    const char* argcException("Please specify one input text file.");
    const char* openException("Cannot open given file.");
    const char* readException("The format of input is not correct.");

    if(argc != 2) throw argcException;

    const char* fileName = argv[1];

    ifstream file(fileName);
    int num_input = 0;

    if(!file.is_open())
        throw openException;

    file >> num_input;

    for(int i = 0; i != num_input; ++i)
    {
        if(file.eof())
            throw readException;

        int x, y;
        file >> x >> y;
        input.push_back(Point(x, y));
    }
}
