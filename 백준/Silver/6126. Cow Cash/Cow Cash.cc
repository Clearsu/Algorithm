#include <iostream>
#include <vector>

using namespace std;

long long dp[10001];
int coins[25];

int main() {
	int v, n;

	cin >> v >> n;
	for (int i = 0; i < v; i++) {
		cin >> coins[i];
	}

	dp[0] = 1;

	for (int i = 0; i < v; i++) {
		for (int j = coins[i]; j <= n; j++) {
			dp[j] += dp[j - coins[i]];
		}
	}

	cout << dp[n] << '\n';

	return 0;
}