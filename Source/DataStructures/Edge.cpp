#include "stdafx.h"
#include "Edge.h"

using namespace DataStructures;

Edge::Edge(int v, int w) :
    m_endPoint(v),
    m_weight(w)
{}

int Edge::GetEndPoint()
{
    return m_endPoint;
}

int Edge::GetWeight()
{
    return m_weight;
}