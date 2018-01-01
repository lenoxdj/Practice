#pragma once

namespace DataStructures
{
    public enum class NodeColor
    {
        Red,
        Black,
    };

    ref class BinaryTreeNode
    {
    public:
        BinaryTreeNode(int key);

        int Key;

        property BinaryTreeNode^ Left;
        property BinaryTreeNode^ Right;

        void Print();
    };

    ref class RedBlackTreeNode
    {
    public:
        RedBlackTreeNode(int key);

        property int Key;
        property NodeColor Color;

        property RedBlackTreeNode^ Parent;
        property RedBlackTreeNode^ Left;
        property RedBlackTreeNode^ Right;

        void Print();
    };
}