#include "Matrix.h"
#include <stack>

std::vector<std::vector<int>> Matrix::paint(std::vector<std::vector<int>> image, int row, int col, int newColor) {
	if (image[row][col] == newColor) return image;
	
	struct Vertex {
		int row;
		int col;
		Vertex(int _row, int _col) : row(_row), col(_col) {}
	};
	std::stack<Vertex> vertexesStack;
	vertexesStack.push(Vertex(row, col));

	while (!vertexesStack.empty()) {
		int row = vertexesStack.top().row;
		int col = vertexesStack.top().col;
		vertexesStack.pop();
		
		if (image[row][col] != newColor) {
			image[row][col] = newColor;
			
			if (row - 1 >= 0 && image[row - 1][col] != newColor)
				vertexesStack.push(Vertex(row - 1, col));

			if (col - 1 >= 0 && image[row][col - 1] != newColor)
				vertexesStack.push(Vertex(row, col - 1));

			if (row + 1 < image.size() && image[row + 1][col] != newColor)
				vertexesStack.push(Vertex(row + 1, col));

			if (col + 1 < image.size() && image[row][col + 1] != newColor)
				vertexesStack.push(Vertex(row, col + 1));
		}
	}
	return image;
}

int Matrix::numIslands(const std::vector<std::vector<char>>& grid)
{
	int counter{};
	auto sizeRow = grid.size();
	auto sizeCol = grid[0].size();
	std::vector<std::vector<bool>> passedVertexes(sizeRow, std::vector<bool> (sizeCol, false));
	
	auto checkVertex = [&](int row, int col) {
		if (grid[row][col] == '0') return;

		++counter;
		struct Vertex {
			int row;
			int col;
			Vertex(int _row, int _col) : row(_row), col(_col) {}
		};
		std::stack<Vertex> vertexesStack;
		vertexesStack.push(Vertex(row, col));

		while (!vertexesStack.empty()) {
			int row = vertexesStack.top().row;
			int col = vertexesStack.top().col;
			vertexesStack.pop();

			if (grid[row][col] == '1') {

				auto passVertex = [&](int row, int col) {
					passedVertexes[row][col] = true;
					if (grid[row][col] == '1')
						vertexesStack.push(Vertex(row, col));
				};

				if (col + 1 < sizeCol && !passedVertexes[row][col + 1])
						passVertex(row, col + 1);

				if (row + 1 < sizeRow && !passedVertexes[row + 1][col])
						passVertex(row + 1, col);
			}
		}
	};

	for (int row{}; row < sizeRow; ++row)
		for (int col{}; col < sizeCol; ++col)
			if (!passedVertexes[row][col]) {
				passedVertexes[row][col] = true;
				checkVertex(row, col);
			}

	return counter;
}
