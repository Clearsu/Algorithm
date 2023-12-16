#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<long long, long long> > nodes[801];
long long minDist[801];

long long dijkstra(long long start, long long end, long long n) {
	for (long long i = 1; i <= n; i++) {
		minDist[i] = INT_MAX;
	}

	priority_queue<pair<long long, long long>, \
		vector<pair<long long, long long> >, \
		greater<pair<long long, long long> > > pqueue;

	minDist[start] = 0;
	pqueue.push(pair<long long, long long>(0, start));

	long long curr, currDist, next, nextDist, size;
	while (!pqueue.empty()) {
		curr = pqueue.top().second;
		currDist = pqueue.top().first;
		pqueue.pop();
		if (currDist > minDist[curr]) {
			continue ;
		}
		size = nodes[curr].size();
		for (long long i = 0; i < size; i++) {
			next = nodes[curr][i].second;
			nextDist = nodes[curr][i].first + currDist;
			if (nextDist < minDist[next]) {
				minDist[next] = nextDist;
				pqueue.push(pair<long long, long long>(nextDist, next));
			}
		}
	}

	return minDist[end];
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	long long n, e;
	cin >> n >> e;

	long long a, b, cost;
	for (long long i = 0; i < e; i++) {
		cin >> a >> b >> cost;
		nodes[a].push_back(pair<long long, long long>(cost, b));
		nodes[b].push_back(pair<long long, long long>(cost, a));
	}

	long long must1, must2;
	cin >> must1 >> must2;

	unsigned long long ans1 = dijkstra(1, must1, n) \
		+ dijkstra(must1, must2, n) + dijkstra(must2, n, n);
	unsigned long long ans2 = dijkstra(1, must2, n) \
		+ dijkstra(must2, must1, n) + dijkstra(must1, n, n);

	if (ans1 >= INT_MAX && ans2 >= INT_MAX) {
		cout << "-1\n";
		return 0;
	}

	cout << min(ans1, ans2) << '\n';
}