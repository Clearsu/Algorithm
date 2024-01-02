#include <iostream>
#include <algorithm>

using namespace std;

#define RED 0
#define GREEN 1
#define BLUE 2

int dp[1000][3];

int main() {
	int n;
	cin >> n;

	cin >> dp[0][RED];
	cin >> dp[0][GREEN];
	cin >> dp[0][BLUE];

	int r, g, b;
	for (int i = 1; i < n; i++) {
		cin >> r >> g >> b;
		dp[i][RED] = min(dp[i - 1][GREEN], dp[i - 1][BLUE]) + r;
		dp[i][GREEN] = min(dp[i - 1][RED], dp[i - 1][BLUE]) + g;
		dp[i][BLUE] = min(dp[i - 1][RED], dp[i - 1][GREEN]) + b;
	}

	int min = 2147483647;

	for (int i = 0; i < 3; i++) {
		if (dp[n - 1][i] < min) {
			min = dp[n - 1][i];
		}
	}

	cout << min << '\n';

	return 0;
}