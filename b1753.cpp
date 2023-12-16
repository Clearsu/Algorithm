#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

vector<pair<int, int> > nodes[20001];
int minDistance[20001];

void dijkstra(int start) {
	priority_queue<pair<int, int>, \
		vector<pair<int, int> >, \
		greater<pair<int, int> > > pqueue;

	minDistance[start] = 0;
	pqueue.push(pair<int, int>(0, start));
	
	int curr, next, size, currDist, nextDist;
	while (!pqueue.empty()) {
		curr = pqueue.top().second;
		currDist = pqueue.top().first;
		pqueue.pop();
		if (currDist > minDistance[curr]) {
			continue ;
		}
		size = nodes[curr].size();
		for (int i = 0; i < size; i++) {
			next = nodes[curr][i].second;
			nextDist = nodes[curr][i].first + currDist;
			if (nextDist < minDistance[next]) {
				minDistance[next] = nextDist;
				pqueue.push(pair<int, int>(nextDist, next));
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int v, e, k;
	cin >> v >> e >> k;

	for (int i = 0; i <= v; i++) {
		minDistance[i] = INT_MAX;
	}

	int a, b, w;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> w;
		nodes[a].push_back(make_pair(w, b));
	}

	dijkstra(k);

	for (int i = 1; i <= v; i++) {
		if (minDistance[i] == INT_MAX) {
			cout << "INF\n";
		} else {
			cout << minDistance[i] << '\n';
		}
	}

	return 0;
}