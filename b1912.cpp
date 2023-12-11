#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n;
	cin >> n;

	int num;
	cin >> num;

	if (n == 1) {
		cout << num << '\n';
		return 0;
	}

	int maxVal = num;
	int curr = num;

	for (int i = 1; i < n; i++) {
		cin >> num;
		curr = max(curr + num, num);
		if (curr > maxVal) {
			maxVal = curr;
		}
	}

	cout << maxVal << '\n';
}