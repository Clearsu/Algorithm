#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int findParent(vector<int>& parent, int child) {
	if (child == parent[child]) {
		return child;
	}
	parent[child] = findParent(parent, parent[child]);
	return parent[child];
}

int unionParent(vector<int>& parent, int child1, int child2, vector<int>& familyCount) {
	child1 = findParent(parent, child1);
	child2 = findParent(parent, child2);
	if (child1 != child2) {
		if (child2 < child1) {
			swap(child1, child2);
		}
		parent[child2] = child1;
		familyCount[child1] += familyCount[child2];
	}
	return familyCount[child1];
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		int f;
		cin >> f;
		cin.ignore();
		unordered_map<string, int> map;
		vector<int> parent(2 * f);
		for (int j = 0; j < 2 * f; j++) {
			parent[j] = j;
		}
		vector<int> familyCount(2 * f, 1);
		int id = 0;
		for (int j = 0; j < f; j++) {
			string a, b;
			cin >> a >> b;
			cin.ignore();
			if (map.find(a) == map.end()) {
				map[a] = id++;
			}
			if (map.find(b) == map.end()) {
				map[b] = id++;
			}
			cout << unionParent(parent, map[a], map[b], familyCount) << '\n';
		}	
	}
	return 0;
}