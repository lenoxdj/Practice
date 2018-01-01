#include "stdafx.h"
#include "KSum.h"
#include "SortingSearching.h"

using namespace LeetCodeProblems;
using namespace HelperClasses;

std::vector<int> KSum::TwoSum(std::vector<int> nums, int target)
{
    std::map<int, int> numsMap;

    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];
        auto iter = numsMap.find(complement);

        if (iter != end(numsMap))
        {
            return std::vector<int> {nums[i], iter->first};
        }

        numsMap[nums[i]] = i;
    }

    /*
    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];
        auto iter = numsMap.find(complement);

        // iter->first is the key, iter->second is the value, distance from begin is the index
        if (iter != end(numsMap) && (i != std::distance(begin(numsMap), iter)))
        {
            return std::vector<int> {nums[i], iter->first};
        }
    }
    */

    return std::vector<int>{};
}

std::vector<std::vector<int>> KSum::ThreeSum(std::vector<int> nums)
{
    std::vector<std::vector<int>> result;

    for(int i = 0; i < nums.size(); i++)
    {
        int valueNeeded = nums[i] * -1;

        for (int j = 0; j < nums.size(); j++)
        {
            if (j == i)
                continue;

            int newValueNeeded = valueNeeded - nums[j];
            int searchedValue = SortingSearching::BinarySearch(nums, newValueNeeded);

            for (int k = 0; k < nums.size(); k++)
            {
                if (k == i || k == j)
                    continue;

                if (nums[k] == newValueNeeded)
                {
                    auto newResult = std::vector<int>{ nums[i], nums[j], nums[k] };

                    if (!Contains(result, newResult))
                    {
                        result.push_back(newResult);
                    }
                }
            }
        }
    }

    return result;
}

bool KSum::Contains(std::vector<std::vector<int>> result, std::vector<int> newResult)
{
    bool found = false;
    for (int i = 0; i < result.size(); i++)
    {
        auto curResult = result[i];

        if (std::find(begin(curResult), end(curResult), newResult[0]) != end(curResult) &&
            std::find(begin(curResult), end(curResult), newResult[1]) != end(curResult) &&
            std::find(begin(curResult), end(curResult), newResult[2]) != end(curResult))
        {
            found = true;
            break;
        }
    }

    return found;
}


