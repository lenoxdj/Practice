#pragma once

#include "ListNode.h"

namespace DataStructures
{
    ref class SingleLinkedList
    {
    public:
        SingleLinkedList();

        property int Size;

        void InsertFront(int value);
        void InsertAfter(ListNode^ n, int value);
        void InsertEnd(int value);
        ListNode^ Find(int value);
        bool Delete(int value);
        ListNode^ PopTail();
        void Reverse();
        void Print();

    private:
        ListNode^ m_head;
    };
}