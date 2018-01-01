#include "stdafx.h"
#include "EdgeList.h"

using namespace DataStructures;

EdgeList::EdgeList(Vertex* root)
{
    m_edges.first = root;
}

DataStructures::EdgeList::~EdgeList()
{
    std::for_each(begin(m_edges.second), end(m_edges.second),
        [](Edge* curEdge)
    {
        delete curEdge;
    });
}

bool EdgeList::MatchesKey(int key)
{
    return m_edges.first->GetKey() == key;
}

Vertex* EdgeList::GetRoot()
{
    return m_edges.first;
}

void EdgeList::AddEdge(Edge* newEdge)
{
    if (ValidateEdge(newEdge->GetEndPoint()))
    {
        m_edges.second.push_front(newEdge);
    }
}

std::list<Edge*> EdgeList::GetEdges()
{
    return m_edges.second;
}

bool EdgeList::ValidateEdge(int newEdgeVal)
{
    bool result = true;

    std::for_each(begin(m_edges.second), end(m_edges.second),
        [newEdgeVal, &result](Edge* e)
    {
        if (e->GetEndPoint() == newEdgeVal)
        {
            result = false;
            std::cout << "!!!! INSERTION OF DUPLICATE EDGE !!!! Value: " << newEdgeVal << std::endl;
        }
    });
    return result;
}