#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int bags[300000];
pair<int, int> jewels[300000];

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> jewels[i].first >> jewels[i].second;
	}
	sort(jewels, jewels + n);

	for (int i = 0; i < k; i++) {
		cin >> bags[i];
	}
	sort(bags, bags + k);

	priority_queue<int> jewelsToSteal;

	int jewelIdx = 0;
	long long maxValue = 0;

	for (int i = 0; i < k; i++) {
		while (jewelIdx < n && jewels[jewelIdx].first <= bags[i]) {
			jewelsToSteal.push(jewels[jewelIdx++].second);
		}
		if (!jewelsToSteal.empty()) {
			maxValue += jewelsToSteal.top();
			jewelsToSteal.pop();
		}
	}

	cout << maxValue << '\n';

	return 0;
}