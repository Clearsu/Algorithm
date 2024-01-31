#include <iostream>

int main() {
	int n;
	std::cin >> n;

	long long dp[91];

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	std::cout << dp[n] << '\n';

	return 0;
}