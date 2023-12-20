#include <iostream>
#include <queue>
#include <map>

using namespace std;

int n;
map<int, bool> tree[100001];
queue<int> toVisit;

void readInput() {
	cin >> n;

	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		tree[a][b] = true;
		tree[b][a] = true;
	}

	int temp;
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		toVisit.push(temp);
	}
}

void dfs(int curr) {
	int next;

	while (!toVisit.empty() && tree[curr][toVisit.front()]) {
		next = toVisit.front();
		toVisit.pop();
		dfs(next);
	}
}

void printAnswer() {
	if (!toVisit.empty()) {
		cout << "0\n";
		return ;
	}
	cout << "1\n";
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	readInput();

	toVisit.pop();
	dfs(1);
	printAnswer();

	return 0;
}