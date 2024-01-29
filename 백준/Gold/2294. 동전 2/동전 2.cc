#include <iostream>
#include <utility>
using namespace std;

int dp[10001];

int main() {
  int n, k;
  int coins[100];

  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }

  for (int i = 0; i <= k; i++) {
    dp[i] = 10001;
  }

  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = coins[i]; j <= k; j++) {
      dp[j] = min(dp[j], dp[j - coins[i]] + 1); 
    }
  }

  if (dp[k] > 10000) {
    cout << "-1\n";
  } else {
    cout << dp[k] << '\n';
  }

  return 0;
}