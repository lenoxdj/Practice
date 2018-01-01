#include "stdafx.h"
#include "RomanConversion.h"

using namespace LeetCodeProblems;

std::string RomanConversion::IntToRoman(int num)
{
    std::string result = "";

    std::vector<int> itemKeys;
    for (auto & kvp : RomanNumerals)
    {
        itemKeys.emplace_back(kvp.first);
    }

    int curKeyPos = 1;
    int curKey = -1;

    while (num > 0)
    {
        curKey = itemKeys[itemKeys.size() - curKeyPos];

        if (num >= curKey)
        {
            result += RomanNumerals.at(curKey);
            num -= curKey;
        }
        else
        {
            curKeyPos++;
        }
    }

    return result;
}

int RomanConversion::RomanToInt(std::string roman)
{
    int returnVal = 0;

    for(int i = (static_cast<int>(roman.size()) - 1); i >= 0; i--)
    {
        std::string curChar = roman.substr(i, 1);

        std::string prevChar = "";
        if (i > 0)
        {
            prevChar = roman.substr(i - 1, 1);
        }

        if (!prevChar.empty() && Ints.find(prevChar + curChar) != Ints.end())
        {
            returnVal += Ints.at(prevChar + curChar);
            i--;
        }
        else if (Ints.find(curChar) != Ints.end())
        {
            returnVal += Ints.at(curChar);
        }
    }

    return returnVal;
}
