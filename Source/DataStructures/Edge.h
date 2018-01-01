#pragma once

#include "Vertex.h"

namespace DataStructures
{
    class Edge
    {
    public:
        Edge(int ep, int weight);
        int GetEndPoint();
        int GetWeight();
    private:
        int m_endPoint;
        int m_weight;
    };
}