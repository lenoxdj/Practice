#include "stdafx.h"
#include "BinarySearchTree.h"

using namespace DataStructures;
using namespace System::Collections;
using namespace System::Collections::Generic;

bool is_perfect_square(int n) {
    if (n < 0)
        return false;
    int root = static_cast<int>(round(sqrt(n)));
    return n == root * root;
}

BinarySearchTree::BinarySearchTree()
{}

void BinarySearchTree::Insert(int value)
{
    BinaryTreeNode^ newNode = gcnew BinaryTreeNode(value);

    if (!m_root)
    {
        m_root = newNode;
    }
    else
    {
        Insert(m_root, newNode);
    }

}

void BinarySearchTree::Remove(int value)
{
    throw gcnew System::NotImplementedException();
}

void BinarySearchTree::Insert(BinaryTreeNode^ curNode, BinaryTreeNode^ newNode)
{
    if (newNode->Key > curNode->Key)
    {
        if (curNode->Right)
        {
            Insert(curNode->Right, newNode);
        }
        else
        {
            curNode->Right = newNode;
        }

    }
    else
    {
        if (curNode->Left)
        {
            Insert(curNode->Left, newNode);
        }
        else
        {
            curNode->Left = newNode;
        }
    }
}

void BinarySearchTree::InOrderTraversal()
{
    InOrderTraversal(m_root);
}

void BinarySearchTree::InOrderTraversal(BinaryTreeNode^ n)
{
    if (n)
    {
        InOrderTraversal(n->Left);
        n->Print();
        InOrderTraversal(n->Right);
    }
}

void BinarySearchTree::LevelOrderTraversal()
{
    LevelOrderTraversal(m_root);
}

// This is breadth first search
void BinarySearchTree::LevelOrderTraversal(BinaryTreeNode^ n)
{
    System::Collections::Queue q = gcnew System::Collections::Queue();

    for (q.Enqueue(n); q.Count > 0; q.Dequeue())
    {
        BinaryTreeNode^ front = static_cast<BinaryTreeNode^>(q.Peek());

        front->Print();

        if (front->Left)
        {
            q.Enqueue(front->Left);
        }
        if (front->Right)
        {
            q.Enqueue(front->Right);
        }
    }
}

int DataStructures::BinarySearchTree::MinValue()
{
    return MinValue(m_root)->Key;
}

BinaryTreeNode^ DataStructures::BinarySearchTree::MinValue(BinaryTreeNode^ n)
{
    if (n->Left)
    {
        return MinValue(n->Left);
    }
    else
    {
        return n;
    }
}

int DataStructures::BinarySearchTree::MaxValue()
{
    return MaxValue(m_root)->Key;
}

BinaryTreeNode^  DataStructures::BinarySearchTree::MaxValue(BinaryTreeNode^ n)
{
    if (n->Right)
    {
        return MaxValue(n->Right);
    }
    else
    {
        return n;
    }
}

int DataStructures::BinarySearchTree::Height()
{
    return Height(m_root);
}

int DataStructures::BinarySearchTree::Height(BinaryTreeNode^ n)
{
    if (!n) return 0;

    return 1 + std::max(Height(n->Left), Height(n->Right));


}
