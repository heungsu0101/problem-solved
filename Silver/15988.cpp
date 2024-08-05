/*
    #백준15988 1, 2, 3 더하기 3(S2)
        - dp문제
*/
#include <iostream>
#include <algorithm>
using namespace std;

long long n, dp[1000006];
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    dp[1] = 1; dp[2] = 2; dp[3] = 4;
    for (int i = 4; i <= 1000000; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        dp[i] %= 1000000009;
    }
    while (t--) {
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}