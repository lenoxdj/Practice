#include "stdafx.h"
#include "ListNode.h"

using namespace DataStructures;

ListNode::ListNode(int value)
{
    Value = value;
    Next = nullptr;
}

DoubleListNode::DoubleListNode(int value)
{
    Value = value;
    Prev = nullptr;
    Next = nullptr;
}