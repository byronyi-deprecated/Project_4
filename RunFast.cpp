#include "Point.h"
#include "Utils.h"
#include "Fast.h"
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char*argv[])
{
    vector<Point> raw_input;
    try{openFile(argc, argv, raw_input);}
    catch(const char* exception){
        cerr << exception << endl;
    }

    vector<vector<Point> > result;

    Fast(raw_input, result);

    for_each(result.begin(), result.end(), PrintResult);

    return 0;
}
