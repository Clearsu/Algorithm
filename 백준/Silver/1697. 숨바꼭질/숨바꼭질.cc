#include <iostream>
#include <queue>
using namespace std;

int t[100001];

void bfs(int n, int k) {
	queue<int> q;

	t[n] = 0;
	q.push(n);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		
		if (curr + 1 <= 100000 && t[curr] + 1 < t[curr + 1]) {
			t[curr + 1] = t[curr] + 1;
			q.push(curr + 1);
		}
		if (curr - 1 >= 0 && t[curr] + 1 < t[curr - 1]) {
			t[curr - 1] = t[curr] + 1;
			q.push(curr - 1);
		}
		if (curr * 2 <= 100000 && t[curr] + 1 < t[curr * 2]) {
			t[curr * 2] = t[curr] + 1;
			q.push(curr * 2);
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i <= 100001; i++) {
		t[i] = 2147483647;
	}

	bfs(n, k);

	cout << t[k] << '\n';

	return 0;
}