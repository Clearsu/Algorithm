#include <iostream>
#include <queue>
#include <utility>

int m, n;
short grid[1000][1000];
const short dx[4] = {0, 0, 1, -1};
const short dy[4] = {1, -1, 0, 0};
int cnt = 0;

void bfs(std::queue<std::pair<int, int> >& queueFirst,
			std::queue<std::pair<int, int> >& queueSecond) {
	if (queueFirst.empty()) {
		return ;
	}
	while (!queueFirst.empty()) {
		const std::pair<int, int>& temp = queueFirst.front();
		for (int i = 0; i < 4; i++) {
			const int& y = temp.first + dy[i];
			const int& x = temp.second + dx[i];
			if (y >= 0 && y < n && x >= 0 && x < m && grid[y][x] == 0) {
				grid[y][x] = 1;
				queueSecond.push(std::pair<int, int>(y, x));
			}
		}
		queueFirst.pop();
	}
	if (!queueSecond.empty()) {
		cnt++;
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	std::queue<std::pair<int, int> > queue1;
	std::queue<std::pair<int, int> > queue2;

	std::cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> grid[i][j];
			if (grid[i][j] == 1) {
				queue1.push(std::pair<int, int>(i, j));
			}
		}
	}

	while (!(queue1.empty() && queue2.empty())) {
		bfs(queue1, queue2);
		bfs(queue2, queue1);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 0) {
				std::cout << "-1\n";
				return 0;
			}
		}
	}

	std::cout << cnt << '\n';

	return 0;
}