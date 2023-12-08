#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <deque>
#include <limits>

using namespace std;

int n, m;
int map[50][50];
vector<pair<int, int> > virusPos;
deque<pair<int, int> > virusQueue;
int originEmptyCount;
int minTime = numeric_limits<int>::max();

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs(deque<pair<int, int> > virusQueue) {
	int distMap[50][50] = {0, };
	int currEmptyCount = originEmptyCount;

	deque<pair<int, int> >::iterator it = virusQueue.begin();
	deque<pair<int, int> >::iterator end = virusQueue.end();
	while (it != end) {
		distMap[(*it).first][(*it).second] = 1;
		++it;
	}

	int nextX, nextY;
	while (!virusQueue.empty()) {
		const pair<int, int>& curr = virusQueue.front();
		for (int i = 0; i < 4; i++) {
			nextY = curr.first + dy[i];
			nextX = curr.second + dx[i];
			if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n
				|| map[nextY][nextX] == 1 || distMap[nextY][nextX] > 0) {
				continue ;
			}
			distMap[nextY][nextX] = distMap[curr.first][curr.second] + 1;
			if (map[nextY][nextX] == 0 && --currEmptyCount == 0) {
				break ;
			}
			virusQueue.push_back(make_pair(nextY, nextX));
		}
		if (currEmptyCount == 0) {
			break ;
		}
		virusQueue.pop_front();
	}

	if (currEmptyCount != 0) {
		return ;
	}

	int maxDist = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (distMap[i][j] > maxDist) {
				maxDist = distMap[i][j];
			}
		}
	}

	if (--maxDist < minTime) {
		minTime = maxDist;
	}
}

void bruteForce(int count, vector<pair<int, int> >::iterator currVirusPos) {
	if (count == m) {
		bfs(virusQueue);
		return ;
	}
	for (vector<pair<int, int> >::iterator it = currVirusPos + 1;
		it != virusPos.end(); ++it) {
		virusQueue.push_back(*it);
		bruteForce(count + 1, it);
		virusQueue.pop_back();
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int& temp = map[i][j];
			cin >> temp;
			if (temp == 1) {
				continue ;
			}
			if (temp == 0) {
				originEmptyCount++;
				continue ;
			}
			virusPos.push_back(make_pair(i, j));
		}
	}

	if (originEmptyCount == 0) {
		cout << "0\n";
		return 0;
	}

	for (vector<pair<int, int> >::iterator it = virusPos.begin();
		it != virusPos.end(); ++it) {
		virusQueue.push_back(*it);
		bruteForce(1, it);
		virusQueue.pop_back();
	}

	if (minTime == numeric_limits<int>::max()) {
		cout << "-1\n";
	} else {
		cout << minTime << '\n';
	}

	return 0;
}