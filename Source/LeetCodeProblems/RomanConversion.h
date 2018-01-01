#pragma once


namespace LeetCodeProblems
{
    static const std::map<int, std::string> RomanNumerals
    {
        { 1, "I" },
        { 4, "IV"},
        { 5, "V" },
        { 9, "IX" },
        { 10, "X" },
        { 40, "XL" },
        { 50, "L" },
        { 90, "XC" },
        { 100, "C" },
        { 400, "CD" },
        { 500, "D" },
        { 1000, "M" }
    };

    static const std::map<std::string, int> Ints
    {
        { "I", 1 },
        { "IV", 4 },
        { "V", 5 },
        { "IX", 9 },
        { "X", 10 },
        { "XL", 40 },
        { "L", 50 },
        { "XC", 90 },
        { "C", 100 },
        { "CD", 400 },
        { "D", 500 },
        { "M", 1000 }
    };

    ref class RomanConversion abstract sealed
    {
    public:
        // #12
        static std::string IntToRoman (int num);
        // #13
        static int RomanToInt(std::string roman);
    };
}