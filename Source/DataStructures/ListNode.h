#pragma once

namespace DataStructures
{
    ref class ListNode
    {
    public:
        ListNode(int value);

        property int Value;
        property ListNode^ Next;
    };

    ref class DoubleListNode
    {
    public:
        DoubleListNode(int value);

        property int Value;
        property DoubleListNode^ Prev;
        property DoubleListNode^ Next;
    };
}


