#include "stdafx.h"
#include "AdjList.h"

using namespace DataStructures;

AdjList::AdjList() :
    m_time(0),
    m_currentTraversal(TraversalType::None)
{}

DataStructures::AdjList::~AdjList()
{
    std::for_each(begin(m_al), end(m_al),
        [](EdgeList* curList)
    {
        delete curList;
    });
}

void AdjList::SetRoot(int newRoot)
{
    std::for_each(begin(m_al), end(m_al),
        [this, newRoot](EdgeList* curList)
    {
        if (newRoot == curList->GetRoot()->GetKey())
        {
            m_root = curList->GetRoot();
        }
    });
}

int AdjList::GetRoot()
{
    if (m_root)
    {
        return m_root->GetKey();
    }
    else
    {
        throw new std::exception("NO ROOT");
    }
}

void AdjList::InsertVertex(int key)
{
    bool isUniqueKey = true;

    if (m_m.find(key) == end(m_m))
    {
        EdgeList* newList = new EdgeList(new Vertex(key));
        m_al.push_back(newList);
        m_m[key] = static_cast<int>(m_al.size()) - 1;
    }
    else
    {
        std::cout << "!!!! DUPLICATE NODE !!!! Value: " << key << std::endl;
    }
}

void AdjList::InsertEdge(int fromA, int toB, int weight /*=1*/, bool isDirected /*=false*/)
{
    if (m_m.find(fromA) == end(m_m) || m_m.find(toB) == end(m_m))
    {
        std::cout << "!!!! INVALID EDGE - END POINT INVALID !!!! " << fromA << "," << toB << std::endl;
    }
    else
    {
        auto aList = m_al[m_m[fromA]];
        if (aList)
        {
            aList->AddEdge(new Edge(toB, weight));

            if (!isDirected)
            {
                auto bList = m_al[m_m[toB]];
                bList->AddEdge(new Edge(fromA, weight));
            }
        }
    }
}

bool AdjList::HasEdge(int node, int edge)
{
    auto edges = NodeEdges(node);
    bool found = false;

    std::for_each(begin(edges), end(edges), [&found, edge](Edge* e)
    {
        if (e->GetEndPoint() == edge)
            found = true;
    });

    return found;
}

std::list<Edge*> AdjList::NodeEdges(int node)
{
    return m_al[m_m[node]]->GetEdges();
}

std::list<Edge*> DataStructures::AdjList::PrimsMST()
{
    std::list<Edge*> mst;
    std::list<Vertex*> curNodes;
    std::map<int, int> m;

    curNodes.push_front(m_al[0]->GetRoot());
    m_al[0]->GetRoot()->SetInTree(true);

    for (int i = 0; i < m_al.size() - 1; i++)
    {
        std::list<Edge*> curEdges;
        std::for_each(begin(curNodes), end(curNodes),
            [this, &curEdges, &m](Vertex* v) mutable
        {
            auto vEdges = m_al[m_m[v->GetKey()]]->GetEdges();
            std::for_each(begin(vEdges), end(vEdges),
                [&curEdges, &m, v](Edge* e) mutable
            {
                curEdges.push_back(e);
                m[e->GetEndPoint()] = v->GetKey();
            });
        });

        Edge* minWeightEdge = nullptr;
        int curMinWeight = INT_MAX;
        std::for_each(begin(curEdges), end(curEdges),
            [this, &minWeightEdge, curMinWeight, &curNodes](Edge* e) mutable
        {
            if (!m_al[m_m[e->GetEndPoint()]]->GetRoot()->GetInTree() &&
                (e->GetWeight() < curMinWeight))
            {
                minWeightEdge = e;
                curMinWeight = e->GetWeight();
            }
        });

        if (minWeightEdge)
        {
            std::cout << "[" << m[minWeightEdge->GetEndPoint()] << ", " << minWeightEdge->GetEndPoint() << "]" << std::endl;
            mst.push_back(minWeightEdge);
            curNodes.push_back(m_al[m_m[minWeightEdge->GetEndPoint()]]->GetRoot());
            m_al[m_m[minWeightEdge->GetEndPoint()]]->GetRoot()->SetInTree(true);
        }
    }

    return mst;
}

void DataStructures::AdjList::Traverse(TraversalType t)
{
    if (m_root)
    {
        if (t == TraversalType::None || m_root->GetState() == VertexState::Processed)
        {
            this->Reset();
        }

        switch (t)
        {
        case TraversalType::BFS:
            std::cout << "BFS from " << m_root->GetKey() << ":" << std::endl;
            BFS();
            break;
        case TraversalType::DFS:
            std::cout << "DFS from " << m_root->GetKey() << ":" << std::endl;
            DFS(m_root);
            break;
        default:
            std::cout << "Unknown traversal type" << std::endl;
        }

        m_currentTraversal = t;
    }
    else
    {
        std::cout << "Must specify root to BFS" << std::endl;
    }
}

void AdjList::BFS()
{
    std::queue<Vertex*> q;

    for (q.push(m_root); q.size() > 0; q.pop())
    {
        auto curVertex = q.front();
        std::cout << "Processing: " << curVertex->GetKey() << std::endl;
        auto neighbors = NodeEdges(curVertex->GetKey());

        std::for_each(begin(neighbors), end(neighbors),
            [this, &q, curVertex](Edge* e) mutable
        {
            auto curNeighbor = m_al[m_m[e->GetEndPoint()]]->GetRoot();
            if (curNeighbor->GetState() == VertexState::Undiscovered)
            {
                curNeighbor->SetState(VertexState::Discovered);
                curNeighbor->SetParent(curVertex->GetKey());
                q.push(curNeighbor);
            }
        });

        curVertex->SetState(VertexState::Processed);
    }
}

void DataStructures::AdjList::DFS(Vertex* v)
{
    ProcessVertexEarly(v);

    auto neighbors = NodeEdges(v->GetKey());
    std::for_each(begin(neighbors), end(neighbors),
        [this, v](Edge* e) mutable
    {
        auto curNeighbor = m_al[m_m[e->GetEndPoint()]];
        auto curNeighborRoot = curNeighbor->GetRoot();
        if (curNeighborRoot->GetState() == VertexState::Undiscovered)
        {
            curNeighborRoot->SetParent(v->GetKey());
            ProcessEdge(v, e, true);
            DFS(curNeighborRoot);
        }
        else if(curNeighborRoot->GetState() != VertexState::Processed)
        {
            auto curNeighborEdges = curNeighbor->GetEdges();

            std::for_each(begin(curNeighborEdges), end(curNeighborEdges),
                [this, v, e](Edge* edge)
            {
                if (edge->GetEndPoint() == v->GetKey())
                {
                    ProcessEdge(m_al[m_m[edge->GetEndPoint()]]->GetRoot(), e, false);
                }
            });
        }
    });

    ProcessVertexLate(v);
}

void AdjList::ProcessVertexEarly(Vertex* v)
{
    std::cout << "ProcessVertexEarly: " << v->GetKey() << std::endl;
    v->SetEntryTime(++m_time);
    v->SetState(VertexState::Discovered);
}

void AdjList::ProcessVertexLate(Vertex* v)
{
    std::cout << "ProcessVertexLate: " << v->GetKey() << std::endl;
    v->SetExitTime(++m_time);
    v->SetState(VertexState::Processed);
}

void AdjList::ProcessEdge(Vertex* v, Edge* e, bool d)
{
    std::cout << "Process " << (d ? "forward" : "backward") << " edge: " <<  "[" << v->GetKey() << "," << e->GetEndPoint() << "]" << std::endl;

    if (!d && v->GetParent() != e->GetEndPoint())
    {
        std::cout << "Cycle from " << v->GetKey() << " to " << e->GetEndPoint() << std::endl;
    }
}

int AdjList::NodeNotInTree(std::list<Vertex*> vl)
{
    int result = -1;

    std::for_each(begin(vl), end(vl),
        [this, &result](Vertex* v)
    {
        auto curEdges = m_al[m_m[v->GetKey()]]->GetEdges();
        std::for_each(begin(curEdges), end(curEdges),
            [this, &result](Edge* e)
        {
            if (!m_al[m_m[e->GetEndPoint()]]->GetRoot()->GetInTree())
            {
                result = e->GetEndPoint();
            }
        });
    });

    return result;
}

std::list<int> AdjList::FindPath(int v)
{
    std::list<int> path;

    if (m_m.find(v) == end(m_m))
    {
        std::cout << "Unknown vertex " << v << std::endl;
    }
    else if (m_al[m_m[v]]->GetRoot()->GetState() == VertexState::Undiscovered)
    {
        std::cout << "Vertex " << v << " is undiscovered, unable to find path" << std::endl;
    }
    else
    {
        FindPath(v, path);
    }

    return path;
}

int AdjList::NumberOfDecendents(int key)
{
    Vertex* v = m_al[m_m[key]]->GetRoot();

    if (!v || m_currentTraversal != TraversalType::DFS)
    {
        return 0;
    }

    return (v->GetExitTime() - v->GetEntryTime()) / 2;
}

void AdjList::FindPath(int v, std::list<int>& res)
{
    res.push_front(v);

    auto parent = m_al[m_m[v]]->GetRoot()->GetParent();
    if (parent != -1)
    {
        FindPath(parent, res);
    }
}

void AdjList::Reset()
{
    std::for_each(begin(m_al), end(m_al),
        [](EdgeList* curList)
    {
        curList->GetRoot()->Reset();
    });

    m_time = 0;
}

void AdjList::Print()
{
    std::cout << "Root: " << this->GetRoot() << std::endl;

    std::for_each(begin(m_al), end(m_al),
        [](EdgeList* curList)
    {
        std::cout << curList->GetRoot()->GetKey() << ": ";
        PrintList(&curList->GetEdges());
    });
}

void AdjList::PrintParents()
{
    std::cout << "PARENTS:" << std::endl;

    std::for_each(begin(m_al), end(m_al),
        [](EdgeList* curList)
    {
        auto curVertex = curList->GetRoot();
        std::cout << "[" << curVertex->GetKey() << "," << curVertex->GetParent() << "]" << std::endl;
    });
}

void AdjList::PrintList(std::list<Edge*>* list)
{
    std::for_each(begin(*list), end(*list), [](Edge* e)
    {
        std::cout << "[" << e->GetEndPoint() << "," << e->GetWeight() << "]" << " ";
    });

    std::cout << std::endl;
}