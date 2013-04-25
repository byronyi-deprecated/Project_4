#include "Fast.h"

Fast::Fast(vector<Point>& raw_input,
            vector<vector<Point> >& result)
{
    vector<Point> input;
    for(vector<Point>::iterator iter = raw_input.begin();
        iter != raw_input.end(); ++iter)
    {
        iter->findCandidate(input, result, false);
        input.push_back(*iter);
    }
}
