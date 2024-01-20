#include <iostream>

int main() {
	std::cin.tie(0);
	std::ios_base::sync_with_stdio(0);

	int dp[30][30];

	for (int i = 1; i < 30; i++) {
		dp[1][i] = i;
	}

	for (int i = 2; i < 30; i++) {
		for (int j = i; j < 30; j++) {
			if (i == j) {
				dp[i][j] = 1;
			} else {
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
			}
		}
	}

	int t;
	std::cin >> t;

	int siteA, siteB;
	for (int i = 0; i < t; i++) {
		std::cin >> siteA >> siteB;
		std::cout << dp[siteA][siteB] << '\n';
	}

	return 0;
}