#include <queue>
#include <iostream>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);

	ios_base::sync_with_stdio(0);

	priority_queue<int> pqueueLess;
	priority_queue<int, vector<int>, greater<int> > pqueueGreater;

	int n;
	cin >> n;

	int val;

	cin >> val;
	pqueueLess.push(val);
	cout << val << '\n';

	int lessTop, greaterTop;

	for (int i = 1; i < n; i++) {
		cin >> val;
		pqueueLess.push(val);
		
		if (pqueueLess.size() > pqueueGreater.size() + 1) {
			pqueueGreater.push(pqueueLess.top());
			pqueueLess.pop();
		}

		lessTop = pqueueLess.top();
		greaterTop = pqueueGreater.top();
		if (lessTop > greaterTop) {
			pqueueLess.pop();
			pqueueGreater.pop();
			pqueueLess.push(greaterTop);
			pqueueGreater.push(lessTop);
		}

		cout << pqueueLess.top() << '\n';
	}

	return 0;
}