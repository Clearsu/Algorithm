#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

void bfs(char map[25][25], int x, int y, int n, vector<int>& numHouses) {
	const static int dx[4] = {0, 0, 1, -1};
	const static int dy[4] = {1, -1, 0, 0};
	queue<pair<int, int> > queue;

	queue.push(pair<int, int>(y, x));
	map[y][x] = '0';

	int currX, currY, nextX, nextY, count = 1;
	while (!queue.empty()) {
		const pair<int, int>& curr = queue.front();
		currX = curr.second;
		currY = curr.first;
		queue.pop();
		for (int i = 0; i < 4; i++) {
			nextX = currX + dx[i];
			nextY = currY + dy[i];
			if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n
				|| map[nextY][nextX] == '0') {
				continue ;
			}
			count++;
			map[nextY][nextX] = '0';
			queue.push(pair<int, int>(nextY, nextX));
		}
	}
	numHouses.push_back(count);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	char map[25][25];

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	vector<int> numHouses;

	for(int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == '1') {
				bfs(map, j, i, n, numHouses);
			}
		}
	}

	sort(numHouses.begin(), numHouses.end());
	int size = numHouses.size();
	cout << size << '\n';
	for (int i = 0; i < size; i++) {
		cout << numHouses[i] << '\n';
	}

	return 0;
}