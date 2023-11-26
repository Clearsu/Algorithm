#include <iostream>

void fibonacci(int n) {
	int dp[41];
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}
	std::cout << dp[n - 1] << ' ' << dp[n] << '\n';
}

int main() {
	int t;
	std::cin >> t;
	std::cin.ignore();

	int n;
	for (int i = 0; i < t; i++) {
		std::cin >> n;
		std::cin.ignore();
		if (n == 0) {
			std::cout << "1 0\n";
		} else {
			fibonacci(n);
		}
	}
}