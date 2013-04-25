#include "mainwindow.h"
#include <QApplication>
#include "Point.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void Print(Point point)
{
    cout << "x: " << point.getX() << " y: " << point.getY() << "    ";
}

void PrintResult(vector<Point> points)
{
    for_each(points.begin(), points.end(), Print);
    cout << endl;
}

int main(int argc, char *argv[])
{
    //    argv[1] = "";
    //    if(argc != 2)
    //    {
    //        cerr << "Please specify one input text file!" << endl;
    //        return -1;
    //    }

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

//    ifstream file("input6.txt");
//    int num_input = 0;

//    if(!file.is_open())
//        return -1;;

//    file >> num_input;

//    vector<Point> input;
//    vector<vector<Point> > results;

//    for(int i = 0; i != num_input; ++i)
//    {
//        if(file.eof())
//            return -1;

//        int x, y;
//        file >> x >> y;

//        Point newPoint(x, y);
//        newPoint.findCandidate(input, results);
//        input.push_back(newPoint);

//    }

//    for_each(results.begin(), results.end(), PrintResult);

//    return 0;
}
