#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

bool graph[1001][1001] = {false, };
bool visited[1001] = {false, };
int n, m ,v;

void dfs(int v) {
	cout << v << ' ';
	for (int i = 1; i <= n; i++) {
		if (graph[v][i] == true && visited[i] == false) {
			visited[i] = true;
			dfs(i);
		}
	}
}

void bfs(int v) {
	queue<int> queue;
	queue.push(v);

	memset(visited, false, n + 1);
	visited[v] = true;

	int toVisit;
	while (!queue.empty()) {
		toVisit = queue.front();
		queue.pop();
		cout << toVisit << ' ';
		for (int i = 1; i <= n; i++) {
			if (graph[toVisit][i] == true && visited[i] == false) {
				visited[i] = true;
				queue.push(i);
			}
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> m >> v;

	int p1, p2;
	for (int i = 0; i < m; i++) {
		cin >> p1 >> p2;
		graph[p1][p2] = true;
		graph[p2][p1] = true;
	}

	visited[v] = true;
	dfs(v);
	cout << '\n';
	bfs(v);
	cout << '\n';
	return 0;
}