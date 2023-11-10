#include <iostream>
#include <queue>
#include <utility>

int main() {
	char map[1000][1000];
	int dist[1000][1000];
	
	int n, m;
	std::cin >> n >> m;
	std::cin.ignore();

	std::queue<std::pair<int , int> > queue;


	char temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> temp;
			if (temp == '2') {
				queue.push(std::pair<int, int>(i, j));
				dist[i][j] = 0; // 시작 위치 초기화
			} else if (temp == '0') {
				dist[i][j] = 0;
			} else {
				dist[i][j] = -1;
			}
			map[i][j] = temp;
		}
		std::cin.ignore();
	}

	const short dx[4] = {0, 0, 1, -1};
	const short dy[4] = {1, -1, 0, 0};

	while (!queue.empty()) {
		const std::pair<int, int>& coord = queue.front();
		queue.pop();
		for (int i = 0; i < 4; i++) {
			const int tempY = coord.first + dy[i];
			const int tempX = coord.second + dx[i];
			if (tempY >= 0 && tempY < n && tempX >= 0 && tempX < m) {
				if (map[tempY][tempX] == '1' && dist[tempY][tempX] == -1) { // not visited yet
					queue.push(std::pair<int, int>(tempY, tempX));
					dist[tempY][tempX] = dist[coord.first][coord.second] + 1;
				}
			}
		}	
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << dist[i][j] << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}