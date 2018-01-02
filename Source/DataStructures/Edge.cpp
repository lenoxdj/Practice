#include "stdafx.h"
#include "Edge.h"

using namespace DataStructures;

Edge::Edge(int from, int to, int w) :
    m_from(from),
    m_to(to),
    m_weight(w)
{}

int Edge::GetFrom()
{
    return m_from;
}

int Edge::GetEndPoint()
{
    return m_to;
}

int Edge::GetWeight()
{
    return m_weight;
}