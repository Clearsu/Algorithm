#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000];
int dp[1000];

int main(void) {
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int maxLen = 0;

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		if (dp[i] > maxLen) {
			maxLen = dp[i];
		}
	}

	cout << maxLen << '\n';

	return 0;
}