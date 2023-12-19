#include <iostream>
#include <deque>

using namespace std;

int arr[1000];
deque<int> LIS;
deque<int> reverseLIS;
int LISDP[1000];
int reverseLISDP[1000];

void updateForward(int value) {
	int start, end, mid;

	start = 0;
	end = LIS.size() - 1;

	while (start != end) {
		mid = (start + end) / 2;
		if (LIS[mid] < value) {
			start = mid + 1;
		} else {
			end = mid;
		}
	}
	LIS[start] = value;
}

void updateReverse(int value) {
	int start, end, mid;

	start = reverseLIS.size() - 1;
	end = 0;

	while (start != end) {
		mid = (start + end) / 2 + 1;
		if (reverseLIS[mid] < value) {
			start = mid - 1;
		} else {
			end = mid;
		}
	}
	reverseLIS[start] = value;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	LIS.push_back(arr[0]);
	LISDP[0] = 1;

	for (int i = 1; i < n; i++) {
		if (arr[i] > LIS.back()) {
			LIS.push_back(arr[i]);
			LISDP[i] = LISDP[i - 1] + 1;
		} else {
			updateForward(arr[i]);
			LISDP[i] = LISDP[i - 1];
		}
	}

	reverseLIS.push_back(arr[n - 1]);
	reverseLISDP[n - 1] = 1;

	for (int i = n - 2; i >= 0; i--) {
		if (arr[i] > reverseLIS.front()) {
			reverseLIS.push_front(arr[i]);
			reverseLISDP[i] = reverseLISDP[i + 1] + 1;
		} else {
			updateReverse(arr[i]);
			reverseLISDP[i] = reverseLISDP[i + 1];
		}
	}

	int max = 0;
	int temp;
	for (int i = 0; i < n; i++) {
		temp = LISDP[i] + reverseLISDP[i];
		if (temp > max) {
			max = temp;
		}
	}

	if (max == LIS.size() || max == reverseLIS.size()) {
		cout << max << '\n';
	} else {
		cout << max - 1 << '\n';
	}

	return 0;
}