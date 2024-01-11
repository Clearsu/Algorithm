#include <iostream>

int r, c;
char map[20][20];
bool visited[26] = {false, };
int maxDist = 0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int y, int x, int dist) {
	visited[map[y][x] - 'A'] = true;
	if (dist > maxDist) {
		maxDist = dist;
	}
	int nextX, nextY;
	for (int i = 0; i < 4; i++) {
		nextX = x + dx[i];
		nextY = y + dy[i];
		if (nextX < 0 || nextY < 0 || nextX >= c || nextY >= r
			|| visited[map[nextY][nextX] - 'A']) {
			continue ;
		}
		dfs(nextY, nextX, dist + 1);
	}
	visited[map[y][x] - 'A'] = false;
}

int main() {
	std::cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			std::cin >> map[i][j];
		}
	}
	
	dfs(0, 0, 1);

	std::cout << maxDist << '\n';
}