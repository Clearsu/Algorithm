#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    int dp[10001] = {0, };

    dp[0] = 1;

    int coin;
    for (int i = 0; i < n; i++) {
        cin >> coin;
        for (int j = coin; j <= k; j++) {
            dp[j] += dp[j - coin];
        }
    }

    cout << dp[k] << '\n';

    return 0;
}