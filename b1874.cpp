#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	stack<int> stack;
	queue<char> toPrint;

	cin >> n;

	int num = 0;
	for (int i = 1; i <= n; i++) {
		stack.push(i);
		toPrint.push('+');
		while (!stack.empty()) {
			if (num == 0) {
				cin >> num;
			}
			if (stack.top() != num) {
				break ;
			}
			num = 0;
			stack.pop();
			toPrint.push('-');
		}
	}

	if (!stack.empty()) {
		cout << "NO\n";
	} else {
		while (!toPrint.empty()) {
			cout << toPrint.front() << '\n';
			toPrint.pop();
		}
	}

	return 0;
}