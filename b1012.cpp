#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

void bfs(int field[50][50], queue<pair<int, int> >& queue, \
			int n, int m, int dx[4], int dy[4], int id) {
	int nextY, nextX;

	while (!queue.empty()) {
		pair<int, int>& curr = queue.front();
		for (int i = 0; i < 4; i++) {
			nextY = curr.first + dy[i];
			nextX = curr.second + dx[i];
			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m
				|| field[nextY][nextX] != 1) {
				continue ;
			}
			field[nextY][nextX] = id;
			queue.push(pair<int, int>(nextY, nextX));
		}	
		queue.pop();
	}
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int field[50][50];
	queue<pair<int, int> > queue;
	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0, 0};
	int t, m, n, k;
	int x, y;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> m >> n >> k;
		for (int j = 0; j < n; j++) {
			memset(field[j], 0, m * sizeof(int));
		}
		for (int j = 0; j < k; j++) {
			cin >> x >> y;
			field[y][x] = 1;
		}
		int id = 1;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				if (field[y][x] == 1) {
					queue.push(pair<int, int>(y, x));
					field[y][x] = ++id;
					bfs(field, queue, n, m, dx, dy, id);
				}
			}
		}
		cout << --id << '\n';
	}
	return 0;
}