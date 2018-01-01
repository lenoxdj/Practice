#pragma once

#include "ListNode.h"

namespace DataStructures
{
    ref class DoubleLinkedList
    {
    public:
        DoubleLinkedList();

        property DoubleListNode^ Root;
        property int Size;

        void InsertFront(int value);
        void InsertAfter(DoubleListNode^ n, int value);
        void InsertEnd(int value);
        DoubleListNode^ Find(int value);
        bool Delete(int value);
        DoubleListNode^ PopTail();
        void Reverse();
        void Print();

    private:
        DoubleListNode^ m_head;
    };
}