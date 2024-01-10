#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
long long tree[4000001], lazy[4000001] = {0, };
long long initialValues[1000001];

long long init(int start, int end, int node) {
	if (start == end) {
		tree[node] = initialValues[start];
		return tree[node];
	}
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

void update_lazy(int start, int end, int node) {
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_range(int start, int end, int node, int left, int right, long long diff) {
    update_lazy(start, end, node);
    if (left > end || right < start) {
		return;
	}
    if (left <= start && end <= right) {
		lazy[node] = diff;
		update_lazy(start, end, node);
        return;
    }
    int mid = (start + end) / 2;
    update_range(start, mid, node * 2, left, right, diff);
    update_range(mid + 1, end, node * 2 + 1, left, right, diff);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long sum(int start, int end, int node, int left, int right) {
    update_lazy(start, end, node);
    if (left > end || right < start) {
		return 0;
	}
    if (left <= start && end <= right) {
		return tree[node];
	}
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> initialValues[i];
    }

	init(1, n, 1);

    for (int i = 0; i < m + k; i++) {
        int operation, idx1, idx2;
		long long diff;
        cin >> operation;
        if (operation == 1) {
            cin >> idx1 >> idx2 >> diff;
            update_range(1, n, 1, idx1, idx2, diff);
        } else {
            cin >> idx1 >> idx2;
            cout << sum(1, n, 1, idx1, idx2) << '\n';
        }
    }

    return 0;
}
