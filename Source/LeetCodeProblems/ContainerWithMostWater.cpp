#include "stdafx.h"
#include "ContainerWithMostWater.h"

using namespace LeetCodeProblems;

Container* ContainerWithMostWater::MaxArea(std::vector<int>& heights)
{
    std::vector<Container*> containers;
    int curLeft = -1;
    int curRight = -1;
    int numVerticals = 0;

    for (int i = 0; i < heights.size(); i++)
    {
        if (heights[i] == 0)
        {
            continue;
        }
        else
        {
            numVerticals++;
        }

        if (curLeft == -1)
        {
            curLeft = i;
        }
        else if (curRight == -1)
        {
            curRight = i;
        }

        if (curLeft != -1 && curRight != -1)
        {
            containers.push_back(new Container(curLeft, curRight, std::min(heights[curLeft], heights[curRight]) * (curRight - curLeft)));
            curLeft = -1;
            curRight = -1;
        }
    }

    if (numVerticals < 2)
    {
        // there wasn't a single container
        return new Container(-1, -1, 0);
    }

    int curMaxIndex = 0;
    for (int i = 0; i < containers.size(); i++)
    {
        if (containers[i]->area > containers[curMaxIndex]->area)
        {
            curMaxIndex = i;
        }
    }

    return containers[curMaxIndex];
}

Container* ContainerWithMostWater::MaxAreaTwo(std::vector<int>& heights)
{
    int left = 0;
    int right = static_cast<int>(heights.size()) - 1;

    int maxArea = 0;
    int maxLeft = -1;
    int maxRight = -1;

    while(left < right)
    {
        int curArea = std::min(heights[left], heights[right]) * (right - left);

        if (curArea > maxArea)
        {
            maxArea = curArea;
            maxLeft = left;
            maxRight = right;
        }

        bool isLeftShorter = heights[left] < heights[right];
        if (isLeftShorter)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return new Container(maxLeft, maxRight, maxArea);
}

Container::Container(int left, int right, int area)
{
    this->left = left;
    this->right = right;
    this->area = area;
}