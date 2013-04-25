#include "Brute.h"

Brute::Brute(vector<Point>& raw_input,
            vector<vector<Point> >& result)
{
    vector<Point> input;
    for(vector<Point>::iterator iter = raw_input.begin();
        iter != raw_input.end(); ++iter)
    {
        iter->findCandidate(input, result, true);
        input.push_back(*iter);
    }
}
