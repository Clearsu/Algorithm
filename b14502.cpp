#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int n, m;
char map[8][8] = {0, };
int maxSafeSpace = 0;
int initialSpaceLeft;
queue<pair<int, int> > initialVirusPos;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int getSafeSpace() {
	bool visited[8][8] = {false, };

	queue<pair<int, int> > queue(initialVirusPos);
	int spaceLeft = initialSpaceLeft;
	
	int nextX, nextY;
	while (!queue.empty()) {
		const pair<int, int>& curr = queue.front();
		for (int i = 0; i < 4; i++) {
			nextY = curr.first + dy[i];
			nextX = curr.second + dx[i];
			if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < m
				&& map[nextY][nextX] == '0' && visited[nextY][nextX] == false) {
				visited[nextY][nextX] = true;
				spaceLeft--;
				queue.push(pair<int, int>(nextY, nextX));
			}
		}
		queue.pop();
	}

	return spaceLeft;
}

void setWall(int col, int row, int cnt) {
	if (cnt == 3) {
		int safeSpace = getSafeSpace();
		if (safeSpace > maxSafeSpace) {
			maxSafeSpace = safeSpace;
		}
		return ;
	}
	for (int i = row; i < m; i++) {
		char& space = map[col][i];
		if (space == '0') {
			space = '1';
			setWall(col, i + 1, cnt + 1);
			space = '0';
		}
	}
	if (col < n) {
		setWall(col + 1, 0, cnt);
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> m;
	initialSpaceLeft = n * m - 3;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m ; j++) {
			char& space = map[i][j];
			cin >> space;
			if (space == '0') {
				continue;
			}
			initialSpaceLeft--;
			if (space == '2') {
				initialVirusPos.push(pair<int, int>(i, j));
			}
		}
	}

	setWall(0, 0, 0);

	cout << maxSafeSpace << '\n';
	
	return 0;
}