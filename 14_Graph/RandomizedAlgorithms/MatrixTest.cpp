#include "Matrix.h"
#include <cassert>
#include <iostream>


void printTest(const std::vector<std::vector<int>>& image, int row, int col, int newColor, const std::vector<std::vector<int>>& targetImage)
{
    //std::cout << "Print a matrix";
    auto actual = Matrix::paint(image, row, col, newColor);
    auto expected = targetImage;
    
    assert(actual.size() == expected.size());
    for (size_t i = 0; i < actual.size(); ++i){
        assert(actual[i].size() == expected[i].size());
        for (size_t j = 0; j < actual[i].size(); ++j){
            assert(actual[i][j] == expected[i][j]);
        }
    }
}

void numIslandsTest(const std::vector<std::vector<char>>& grid, int islands)
{
    //std::cout << "Find count of Islands";
    auto actual = Matrix::numIslands(grid);
    auto expected = islands;

    assert(actual == expected);
}

int main(){
    printTest({{0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}}, 0, 1, 1, 
              {{1, 1, 1, 0}, {1, 1, 1, 0}, {1, 1, 1, 0}, {1, 1, 1, 0}});
    printTest({{0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}}, 0, 3, 1,
              {{0, 0, 1, 1}, {0, 0, 1, 1}, {0, 0, 1, 1}, {0, 0, 1, 1}});

    numIslandsTest({
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}}, 1);
    numIslandsTest({
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}}, 3);
    return 0;
}