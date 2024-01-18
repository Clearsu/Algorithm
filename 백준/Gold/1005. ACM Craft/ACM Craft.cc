#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int d[1001];
int timeSpent[1001];
vector<int> graph[1001];
int enterCount[1001];

void readInput(int n, int k) {
	int building1, building2;

	for (int i = 1; i <= n; i++) {
		cin >> d[i];
		timeSpent[i] = 0;
		graph[i].clear();
		enterCount[i] = 0;
	}
	for (int i = 1; i <= k; i++) {
		cin >> building1 >> building2;
		graph[building1].push_back(building2);
		++enterCount[building2];
	}
}

void topologicalSort(int n) {
	queue<int> queue;
	
	for (int i = 1; i <= n; i++) {
		if (enterCount[i] == 0) {
			queue.push(i);
			timeSpent[i] = d[i];
		}
	}

	int curr, next, size, sortedIdx = 1;
	while (!queue.empty()) {
		curr = queue.front();
		queue.pop();
		size = graph[curr].size();
		for (int i = 0; i < size; i++) {
			next = graph[curr][i];
			--enterCount[next];
			timeSpent[next] = max(timeSpent[next], timeSpent[curr] + d[next]);
			if (enterCount[next] == 0) {
				queue.push(next);
			}
		}
	}
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int t;
	cin >> t;

	int n, k, w;
	for (int i = 0; i < t; i++) {
		cin >> n >> k;
		readInput(n, k);
		topologicalSort(n);
		cin >> w;
		cout << timeSpent[w] << '\n';
	}
}