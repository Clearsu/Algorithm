#include <iostream>
#include <map>
#include <deque>
#include <queue>
#include <vector>

using namespace std;

vector<int> stations[3001];
bool finish = false;
deque<int> path;
bool visited[3001] = {false, };
int dist[3001];

void dfs(int prev, int curr) {
	int next;

	if (finish) {
		return ;
	}
	if (visited[curr]) {
		while (path.front() != curr) {
			path.pop_front();
		}
		for (int i = 0; i < path.size(); i++) {
			dist[path[i]] = 0;
		}
		finish = true;
		return ;
	}
	visited[curr] = true;
	path.push_back(curr);
	for (int i = 0; i < stations[curr].size(); i++) {
		next = stations[curr][i];
		if (next == prev) {
			continue ;
		}
		dfs(curr, next);
	}
	path.pop_back();
}

void bfs(int start) {
	queue<int> queue;
	int curr;

	queue.push(start);
	while (!queue.empty()) {
		curr = queue.front();
		queue.pop();
		for (int i = 0; i < stations[curr].size(); i++) {
			if (dist[stations[curr][i]] >= 0) {
				continue ;
			}
			dist[stations[curr][i]] = dist[curr] + 1;
			queue.push(stations[curr][i]);
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;

	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		stations[a].push_back(b);
		stations[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		dist[i] = -1;
	}

	dfs(0, 1);

	for (int i = 1; i <= n; i++) {
		if (dist[i] == 0 && stations[i].size() > 2) {
			bfs(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << dist[i] << ' ';
	}
	cout << '\n';

	return 0;
}