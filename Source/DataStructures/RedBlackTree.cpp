#include "stdafx.h"
#include "RedBlackTree.h"

using namespace DataStructures;
using namespace System::Collections::Generic;

RedBlackTree::RedBlackTree()
{}

void RedBlackTree::Insert(int key)
{
    Insert(gcnew RedBlackTreeNode(key));
}

void RedBlackTree::Insert(RedBlackTreeNode^ n)
{
    RedBlackTreeNode^ p = m_root;
    RedBlackTreeNode^ q = nullptr;

    if (!m_root)
    {
        m_root = n;
        n->Parent = nullptr;
    }
    else
    {
        while (p)
        {
            q = p;
            if (p->Key < n->Key)
            {
                p = p->Right;
            }
            else
            {
                p = p->Left;
            }
        }

        n->Parent = q;
        if (q->Key < n->Key)
        {
            q->Right = n;
        }
        else
        {
            q->Left = n;
        }
    }

    InsertFix(n);
}

void RedBlackTree::InsertFix(RedBlackTreeNode^ n)
{
    RedBlackTreeNode^ u;

    if (m_root == n)
    {
        n->Color = NodeColor::Black;
        return;
    }

    while (n->Parent && n->Parent->Color == NodeColor::Red)
    {
        auto g = n->Parent->Parent;
        if (g->Left == n->Parent)
        {
            if (g->Right)
            {
                u = g->Right;
                if (u->Color == NodeColor::Red)
                {
                    n->Parent->Color = NodeColor::Black;
                    u->Color = NodeColor::Black;
                    g->Color = NodeColor::Red;
                    n = g;
                }
                else
                {
                    n->Parent->Color = NodeColor::Red;
                    u->Color = NodeColor::Red;
                    g->Color = NodeColor::Black;
                    n = g;
                }
            }
            else
            {
                if (n->Parent->Right == n)
                {
                    n = n->Parent;
                    LeftRotate(n);
                }

                n->Parent->Color = NodeColor::Black;
                g->Color = NodeColor::Red;
                RightRotate(g);
            }
        }
        else
        {
            if (g->Left)
            {
                u = g->Left;
                if (u->Color == NodeColor::Red)
                {
                    n->Parent->Color = NodeColor::Black;
                    u->Color = NodeColor::Black;
                    g->Color = NodeColor::Red;
                    n = g;
                }
                else
                {
                    n->Parent->Color = NodeColor::Red;
                    u->Color = NodeColor::Red;
                    g->Color = NodeColor::Black;
                    n = g;
                }
            }
            else
            {
                if (n->Parent->Left == n)
                {
                    n = n->Parent;
                    RightRotate(n);
                }

                n->Parent->Color = NodeColor::Black;
                g->Color = NodeColor::Red;
                LeftRotate(g);
            }
        }

        m_root->Color = NodeColor::Black;
    }
}

void RedBlackTree::LeftRotate(RedBlackTreeNode^ n)
{
    if (!n->Right) return;

    RedBlackTreeNode^ y = n->Right;
    if (y->Left)
    {
        n->Right = y->Left;
        y->Left->Parent = n;
    }
    else
    {
        n->Right = nullptr;
    }

    if (n->Parent)
    {
        y->Parent = n->Parent;
    }

    if (!n->Parent)
    {
        m_root = y;
    }
    else
    {
        if (n == n->Parent->Left)
        {
            n->Parent->Left = y;
        }
        else
        {
            n->Parent->Right = y;
        }
    }

    y->Left = n;
    n->Parent = y;
}

void RedBlackTree::RightRotate(RedBlackTreeNode^ n)
{
    if (!n->Left) return;

    RedBlackTreeNode^ y = n->Left;

    if (y->Right)
    {
        n->Left = y->Right;
        y->Right->Parent = n;
    }
    else
    {
        n->Left = nullptr;
    }

    if (n->Parent)
    {
        y->Parent = n->Parent;
    }

    if (!n->Parent)
    {
        m_root = y;
    }
    else
    {
        if (n == n->Parent->Left)
        {
            n->Parent->Left = y;
        }
        else
        {
            n->Parent->Right = y;
        }
    }

    y->Right = n;
    n->Parent = y;
}

bool RedBlackTree::Delete(int key)
{
    return false;
}

RedBlackTreeNode^ RedBlackTree::Find(int key)
{
    return nullptr;
}

List<RedBlackTreeNode^>^ RedBlackTree::GetInOrder()
{
    auto resultList = gcnew List<RedBlackTreeNode^>();
    GetInOrder(m_root, resultList);
    return resultList;
}

void RedBlackTree::PrintInOrder()
{
    PrintInOrder(m_root);
}

void RedBlackTree::GetInOrder(RedBlackTreeNode^ n, List<RedBlackTreeNode^>^ resultList)
{
    if (n)
    {
        GetInOrder(n->Left, resultList);
        resultList->Add(n);
        GetInOrder(n->Right, resultList);
    }
}

void RedBlackTree::PrintInOrder(RedBlackTreeNode^ n)
{
    if (n)
    {
        PrintInOrder(n->Left);
        n->Print();
        PrintInOrder(n->Right);
    }
}