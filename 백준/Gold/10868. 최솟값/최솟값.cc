#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100000
#define INTMAX 2147483647

int arr[MAX + 1];
int segTree[MAX * 4 + 1];

int initTree(int start, int end, int node) {
	if (start == end) {
		return segTree[node] = arr[start];
	}
	int mid = (start + end) / 2;
	return segTree[node] = min(initTree(start, mid, node * 2), initTree(mid + 1, end, node * 2 + 1));
}

int getMin(int start, int end, int node, int left, int right) {
	if (start > right || end < left) {
		return INTMAX;
	}
	if (left <= start && end <= right) {
		return segTree[node];
	}
	int mid = (start + end) / 2;
	return min(getMin(start, mid, node * 2, left, right), getMin(mid + 1, end, node * 2 + 1, left, right));
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	initTree(1, n, 1);

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << getMin(1, n, 1, a, b) << '\n';
	}
	
	return 0;
}