#pragma once

namespace HelperClasses
{
    ref class SortingSearching abstract sealed
    {
    public:
        static void BubbleSort(std::vector<int> &v);
        static void InsertionSort(std::vector<int> &v);
        static void MergeSort(std::vector<int> &v);
        static void Merge(std::vector<int> &v, std::vector<int> a, std::vector<int> b);
        static void QuickSort(std::vector<int> &v);
        static int Fib(int n);

        static int LinearSearch(std::vector<int> v, int key);
        static int BinarySearch(std::vector<int> v, int key);

        static void PrintArr(std::vector<int> v);

    private:
        static void Swap(std::vector<int> &v, int i, int j);
        static void MergeSort(std::vector<int> &v, int start, int end);
        static void Merge(std::vector<int>& v, int start, int end);
        static void QuickSort(std::vector<int> &v, int left, int right);
        static int BinarySearch(std::vector<int> v, int key, int low, int high);
    };
}
