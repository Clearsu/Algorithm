#include <iostream>
#include <queue>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	priority_queue<int> pqueue;
	
	int n, val;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> val;
		if (val == 0) {
			if (pqueue.empty()) {
				cout << "0\n";
			} else {
				cout << pqueue.top() << '\n';
				pqueue.pop();
			}
		} else {
			pqueue.push(val);
		}
	}
	
	return 0;
}