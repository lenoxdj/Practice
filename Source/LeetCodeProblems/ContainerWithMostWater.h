#pragma once

// #11
namespace LeetCodeProblems
{
    struct Container
    {
        Container(int left, int right, int area);

        int left;
        int right;
        int area;
    };

    ref class ContainerWithMostWater abstract sealed
    {
    public:
        static Container* MaxArea(std::vector<int>& heights);
        static Container* MaxAreaTwo(std::vector<int>& heights);
    };
}
