#pragma once

#include "TreeNode.h"

namespace DataStructures
{
    ref class RedBlackTree
    {
    public:
        RedBlackTree();

        void Insert(int key);
        bool Delete(int key);
        RedBlackTreeNode^ Find(int key);

        System::Collections::Generic::List<RedBlackTreeNode^>^ GetInOrder();
        void PrintInOrder();


    private:
        RedBlackTreeNode^ m_root;
        RedBlackTreeNode^ m_q;

        void Insert(RedBlackTreeNode^ n);
        void InsertFix(RedBlackTreeNode^ n);
        void LeftRotate(RedBlackTreeNode^ n);
        void RightRotate(RedBlackTreeNode^ n);

        void GetInOrder(RedBlackTreeNode^ n, System::Collections::Generic::List<RedBlackTreeNode^>^ resultList);
        void PrintInOrder(RedBlackTreeNode^);
    };
}
