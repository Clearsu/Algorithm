#include <iostream>
#include <queue>
#include <utility>

using namespace std;

void bfs(int n, int map[20][20], pair<int, int>& sharkPos, int& moveDist, int& sharkSize, int& eatCount) {
	queue<pair<int, int> > queue;

	int distMap[20][20] = {0, };
	int edibleFishDist[20][20] = {2147483647, };
	static const int dy[4] = {1, -1, 0, 0};
	static const int dx[4] = {0, 0, 1, -1};

	queue.push(sharkPos);

	int y, x;
	while (!queue.empty()) {
		pair<int, int> curr = queue.front();
		queue.pop();
		for (int i = 0; i < 4; i++) {
			y = curr.first + dy[i];
			x = curr.second + dx[i];
			int& mapVal = map[y][x];
			int& distVal = distMap[y][x];
			if (y < 0 || x < 0 || y >= n || x >= n || distVal > 0 || mapVal > sharkSize) {
				continue ;
			}
			distVal = distMap[curr.first][curr.second] + 1;
			if (mapVal == 0 || mapVal == sharkSize) {
				queue.push(make_pair(y, x));
			} else if (mapVal > 0 && mapVal < sharkSize) {
				edibleFishDist[y][x] = distVal;
			}
		}
	}
	
	int minDist = 2147483647;
	int toEatX, toEatY;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int& dist = edibleFishDist[i][j];
			if (dist > 0 && dist < minDist) {
				minDist = dist;
				toEatY = i;
				toEatX = j;
			}
		}
	}
	if (minDist == 2147483647) {
		return ;
	}

	sharkPos.first = toEatY;
	sharkPos.second = toEatX;
	moveDist += edibleFishDist[toEatY][toEatX];
	map[toEatY][toEatX] = 0;
	eatCount++;
	if (eatCount == sharkSize) {
		sharkSize++;
		eatCount = 0;
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int map[20][20];
	int n;
	pair<int, int> sharkPos;
	int sharkSize = 2;
	int moveDist = 0;
	int eatCount = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int& temp = map[i][j];
			cin >> temp;
			if (temp == 9) {
				sharkPos.first = i;
				sharkPos.second = j;
				temp = 0;
			}
		}
	}

	int prevEatCount;
	while (true) {
		prevEatCount = eatCount;
		bfs(n, map, sharkPos, moveDist, sharkSize, eatCount);
		if (prevEatCount == eatCount) {
			break ;
		}
	}

	cout << moveDist << '\n';

	return 0;
}