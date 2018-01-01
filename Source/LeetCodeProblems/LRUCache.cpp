#include "stdafx.h"
#include "LRUCache.h"

using namespace LeetCodeProblems;

LRUCache::LRUCache(int capacity) :
    m_capacity(capacity)
{
}

int LRUCache::get(int key)
{
    auto itr = std::find(begin(l), end(l) , key);

    // Not found
    if (itr == end(l)) return -1;

    l.erase(itr);
    l.push_front(key);

    return m[key];
}

void LRUCache::put(int key, int value)
{
    if (l.size() == m_capacity)
    {
        m.erase(l.back());
        l.pop_back();
    }

    l.push_front(key);
    m[key] = value;
}

void LRUCache::Print()
{
    std::cout << std::endl;

    std::for_each(begin(l), end(l),
        [this](int key)
    {
        std::cout << "[" << key << "," << m[key] << "]" << std::endl;
    });
}