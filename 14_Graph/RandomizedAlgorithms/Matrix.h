#pragma once
#include <vector>

class Matrix {
public:
    static std::vector<std::vector<int>> paint(std::vector<std::vector<int>> image, int row, int col, int newColor); //...(const std::vector<std::vector<int>>& image, int row, int col, int newColor)

    static int numIslands(const std::vector<std::vector<char>>& grid);
};