#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, k;
	cin >> n >> k;

	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > jewels;
	priority_queue<int, vector<int>, greater<int> > bags;
	
	int weight, value;
	for (int i = 0; i < n; i++) {
		cin >> weight >> value;
		jewels.push(pair<int, int>(weight, value));
	}

	int capacity;
	for (int i = 0; i < k; i++) {
		cin >> capacity;
		bags.push(capacity);
	}

	priority_queue<pair<int, int> > pqueue;

	long long maxValue = 0;
	int jewelWeight, currBagCapacity;
	while (!bags.empty()) {
		currBagCapacity = bags.top();
		bags.pop();
		while (!jewels.empty() && jewels.top().first <= currBagCapacity) {
			pqueue.push(pair<int, int>(jewels.top().second, jewels.top().first));
			jewels.pop();
		}
		if (pqueue.empty()) {
			continue ;
		}
		maxValue += pqueue.top().first;
		pqueue.pop();
	}

	cout << maxValue << '\n';

	return 0;
}