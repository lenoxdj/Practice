#pragma once

#include "Edge.h"

namespace DataStructures
{
    class EdgeList
    {
    public:
        EdgeList(Vertex* root);
        ~EdgeList();
        bool MatchesKey(int key);
        Vertex* GetRoot();
        void AddEdge(Edge* newEdge);
        std::list<Edge*> GetEdges();

    private:
        bool ValidateEdge(int newEdgeVal);

    private:
        std::pair<Vertex*, std::list<Edge*>> m_edges;
    };
}