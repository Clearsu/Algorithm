#include <iostream>
#include <algorithm>
using namespace std;

#define DURATION 0
#define BENEFIT 1

int main() {
    int n;
    int dp[16] = {0, };
    int targetDay, duration, benefit;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i], dp[i - 1]);
        cin >> duration >> benefit;
        targetDay = i + duration - 1;
        if (targetDay > n) {
            continue ;
        }
        dp[targetDay] = max(dp[targetDay], benefit + dp[i - 1]);
    }

    cout << dp[n] << '\n';

    return 0;
}