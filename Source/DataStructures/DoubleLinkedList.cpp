#include "stdafx.h"
#include "DoubleLinkedList.h"

using namespace DataStructures;

DoubleLinkedList::DoubleLinkedList() :
    m_head(nullptr)
{
    Size = 0;
}

void DoubleLinkedList::InsertFront(int value)
{
    auto newNode = gcnew DoubleListNode(value);

    if (!m_head)
    {
        newNode->Next = newNode;
        newNode->Prev = newNode;

    }
    else
    {
        newNode->Next = m_head;
        newNode->Prev = m_head->Prev;
        m_head->Prev->Next = newNode;
        m_head->Prev = newNode;
    }

    m_head = newNode;
    Size++;
}

void DoubleLinkedList::InsertAfter(DoubleListNode^ n, int value)
{
    if (n)
    {
        auto newNode = gcnew DoubleListNode(value);

        newNode->Prev = n;
        newNode->Next = n->Next;

        if (n->Next)
        {
            n->Next->Prev = newNode;
        }

        n->Next = newNode;

        Size++;
    }
}

void DoubleLinkedList::InsertEnd(int value)
{
    auto newNode = gcnew DoubleListNode(value);

    if (!m_head)
    {
        m_head = newNode;
    }
    else
    {
        newNode->Next = m_head;
        newNode->Prev = m_head->Prev;

        if (m_head->Prev)
        {
            m_head->Prev->Next = newNode;
        }

        m_head->Prev = newNode;
    }

    Size++;
}

DoubleListNode^ DoubleLinkedList::Find(int value)
{
    DoubleListNode^ curNode = m_head;
    while (curNode)
    {
        if (curNode->Value == value)
        {
            return curNode;
        }

        curNode = curNode->Next;

        if (curNode == m_head)
        {
            break;
        }
    }

    return nullptr;
}

bool DoubleLinkedList::Delete(int value)
{
    bool found = false;
    DoubleListNode^ curNode = m_head;

    if (m_head && m_head->Value == value)
    {
        m_head = nullptr;
        found = true;
    }
    else
    {
        while (curNode)
        {
            if (curNode->Next && curNode->Next->Value == value)
            {
                curNode->Next = curNode->Next->Next;
                curNode->Next->Next->Prev = curNode;
                found = true;
                break;
            }

            curNode = curNode->Next;

            if (curNode == m_head)
            {
                break;
            }
        }
    }

    if (found)
    {
        Size--;
    }

    return found;
}

DoubleListNode^ DoubleLinkedList::PopTail()
{
    if (!m_head)
    {
        return nullptr;
    }

    auto tail = m_head->Prev;
    if (tail == m_head)
    {
        _ASSERTE(Size == 1);
        m_head = nullptr;
        Size = 0;
    }
    else
    {
        m_head->Prev = tail->Prev;
        tail->Prev->Next = m_head;

        Size--;
    }

    return tail;
}

void DoubleLinkedList::Reverse()
{
    auto current = m_head;
    DoubleListNode^ temp = nullptr;

    while (current)
    {
        temp = current->Prev;
        current->Prev = current->Next;
        current->Next = temp;
        current = current->Prev;

        if (current == m_head)
        {
            break;
        }
    }

    if (temp)
    {
        m_head = temp->Prev;
    }
}

void DoubleLinkedList::Print()
{
    std::cout << Size << " nodes: ";
    auto curNode = m_head;
    while (curNode)
    {
        std::cout << curNode->Value << " ";
        curNode = curNode->Next;

        if (curNode == m_head)
        {
            break;
        }
    }
}
