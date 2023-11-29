#include <iostream>

int main() {
	int n;
	std::cin >> n;

	int dp[1000001] = {0,};

	dp[1] = 0;

	int min;
	for (int i = 2; i <= n; i++) {
		min = dp[i - 1];
		if (i % 3 == 0) {
			min = std::min(min, dp[i / 3]);
		}
		if (i % 2 == 0) {
			min = std::min(min, dp[i / 2]);
		}
		dp[i] = min + 1;
	}

	std::cout << dp[n] << '\n';
}