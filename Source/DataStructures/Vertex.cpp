#include "stdafx.h"
#include "Vertex.h"

using namespace DataStructures;

Vertex::Vertex(int key) :
    m_key(key),
    m_parent(-1),
    m_state(VertexState::Undiscovered),
    m_entryTime(-1),
    m_exitTime(-1),
    m_inTree(false)
{}

inline bool Vertex::operator==(const Vertex& other) const
{
    return (other.m_key == m_key);
}

int Vertex::GetKey()
{
    return m_key;
}

void Vertex::SetState(VertexState state)
{
    std::cout << GetKey() << " is " << VertexStateStr(state) << std::endl;
    m_state = state;
}

VertexState Vertex::GetState()
{
    return m_state;
}

void Vertex::SetParent(int parent)
{
    //std::cout << "Parent of " << GetKey() << " is " << parent << std::endl;
    m_parent = parent;
}

int Vertex::GetParent()
{
    return m_parent;
}

void Vertex::SetEntryTime(int time)
{
    std::cout << GetKey() << " entry time is " << time << std::endl;
    m_entryTime = time;
}

int Vertex::GetEntryTime()
{
    return m_entryTime;
}

void Vertex::SetExitTime(int time)
{
    std::cout << GetKey() << " exit time is " << time << std::endl;
    m_exitTime = time;
}

int Vertex::GetExitTime()
{
    return m_exitTime;
}

bool Vertex::GetInTree()
{
    return m_inTree;
}

void Vertex::SetInTree(bool value)
{
    m_inTree = value;
}

void Vertex::Reset()
{
    m_entryTime = -1;
    m_exitTime = -1;
    m_parent = -1;
    m_state = VertexState::Undiscovered;
    m_inTree = false;
}

std::string Vertex::VertexStateStr(VertexState state)
{
    switch (state)
    {
    case VertexState::Undiscovered:
        return "Undiscovered";
    case VertexState::Discovered:
        return "Discovered";
    case VertexState::Processed:
        return "Processed";
    default:
        return "Unknown";
    }
}
