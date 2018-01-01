#include "Stdafx.h"
#include "GenerateAllParentheses.h"

using namespace LeetCodeProblems;

std::vector<std::string> GenerateAllParentheses::GenerateParenthesis(int n)
{
    std::vector<std::string> result;
    std::string s(n * 2, ' ');
    GenerateAllParenthesis(s, 0, 0, 0, result);
    return result;
}

void GenerateAllParentheses::GenerateAllParenthesis(std::string current, int o, int c, int pos, std::vector<std::string>& result)
{
    if (pos == current.length())
    {
        if (GenerateAllParentheses::CheckParenthesis(current))
        {
            result.push_back(current);
        }
    }
    else
    {
        if (o < current.length() / 2)
        {
            current[pos] = '(';
            GenerateAllParenthesis(current, o + 1, c, pos + 1, result);
        }

        if (c < o)
        {
            current[pos] = ')';
            GenerateAllParenthesis(current, o, c + 1, pos + 1, result);
        }
    }
}

bool GenerateAllParentheses::CheckParenthesis(std::string s)
{
    bool result = true;
    int a = 0;

    std::for_each(begin(s), end(s),
        [&](char cur) mutable
    {
        if (a < 0)
        {
            result = false;
            return;
        }

        switch (cur)
        {
        case '(':
            a++;
            break;
        case ')':
            a--;
            break;
        }
    });

    return result & (a == 0);
}
