#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

struct Grid {
	int y;
	int x;
	int isBreak;
	Grid(int initY, int initX, bool initIsBreak)
		: y(initY), x(initX), isBreak(initIsBreak) {}
};


int n, m;
char map[1000][1000];
int distMap[1000][1000][2] = {};
std::queue<Grid> queue;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs(void) {
	queue.push(Grid(0, 0, 0));
	distMap[0][0][0] = 1;

	while (!queue.empty()) {
		Grid curr = queue.front();
		queue.pop();
		for (int i = 0; i < 4; i++) {
			int newY = curr.y + dy[i];
			int newX = curr.x + dx[i];
			if (newY >= n || newY < 0 || newX >= m || newX < 0) {
				continue ;
			}
			if (map[newY][newX] == '0' && distMap[newY][newX][curr.isBreak] == 0) {
				distMap[newY][newX][curr.isBreak] = distMap[curr.y][curr.x][curr.isBreak] + 1;
				queue.push(Grid(newY, newX, curr.isBreak));
				continue ;
			}
			if (map[newY][newX] == '1' && curr.isBreak == 0
				&& distMap[newY][newX][1] == 0) {
				distMap[newY][newX][1] = distMap[curr.y][curr.x][0] + 1;
				queue.push(Grid(newY, newX, 1));
			}
		}
	}
}

int main() {
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(0);

	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> map[i][j];
		}
	}

	bfs();

	int withoutBreakRes = distMap[n - 1][m - 1][0];
	int withBreakRes = distMap[n - 1][m - 1][1];

	if (withoutBreakRes == 0 && withBreakRes == 0) {
		std::cout << "-1\n";
	} else if (withoutBreakRes == 0) {
		std::cout << withBreakRes << '\n';
	} else if (withBreakRes == 0) {
		std::cout << withoutBreakRes << '\n';
	} else {
		std::cout << std::min(withoutBreakRes, withBreakRes) << '\n';
	}

	return 0;
}