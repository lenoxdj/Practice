#pragma once

#include "Vertex.h"

namespace DataStructures
{
    class Edge
    {
    public:
        Edge(int from, int to, int weight);
        int GetFrom();
        int GetEndPoint();
        int GetWeight();
    private:
        int m_from;
        int m_to;
        int m_weight;
    };
}