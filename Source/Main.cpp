#include "stdafx.h"
#include "RedBlackTree.h"
#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"
#include "SortingSearching.h"
#include "SingleFunctionSolutions.h"
#include "ContainerWithMostWater.h"
#include "RomanConversion.h"
#include "KSum.h"
#include "BinarySearchTree.h"
#include "LRUCache.h"
#include "GenerateAllParentheses.h"
#include "AdjList.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace DataStructures;
using namespace HelperClasses;
using namespace LeetCodeProblems;

void PrintBool(bool result)
{
    if (result)
    {
        std::cout << "TRUE" << std::endl;
    }
    else
    {
        std::cout << "FALSE" << std::endl;
    }
}

int RandomInt(int min, int max)
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(min, max);
    return uni(rng);
}

void FillVectorWithRandomInts(std::vector<int>& v, int num, int min, int max)
{
    v.reserve(num);
    for (int i = 0; i < num; i++)
    {
        v.push_back(RandomInt(min, max));
    }
}

template <typename T>
void PrintList(std::list<T> v)
{
    std::cout << "[ ";

    std::for_each(begin(v), end(v),
        [](T cur)
    {
        std::cout << cur << " ";
    });

    std::cout << "]" << std::endl;
}

template <typename T>
void PrintVector(std::vector<T> v)
{
    std::cout << "[";

    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i];

        if (i != v.size() - 1)
        {
            std::cout << ", ";
        }
    }

    std::cout << "]" << std::endl;
}

template <typename T>
void PrintVectors(std::vector<std::vector<T>> vectors)
{
    std::cout << std::endl;

    for_each(begin(vectors), end(vectors),
        [](std::vector<T> cur)
    {
        PrintVector(cur);
    });
}

int main(array<String^>^ args)
{
    std::cout << "MAIN" << std::endl;
    std::cout << std::endl;

    std::clock_t start;
    double duration;

    std::vector<int> test;
    //FillVectorWithRandomInts(test, 100, 0, 5);
    //PrintVector(test);

    AdjList* al = new AdjList();

    for (int i = 1; i <= 10; i++)
    {
        al->InsertVertex(i);
    }

    al->SetRoot(1);

    // 10 is not connected
    al->InsertEdge(1, 2);
    al->InsertEdge(1, 3);
    al->InsertEdge(2, 3);
    al->InsertEdge(2, 4);
    al->InsertEdge(2, 6);
    al->InsertEdge(3, 4);
    al->InsertEdge(3, 5);
    al->InsertEdge(6, 8);
    al->InsertEdge(6, 7);
    al->InsertEdge(8, 9);

    // Start timer
    start = std::clock();

    al->Traverse(TraversalType::DFS);
    std::cout << std::endl;
    al->PrintParents();
    std::cout << std::endl;
    //std::cout << al->NumberOfDecendents(1) << std::endl;

    // End timer
    duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

    //al->PrintList(&al->NodeEdges(1));
    //al->Print();
    delete al;

    std::cout << std::endl;
    std::cout << "duration: " << duration << "s" << std::endl;
    return 0;
}