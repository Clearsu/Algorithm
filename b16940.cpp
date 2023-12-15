#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[100001];
queue<int> order;
int bfsOrder[100001];
bool visited[100001] = {false, };

bool compare(int a, int b) {
	if (bfsOrder[a] < bfsOrder[b]) {
		return true;
	}
	return false;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;

	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		order.push(temp);
		bfsOrder[temp] = i;
	}

	if (order.front() != 1) {
		cout << "0\n";
		return 0;
	}
	 
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end(), compare);
	}

	queue<int> queue;

	queue.push(1);
	order.pop();
	visited[1] = true;

	while (!queue.empty()) {
		vector<int>& currNode = graph[queue.front()];
		queue.pop();
		int size = currNode.size();
		for (int i = 0; i < size; i++) {
			bool& isVisit = visited[currNode[i]];
			if (isVisit) {
				continue ;
			}
			if (currNode[i] == order.front()) {
				isVisit = true;
				queue.push(order.front());
				order.pop();
			} else {
				cout << "0\n";
				return 0;
			}
		}
	}

	cout << "1\n";

	return 0;
}
