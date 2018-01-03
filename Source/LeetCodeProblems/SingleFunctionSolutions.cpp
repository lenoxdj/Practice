#include "stdafx.h"
#include "SingleFunctionSolutions.h"
#include "SortingSearching.h"

using namespace LeetCodeProblems;
using namespace HelperClasses;

int SingleFunctionSolutions::ReverseInteger(int x)
{
    int val = 0;
    do
    {
        val = val * 10 + x % 10;
        x /= 10;
    } while (x);

    return (val > INT_MAX || val < INT_MIN) ? 0 : val;
}

int SingleFunctionSolutions::StringToInteger(std::string s)
{
    auto str = s.c_str();
    if (!str) { return 0; }
    int i = 0;
    bool pos = true;
    int res = 0;
    while (str[i] == ' ') { i++; }
    if (str[i] == '+') { pos = true; i++; }
    if (str[i] == '-') { pos = false; i++; }
    if (!isdigit(str[i])) { return 0; }
    while (isdigit(str[i])) {
        if (pos && res>INT_MAX / 10) { return INT_MAX; }
        if (pos && res == INT_MAX / 10 && int(str[i] - '0') >= 7) { return INT_MAX; }
        if (!pos && -res<INT_MIN / 10) { return INT_MIN; }
        if (!pos && -res == INT_MIN / 10 && int(str[i] - '0') >= 8) { return INT_MIN; }
        res = res * 10 + int(str[i] - '0');
        i++;
    }

    if (pos) { return res; }
    else { return -res; }
}

bool SingleFunctionSolutions::IsPalindrome(int x)
{
    std::vector<int> v;
    bool result = true;

    while (x > 0)
    {
        v.push_back(x % 10);
        x /= 10;
    }

    int i = 0;
    for_each(begin(v), v.end() - (v.size() / 2),
        [&i, &result, v](int cur) mutable
    {
        if (v[i] != v[v.size() - 1 - i])
        {
            result = false;
            return;
        }

        i++;
    });

    return result;
}

std::string SingleFunctionSolutions::LongestCommonPrefix(std::vector<std::string> strs)
{
    std::string maxPrefix = "";

    if (strs.size() > 0)
    {
        std::sort(begin(strs), end(strs));

        for (int i = 0; i < static_cast<int>(strs.size()) - 1; i++)
        {
            int lowestSize = std::min(static_cast<int>(strs[i].size()), static_cast<int>(strs[i + 1].size()));
            int j = 1;
            bool prefixMatch = true;

            while (prefixMatch && j <= lowestSize)
            {
                auto leftPrefix = strs[i].substr(0, j);
                auto rightPrefix = strs[i + 1].substr(0, j);
                prefixMatch = (leftPrefix == rightPrefix);

                if (prefixMatch && leftPrefix.size() > maxPrefix.size())
                {
                    maxPrefix = leftPrefix;
                }

                j++;
            }
        }
    }

    return maxPrefix;
}

bool SingleFunctionSolutions::ValidParentheses(std::string s)
{
    // (a), [b], {c}
    int a = 0, b = 0, c = 0;
    bool result = true;

    std::for_each(begin(s), end(s),
        [&](char cur) mutable
    {
        if (a < 0 ||
            a > 1 ||
            b < 0 ||
            b > 1 ||
            c < 0 ||
            c > 1 ||
            (a > 0 && (b != 0 || c != 0)) ||
            (b > 0 && (a != 0 || c != 0)) ||
            (c > 0 && (b != 0 || a != 0)))
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
            case '[':
                b++;
                break;
            case ']':
                b--;
                break;
            case '{':
                c++;
                break;
            case '}':
                c--;
                break;
        }
    });

    result &= (a == 0) && (b == 0) && (c == 0);

    return result;
}

int SingleFunctionSolutions::RemoveDuplicatesFromSortedArray(std::vector<int>& v)
{
    auto itr = begin(v);

    while(itr != end(v))
    {
        int curVal = *itr;
        itr = std::next(itr, 1);

        while (itr != end(v) && (curVal == *itr))
        {
            itr = v.erase(itr);
        }
    }

    return static_cast<int>(v.size());
}

int SingleFunctionSolutions::RemoveElement(std::vector<int>& v, int val)
{
    int last = SingleFunctionSolutions::FindLastPositionThatIsntVal(v, val, static_cast<int>(v.size()) - 1);

    if (last == -1) return static_cast<int>(v.size());

    for (int i = 0; i < last; i++)
    {
        if (v[i] == val)
        {
            v[i] = v[last];
            v[last] = val;
            last = SingleFunctionSolutions::FindLastPositionThatIsntVal(v, val, last - 1);
        }
    }

    return static_cast<int>(std::distance(begin(v), std::find(begin(v), end(v), val)));
}

int LeetCodeProblems::SingleFunctionSolutions::StrStr(std::string haystack, std::string needle)
{
    int result = -1;

    if (std::empty(needle)) return result;

    for (int i = 0; i < (haystack.size() - needle.size()); i++)
    {
        bool found = true;
        for (int j = 0; j < needle.size() - 1; j++)
        {
            if (haystack[i + j] != needle[j])
            {
                found = false;
                break;
            }
        }

        if (found)
            return i;
    }

    return result;
}

int SingleFunctionSolutions::DivideTwoIntegers(int dividend, int divisor)
{
    if (divisor == 0) return INT_MAX;
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    if (dividend == 0) return 0;

    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

    dividend = abs(dividend);
    divisor = abs(divisor);

    int result = 0;
    while (dividend >= divisor)
    {
        result++;
        dividend -= divisor;
    }

    return (sign == 1) ? result : -result;
}

void SingleFunctionSolutions::NextPermutation(std::vector<int>& nums)
{
    int numsSize = static_cast<int>(nums.size());

    if (numsSize > 1)
    {
        int indexFirstDecreasing = -1;

        int curVal = nums[numsSize - 1];
        for (int i = numsSize - 2; i >= 0; i--)
        {
            if (nums[i] < curVal)
            {
                indexFirstDecreasing = i;
                break;
            }

            curVal = nums[i];
        }

        if (indexFirstDecreasing == -1)
        {
            SortingSearching::QuickSort(nums);
            return;
        }

        int indexSmallestLarger = SortingSearching::IndexOfNextLargerValue(nums, indexFirstDecreasing);
        SortingSearching::Swap(nums, indexFirstDecreasing, indexSmallestLarger);
        std::reverse((begin(nums) + indexFirstDecreasing + 1), end(nums));
    }
}


// Helper functions

int SingleFunctionSolutions::FindLastPositionThatIsntVal(std::vector<int> v, int val, int start)
{
    for (int i = start; i >= 0; i--)
    {
        if (v[i] != val)
        {
            return i;
        }
    }

    return -1;
}


