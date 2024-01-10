#include <iostream>

using namespace std;

#define MAX 1000000

long long arr[MAX + 1];
long long tree[MAX * 4 + 1];

long long initTree(int left, int right, int node) {
	if (left == right) {
		return tree[node] = arr[left];
	}
	int mid = (left + right) / 2;
	return tree[node] = initTree(left, mid, node * 2) \
					+ initTree(mid + 1, right, node * 2 + 1);
}

long long getSum(int start, int end, int node, int left, int right) {
	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	return getSum(start, mid, node * 2, left, right) \
		+ getSum(mid + 1, end, node * 2 + 1, left, right);
}

long long update(int left, int right, int node, int idx, long long value) {
	if (idx < left || idx > right) {
		return 0;
	}
	if (left == right) {
		long long diff = value - tree[node];
		tree[node] = value;
		return diff;
	}
	int mid = (left + right) / 2;
	long long diff = update(left, mid, node * 2, idx, value) \
			+ update(mid + 1, right, node * 2 + 1, idx, value);
	tree[node] += diff;
	return diff;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	initTree(1, n, 1);

	long long a, b, c;
	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, n, 1, b, c);
		} else {
			cout << getSum(1, n, 1, b, c) << '\n';
		}
	}
	
	return 0;
}