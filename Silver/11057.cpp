/*
    #백준11057 오르막 수(S1)
        - dp문제
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n, dp[1003][11], ans = 0;
int main(void) {
    cin >> n;
    for (int i = 0; i < 10; i++) dp[0][i] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= 10007;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        ans += dp[n - 1][i];
        ans %= 10007;
    }
    cout << ans << "\n";
    return 0;
}