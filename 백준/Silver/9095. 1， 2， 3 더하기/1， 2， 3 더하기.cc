#include <iostream>
using namespace std;

/*
 * 1
 * 1 : 1
 *
 * 2
 * 1 1, 2 : 2
 *
 * 3
 * 1 1 1, 1 2, 2 1, 3 : 4
 *
 * 4
 * 1 1 1 1, 1 1 2, 1 2 1, 2 1 1, 2 2, 3 1, 1 3 : 7
 *
 * 5
 * 1 1 1 1 1, 1 1 1 2, 1 1 2 1, 1 2 1 1, 2 1 1 1, 1 2 2, 2 1 2, 2 2 1, 1 1 3, 1 3 1, 3 1 1, 2 3, 3 2 : 13
 * */

int main(void) {
	int dp[11];

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= 10; i++) {
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}

	int n, testCase;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> testCase;
		cout << dp[testCase] << '\n';
	}

	return 0;
}