#include "stdafx.h"
#include "SortingSearching.h"

using namespace HelperClasses;

void SortingSearching::BubbleSort(std::vector<int> &v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v.size() - i - 1; ++j)
        {
            if (v[j] > v[j + 1])
            {
                Swap(v, j, j + 1);
            }
        }
    }
}

void SortingSearching::InsertionSort(std::vector<int>& v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        int j = i;

        while (j > 0 && v[j] < v[j-1])
        {
            Swap(v, j, j-1);
            j--;
        }
    }
}

void SortingSearching::MergeSort(std::vector<int> &v)
{
    MergeSort(v, 0, static_cast<int>(v.size()));
}

void SortingSearching::MergeSort(std::vector<int> &v, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;

        MergeSort(v, start, mid);
        MergeSort(v, mid + 1, end);
        Merge(v,start,end);
    }
}

void SortingSearching::QuickSort(std::vector<int> &v)
{
    QuickSort(v, 0, static_cast<int>(v.size()) - 1);
}

int SortingSearching::Fib(int n)
{
    static std::map<int, int> storedValues;

    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        int first;
        if (storedValues.find(n - 1) != storedValues.end())
        {
            first = storedValues[n - 1];
        }
        else
        {
            first = Fib(n - 1);
            storedValues[n - 1] = first;
        }

        int second;
        if(storedValues.find(n - 2) != storedValues.end())
        {
            second = storedValues[n - 2];
        }
        else
        {
            second = Fib(n - 2);
            storedValues[n - 2] = second;
        }

        return first + second;
    }
}

int SortingSearching::IndexOfNextLargerValue(std::vector<int> v, int curIndex)
{
    int retVal = -1;

    if (curIndex >= 0 && v.size() > 1 && curIndex < v.size())
    {
        int valAtCurIndex = v[curIndex];
        auto copyOfV = v;
        std::sort(begin(v) + curIndex, end(v));

        int valOfNextLarger = -1;
        for (int i = curIndex + 1; i < v.size(); i++)
        {
            if (v[i] > valAtCurIndex)
            {
                valOfNextLarger = v[i];
                break;
            }
        }

        for (int i = curIndex; i < copyOfV.size(); i++)
        {
            if (copyOfV[i] == valOfNextLarger)
            {
                retVal = i;
                break;
            }
        }
    }

    return retVal;
}

int SortingSearching::LinearSearch(std::vector<int> v, int key)
{
    int retVal = -1;

    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] == key)
        {
            retVal = i;
            break;
        }
    }

    return retVal;
}

int SortingSearching::BinarySearch(std::vector<int> v, int key)
{
    return BinarySearch(v, key, 0, static_cast<int>(v.size() - 1));
}

void SortingSearching::Swap(std::vector<int>& v, int i, int j)
{
    auto vSize = v.size();
    if (i >= 0 && j >= 0 && i < vSize && j < vSize && i != j)
    {
        auto temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
}

void SortingSearching::Merge(std::vector<int>& v, std::vector<int> a, std::vector<int> b)
{
    int i = 0;
    int j = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            v.push_back(a[i]);
            i++;
        }
        else
        {
            v.push_back(b[j]);
            j++;
        }
    }

    if (i == a.size())
    {
        while (j < b.size())
        {
            v.push_back(b[j]);
            j++;
        }
    }
    else
    {
        while (i < a.size())
        {
            v.push_back(a[i]);
            i++;
        }
    }
}

void SortingSearching::Merge(std::vector<int>& v, int start, int end)
{
    int len = abs(start - end);
    std::sort(v.begin() + start, v.begin() + start + len);
}

void SortingSearching::QuickSort(std::vector<int>& v, int left, int right)
{
    int m = (left + right) / 2;
    int i = left;
    int j = right;
    int pivot = v[m];

    while (left < j || i < right)
    {
        while (v[i] < pivot)
        {
            i++;
        }
        while (v[j] > pivot)
        {
            j--;
        }

        if (i <= j)
        {
            Swap(v, i, j);
            i++;
            j--;
        }
        else
        {
            if (left < j)
            {
                QuickSort(v, left, j);
            }
            if (i < right)
            {
                QuickSort(v, i, right);
            }

            return;
        }
    }
}

int SortingSearching::BinarySearch(std::vector<int> v, int key, int low, int high)
{
    if (low >= high)
    {
        return -1;
    }

    int mid = (low + high) / 2;

    if (v[mid] > key)
        return BinarySearch(v, key, low, mid);
    else if (v[mid] < key)
        return BinarySearch(v, key, mid + 1, high);
    else
        return mid;
}

void SortingSearching::PrintArr(std::vector<int> v)
{
    std::cout << std::endl;

    std::for_each(begin(v), end(v), [](int val)
    {
        std::cout << val << " ";
    });

    std::cout << std::endl;
}