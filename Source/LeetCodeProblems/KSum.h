#pragma once

namespace LeetCodeProblems
{
    ref class KSum abstract sealed
    {
    public:
        static std::vector<int> TwoSum(std::vector<int> nums, int target); // #1
        static std::vector<std::vector<int>> ThreeSum(std::vector<int> nums); // #15
        static bool Contains(std::vector<std::vector<int>> result, std::vector<int> newResult);
    };
}