#include <iostream>
#include <queue>
#include <utility>


void bfs(int maze[100][100], int n, int m) {
	std::queue<std::pair<int, int> > toVisit;
	std::pair<int, int> coord;

	// initial coordination
	coord.first = 0;
	coord.second = 0;
	toVisit.push(coord);
	
	int row, col, currVal;
	while (!toVisit.empty()) {
		row = toVisit.front().first;
		col = toVisit.front().second;
		toVisit.pop();

		currVal = maze[row][col];
		if (row + 1 < n && maze[row + 1][col] == 1) {
			coord.first = row + 1;
			coord.second = col;
			maze[row + 1][col] = currVal + 1;
			toVisit.push(coord);
		}
		if (row - 1 >= 0 && maze[row - 1][col] == 1) {
			coord.first = row - 1;
			coord.second = col;
			maze[row - 1][col] = currVal + 1;
			toVisit.push(coord);
		}
		if (col + 1 < m && maze[row][col + 1] == 1) {
			coord.first = row;
			coord.second = col + 1;
			maze[row][col + 1] = currVal + 1;
			toVisit.push(coord);
		}
		if (col - 1 >= 0 && maze[row][col - 1] == 1) {
			coord.first = row;
			coord.second = col - 1;
			maze[row][col - 1] = currVal + 1;
			toVisit.push(coord);
		}
	}
}

int main() {
	int n, m;
	std::cin >> n >> m;
	std::cin.ignore();
	int maze[100][100];

	char temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> temp;
			maze[i][j] = static_cast<int>(temp - '0');
		}
		std::cin.ignore();
	}

	bfs(maze, n, m);

	std::cout << maze[n - 1][m - 1] << '\n';

	return 0;
}