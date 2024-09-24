/*
    #1309 동물원(S1)
        - dp문제
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 9901;
int n, dp[100005][3];

int main(void) {
    cin >> n;
    dp[1][0] = dp[1][1] = dp[1][2] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % mod;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
    }
    cout << (dp[n][0] + dp[n][1] + dp[n][2]) % mod;
    return 0;
}