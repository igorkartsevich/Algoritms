#include "Matrix.h"

void painting(std::vector<std::vector<int>>& paintImage, int row, int col, int newColor) {
	if (paintImage[row][col] == newColor) return;

	paintImage[row][col] = newColor;

	if (row + 1 < paintImage.size())
		painting(paintImage, row + 1, col, newColor);
	if (col - 1 >= 0)
		painting(paintImage, row, col - 1, newColor);
}

std::vector<std::vector<int>> Matrix::paint(const std::vector<std::vector<int>> image, int row, int col, int newColor) {
	std::vector<std::vector<int>> paintImage(image);
	painting(paintImage, row, col, newColor);
	return paintImage;
}

//*******************************************************************

void checkIsland(const std::vector<std::vector<char>>& grid, std::vector<std::vector<bool>>& passedNodes, int row, int col) {
	if (grid[row][col] == '0' || passedNodes[row][col]) return;

	passedNodes[row][col] = true;

	if (row + 1 < grid.size())
		checkIsland(grid, passedNodes, row + 1, col);
	if (row - 1 >= 0)
		checkIsland(grid, passedNodes, row - 1, col);
	if (col + 1 < grid[0].size())
		checkIsland(grid, passedNodes, row, col + 1);
	if (col - 1 >= 0)
		checkIsland(grid, passedNodes, row, col - 1);
}

int Matrix::numIslands(const std::vector<std::vector<char>>& grid) {
	int counter{};
	std::vector<std::vector<bool>> passedNodes(grid.size(), std::vector<bool>(grid[0].size(), false));

	for (int row{}; row < grid.size(); ++row) {
		for (int col{}; col < grid[0].size(); ++col) {
			if (grid[row][col] == '1' && !passedNodes[row][col]) {
				++counter;
				checkIsland(grid, passedNodes, row, col);
			}
		}
	}

	return counter;
}
