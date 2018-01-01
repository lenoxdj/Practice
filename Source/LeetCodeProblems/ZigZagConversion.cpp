// Problem #6
#include "stdafx.h"
#include "ZigZagConversion.h"

using namespace std;
using namespace LeetCodeProblems;

string ZigZagConversion::convert(string s, int nRows)
{
    string res;
    if (nRows == 1) return s;

    for (int i = 0; i < nRows && i < s.size(); i++)
    {
        int inc = 2 * (nRows - i - 1);
        int cur = i;
        int pre = -1;

        while (cur < s.size())
        {
            if (cur != pre)
            {
                res.push_back(s[cur]);
            }

            pre = cur;
            cur += inc;
            inc = 2 * (nRows - 1) - inc;
        }
    }

    return res;
}