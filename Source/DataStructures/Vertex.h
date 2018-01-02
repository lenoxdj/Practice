#pragma once

namespace DataStructures
{
    enum class VertexState
    {
        Undiscovered,
        Discovered,
        Processed,
    };

    class Vertex
    {
    public:
        Vertex(int key);
        inline bool operator== (const Vertex &other) const;
        int GetKey();
        void SetState(VertexState state);
        VertexState GetState();
        void SetParent(int parent);
        int GetParent();
        void SetEntryTime(int time);
        int GetEntryTime();
        void SetExitTime(int time);
        int GetExitTime();
        bool GetInTree();
        void SetInTree(bool value);

        void Reset();

    private:
        static std::string VertexStateStr(VertexState state);

    private:
        int m_key;
        VertexState m_state;
        int m_parent;
        int m_entryTime;
        int m_exitTime;
        bool m_inTree;
    };
}