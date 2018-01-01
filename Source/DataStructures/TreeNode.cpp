#include "stdafx.h"
#include "TreeNode.h"

using namespace DataStructures;

BinaryTreeNode::BinaryTreeNode(int key)
{
    Key = key;
}

void BinaryTreeNode::Print()
{
    std::cout << "(" << this->Key << ") ";
}

RedBlackTreeNode::RedBlackTreeNode(int key)
{
    Key = key;
}

void RedBlackTreeNode::Print()
{
    std::cout << "(" << this->Key << ") ";
}