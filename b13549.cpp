#include <iostream>
#include <queue>

using namespace std;

int minTime[100001];

void bfs(int start) {
	int currPos, currTime;
	queue<pair<int, int> > queue;
	
	queue.push(pair<int, int>(start, 0));
	minTime[start] = 0;
	while (!queue.empty()) {
		currPos = queue.front().first;	
		currTime = queue.front().second;
		queue.pop();
		if (currPos < 100000 && currTime + 1 < minTime[currPos + 1]) {
			minTime[currPos + 1] = currTime + 1;
			queue.push(pair<int, int>(currPos + 1, currTime + 1));
		}
		if (currPos > 0 && currTime + 1 < minTime[currPos - 1]) {
			minTime[currPos - 1] = currTime + 1;
			queue.push(pair<int, int>(currPos - 1, currTime + 1));
		}
		if (currPos * 2 <= 100000 && currTime < minTime[currPos * 2]) {
			minTime[currPos * 2] = currTime;
			queue.push(pair<int, int>(currPos * 2, currTime));
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;

	if (n >= k) {
		cout << n - k << '\n';
		return 0;
	}

	for (int i = 0; i <= 100000; i++) {
		minTime[i] = 100000;
	}

	bfs(n);

	cout << minTime[k] << '\n';

	return 0;
}