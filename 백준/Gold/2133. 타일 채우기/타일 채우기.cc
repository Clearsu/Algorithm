#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	if (n % 2 != 0) {
		cout << "0\n";
		return 0;
	}

	int dp[31];

	dp[0] = 1;
	dp[2] = 3;

	int j;
	for (int i = 4; i <= n; i += 2) {
		dp[i] = dp[i - 2] * 3;
		j = i - 4;
		while (j >= 0) {
			dp[i] += dp[j] * 2;
			j -= 2;
		}
	}

	cout << dp[n] << '\n';
	
	return 0;
}