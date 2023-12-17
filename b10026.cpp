#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int n;
char normalMap[100][100];
char colorWeaknessMap[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs(char map[100][100]) {
	int count = 0;
	int c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j]) {
				c = map[i][j];
				count++;
				queue<pair<int, int> > queue;
				queue.push(pair<int, int>(i, j));
				map[i][j] = 0;

				int currY, currX, nextY, nextX;
				while (!queue.empty()) {
					currY = queue.front().first;
					currX = queue.front().second;
					queue.pop();
					for (int i = 0; i < 4; i++) {
						nextY = currY + dy[i];
						nextX = currX + dx[i];
						if (nextY >= 0 && nextX >= 0 && nextY < n && nextX < n
							&& map[nextY][nextX] == c) {
							map[nextY][nextX] = 0;
							queue.push(pair<int, int>(nextY, nextX));
						}
					}
				}
			}
		}
	}

	return count;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> normalMap[i][j];
			if (normalMap[i][j] == 'G') {
				colorWeaknessMap[i][j] = 'R';
			} else {
				colorWeaknessMap[i][j] = normalMap[i][j];
			}
		}
	}

	cout << bfs(normalMap) << ' ' << bfs(colorWeaknessMap) << '\n';

	return 0;
}