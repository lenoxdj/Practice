#pragma once

// #146
namespace LeetCodeProblems
{
    class LRUCache
    {
    public:
        LRUCache(int capacity);

        int get(int key);
        void put(int key, int value);

        void Print();

    private:
        std::list<int> l;
        std::map<int, int> m;
        int m_capacity;
    };
}