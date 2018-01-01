#pragma once

namespace LeetCodeProblems
{
    // #22
    ref class GenerateAllParentheses abstract sealed
    {
    public:
        static std::vector<std::string> GenerateParenthesis(int n);

    private:
        static void GenerateAllParenthesis(std::string current, int o, int c, int pos, std::vector<std::string>& result);
        static bool CheckParenthesis(std::string s);
    };
}
