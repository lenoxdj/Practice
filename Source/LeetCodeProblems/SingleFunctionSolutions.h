#pragma once

namespace LeetCodeProblems
{
    ref class SingleFunctionSolutions abstract sealed
    {
    public:
        static int ReverseInteger(int x); // #7
        static int StringToInteger(std::string s); // #8
        static bool IsPalindrome(int x); // #9
        static std::string LongestCommonPrefix(std::vector < std::string> strs); // #14
        static bool ValidParentheses(std::string s); // #20
        static int RemoveDuplicatesFromSortedArray(std::vector<int>& v); // #26
        static int RemoveElement(std::vector<int>& v, int val); // #27
        static int StrStr(std::string haystack, std::string needle);

    private:
        static int FindLastPositionThatIsntVal(std::vector<int> v, int val, int start);
    };
}
