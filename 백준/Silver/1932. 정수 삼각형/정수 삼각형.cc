#include <iostream>
using namespace std;

int triangle[500][500];
int dp[500][500];

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> triangle[i][j];
		}
	}

	dp[0][0] = triangle[0][0];
	dp[1][0] = dp[0][0] + triangle[1][0];
	dp[1][1] = dp[0][0] + triangle[1][1];

	int temp;
	for (int i = 2; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				temp = dp[i - 1][j];
			} else if (j == i) {
				temp = dp[i - 1][j - 1];
			} else {
				temp = max(dp[i - 1][j], dp[i - 1][j - 1]);
			}
			dp[i][j] = temp + triangle[i][j];
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		if (dp[n - 1][i] > max) {
			max = dp[n - 1][i];
		}
	}

	cout << max << '\n';

	return 0;
}