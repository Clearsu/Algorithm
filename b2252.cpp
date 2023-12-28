#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[32001];
int enterCount[32001] = {0, };

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		++enterCount[b];
	}

	queue<int> queue;
	for (int i = 1; i <= n; i++) {
		if (enterCount[i] == 0) {
			queue.push(i);
		}
	}

	int curr, size, next;
	while (!queue.empty()) {
		curr = queue.front();
		queue.pop();
		cout << curr << ' ';

		size = graph[curr].size();
		for (int i = 0; i < size; i++) {
			next = graph[curr][i];
			--enterCount[next];
			if (enterCount[next] == 0) {
				queue.push(next);
			}
		}
	}

	cout << '\n';

	return 0;
}