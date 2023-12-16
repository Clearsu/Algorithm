#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

vector<pair<int, int> > nodes[1001];
int minCost[1001];

void dijkstra(int start) {
	priority_queue<pair<int, int>, \
		vector<pair<int, int> >, \
		greater<pair<int, int> > > pqueue;
	
	minCost[start] = 0;
	pqueue.push(pair<int, int>(0, start));

	int curr, next, currCost, nextCost, size;
	while (!pqueue.empty()) {
		curr = pqueue.top().second;
		currCost = pqueue.top().first;
		pqueue.pop();
		size = nodes[curr].size();
		if (currCost > minCost[curr]) {
			continue ;
		}
		for (int i = 0; i < size; i++) {
			next = nodes[curr][i].second;
			nextCost = nodes[curr][i].first + currCost;
			if (nextCost < minCost[next]) {
				minCost[next] = nextCost;
				pqueue.push(pair<int, int>(nextCost, next));
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		minCost[i] = INT_MAX;
	}

	int cityA, cityB, cost;
	for (int i = 0; i < m; i++) {
		cin >> cityA >> cityB >> cost;
		nodes[cityA].push_back(pair<int, int>(cost, cityB));
	}

	int start, end;
	cin >> start >> end;

	dijkstra(start);

	cout << minCost[end] << '\n';

	return 0;
}