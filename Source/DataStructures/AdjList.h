#pragma once

#include "EdgeList.h"

namespace DataStructures
{
    enum class TraversalType
    {
        None,
        BFS,
        DFS,
    };

    class AdjList
    {
    public:
        AdjList();
        ~AdjList();
        void SetRoot(int newRoot);
        int GetRoot();
        void InsertVertex(int key);
        void InsertEdge(int a, int b, int weight = 1, bool isDirected = false);
        bool HasEdge(int node, int edge);
        std::list<Edge*> NodeEdges(int node);
        std::list<Edge*> PrimsMST();

        void Traverse(TraversalType t);
        std::list<int> FindPath(int v);
        int NumberOfDecendents(int v);

        void Print();
        void PrintParents();
        static void PrintList(std::list<Edge*>* list);

    private:
        void BFS();
        void DFS(Vertex* v);
        void ProcessVertexEarly(Vertex* v);
        void ProcessVertexLate(Vertex* v);
        void ProcessEdge(Vertex* v, Edge* e, bool direction);
        int NodeNotInTree(std::list<Vertex*> vl);
        void Reset();

        void FindPath(int start, std::list<int>& res);
        std::vector<EdgeList*> m_al;
        std::map<int, int> m_m;
        Vertex* m_root;
        int m_time;
        TraversalType m_currentTraversal;
    };
}