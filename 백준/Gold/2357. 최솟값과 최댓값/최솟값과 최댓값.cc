#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

#define MAX 100000

int n, m;
pair<int, int> segTree[MAX * 4 + 1];
int arr[MAX + 1];

const pair<int, int>& initTree(int left, int right, int node) {
	if (left == right) {
		segTree[node].first = arr[left];
		segTree[node].second = arr[left];
		return segTree[node];
	}
	int mid = (left + right) / 2;
	const pair<int, int>& a = initTree(left, mid, node * 2);
	const pair<int, int>& b = initTree(mid + 1, right, node * 2 + 1);

	segTree[node].first = min(a.first, b.first);
	segTree[node].second = max(a.second, b.second);
	return segTree[node];
}

pair<int, int> getMinMax(int start, int end, int node, int left, int right) {
	if (start > right || end < left) {
		return pair<int, int>(2147483647, 0);
	}
	if (left <= start && end <= right) {
		return segTree[node];
	}
	int mid = (start + end) / 2;
	pair<int, int> res;
	pair<int, int> a = getMinMax(start, mid, node * 2, left, right);
	pair<int, int> b = getMinMax(mid + 1, end, node * 2 + 1, left, right);
	res.first = min(a.first, b.first);
	res.second = max(a.second, b.second);
	return res;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	initTree(1, n, 1);

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		pair<int, int> res = getMinMax(1, n, 1, a, b);
		cout << res.first << ' ' << res.second << '\n';
	}

	return 0;
}