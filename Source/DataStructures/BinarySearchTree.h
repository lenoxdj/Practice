#pragma once

#include "TreeNode.h"

namespace DataStructures
{
    ref class BinarySearchTree
    {
    public:
        BinarySearchTree();

        void Insert(int value);
        void Remove(int value);
        int MinValue();
        int MaxValue();
        int Height();
        void InOrderTraversal();
        void LevelOrderTraversal();

    private:
        void Insert(BinaryTreeNode^ curNode, BinaryTreeNode^ newNode);
        void InOrderTraversal(BinaryTreeNode^ n);
        void LevelOrderTraversal(BinaryTreeNode^ n);
        BinaryTreeNode^ MinValue(BinaryTreeNode^ n);
        BinaryTreeNode^ MaxValue(BinaryTreeNode^ n);
        int Height(BinaryTreeNode^ n);

        BinaryTreeNode^ m_root;

    };
}