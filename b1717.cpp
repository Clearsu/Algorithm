#include <iostream>
#include <vector>

using namespace std;

int findParent(vector<int>& parent, int x) {
	if (x == parent[x]) {
		return x;
	}
	parent[x] = findParent(parent, parent[x]);
	return parent[x];
}

void unite(vector<int>& parent, int a, int b) {
	a = findParent(parent, a);
	b = findParent(parent, b);
	if (a != b) {
		if (a > b) {
			swap(a, b);
		}
		parent[b] = a;
	}
}

bool isSameParent(vector<int>& parent, int a, int b) {
	if (findParent(parent, a) == findParent(parent, b)) {
		return true;
	}
	return false;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n, m;
	cin >> n >> m;

	vector<int> parent(n + 1);
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	int action, a, b;

	for (int i = 0; i < m; i++) {
		cin >> action >> a >> b;
		if (action == 0) {
			unite(parent, a, b);
		} else {
			if (a == b || isSameParent(parent, a, b)) {
				cout << "yes\n";
			} else {
				cout << "no\n";
			}
		}
	}

	return 0;
}