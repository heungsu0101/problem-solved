/*
    #백준15990 1, 2, 3 더하기 5(S2)
        - dp문제
*/
#include <iostream>
#include <algorithm>

using namespace std;
const int mod = 1000000009;
int n, dp[100005][3];
int go(int n, int prev) {
    if (n < 0) return 0;
    if (n == 0) return 1;

    int &ret = dp[n][prev];
    if (ret != -1) return ret;

    if (prev == 1) return ret = (go(n - 2, 2) + go(n - 3, 3)) % mod;
    else if (prev == 2) return ret = (go(n - 1, 1) + go(n - 3, 3)) % mod;
    else return ret = (go(n - 1, 1) + go(n - 2, 2)) % mod;
}
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    fill(&dp[0][0], &dp[0][0] + 100005 * 3, -1);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        cout << ((go(n - 1, 1) + go(n - 2, 2)) % mod + go(n - 3, 3)) % mod << "\n";
    }
    return 0;
}