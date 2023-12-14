#include <iostream>
#include <array>

using namespace std;

int n;
int arr[1000000];

void insertValue(int start, int end, int value) {
	int mid;

	while (true) {
		if (start == end) {
			arr[start] = value;
			return ;
		}
		mid = (start + end) / 2;
		if (value > arr[mid]) {
			start = mid + 1;
			continue ;
		}
		end = mid;
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;

	int value;

	cin >> value;
	arr[0] = value;

	int currIdx = 0;

	for (int i = 1; i < n; i++) {
		cin >> value;
		if (value > arr[currIdx]) {
			arr[++currIdx] = value;
			continue ;
		}
		insertValue(0, currIdx, value);
	}

	cout << currIdx + 1 << '\n';

	return 0;
}