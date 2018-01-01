#include "stdafx.h"
#include "SingleLinkedList.h"

using namespace DataStructures;

SingleLinkedList::SingleLinkedList() :
    m_head(nullptr)
{
    Size = 0;
}

void SingleLinkedList::InsertFront(int value)
{
    auto newNode = gcnew ListNode(value);

    newNode->Next = m_head;
    m_head = newNode;

    Size++;
}

void SingleLinkedList::InsertAfter(ListNode^ n, int value)
{
    if (n)
    {
        auto newNode = gcnew ListNode(value);
        newNode->Next = n->Next;
        n->Next = newNode;
        Size++;
    }
}

void SingleLinkedList::InsertEnd(int value)
{
    auto newNode = gcnew ListNode(value);

    if (!m_head)
    {
        m_head = newNode;
    }
    else
    {
        auto curNode = m_head;
        while (curNode->Next)
        {
            curNode = curNode->Next;
        }

        // curNode is now the tail
        curNode->Next = newNode;
    }

    Size++;
}

ListNode^ SingleLinkedList::Find(int value)
{
    auto curNode = m_head;

    while (curNode)
    {
        if (curNode->Value == value)
        {
            return curNode;
        }

        curNode = curNode->Next;
    }

    return nullptr;
}

bool SingleLinkedList::Delete(int value)
{
    bool found = false;

    if (m_head && m_head->Value == value)
    {
        m_head = m_head->Next;
        found = true;
    }
    else
    {
        auto curNode = m_head;
        while (curNode)
        {
            if (curNode->Next && (curNode->Next->Value == value))
            {
                curNode->Next = curNode->Next->Next;
                found = true;
                break;
            }

            curNode = curNode->Next;
        }
    }

    if (found)
    {
        Size--;
    }

    return found;
}

ListNode^ SingleLinkedList::PopTail()
{
    auto curNode = m_head;
    ListNode^ tail = nullptr;

    while (curNode)
    {
        if (curNode->Next && !curNode->Next->Next)
        {
            tail = curNode->Next;
            curNode->Next = nullptr;
        }

        curNode = curNode->Next;
    }

    return tail;
}

void SingleLinkedList::Reverse()
{
    ListNode^ curNode = m_head;
    ListNode^ nextNode = nullptr;
    m_head = nullptr;

    while (curNode)
    {
        nextNode = curNode->Next;
        curNode->Next = m_head;
        m_head = curNode;
        curNode = nextNode;
    }
}

void SingleLinkedList::Print()
{
    std::cout << Size << " nodes: ";
    auto curNode = m_head;
    while (curNode)
    {

        std::cout << curNode->Value << " ";
        curNode = curNode->Next;
    }

    std::cout << std::endl;
}
