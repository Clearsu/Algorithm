#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int, int> > tree[100001];
bool visited[100001] = {false, };

void initTree(int n) {
	int src, dest, dist;
	for (int i = 1; i <= n; i++) {
		cin >> src >> dest >> dist;
		vector<pair<int, int> >& node = tree[src];
		node.push_back(pair<int, int>(dest, dist));
		while (true) {
			cin >> dest;
			if (dest == -1) {
				break ;
			}
			cin >> dist;
			node.push_back(pair<int, int>(dest, dist));
		}
	}
}

void findMostFarVertex(int node, int distSum, int& maxDist, int& farNode) {
	visited[node] = true;
	if (distSum > maxDist) {
		maxDist = distSum;
		farNode = node;
	}
	int size = tree[node].size();
	for (int i = 0; i < size; i++) {
		const pair<int, int>& next = tree[node][i];
		if (!visited[next.first]) {
			findMostFarVertex(next.first, distSum + next.second, maxDist, farNode);
		}
	}
}

void getTreeSpan(int node, int distSum, int& maxDist) {
	visited[node] = true;
	if (distSum > maxDist) {
		maxDist = distSum;
	}
	int size = tree[node].size();
	for (int i = 0; i < size; i++) {
		const pair<int, int>& next = tree[node][i];
		if (!visited[next.first]) {
			getTreeSpan(next.first, distSum + next.second, maxDist);
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;

	initTree(n);

	int farNode;
	int maxDist = 0;

	findMostFarVertex(1, 0, maxDist, farNode);

	for (int i = 1; i <= n; i++) {
		visited[i] = false;
	}

	maxDist = 0;
	getTreeSpan(farNode, 0, maxDist);

	cout << maxDist << '\n';
	
	return 0;
}