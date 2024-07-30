/*
    #백준12865 평범한 배낭(G5)
        - 기본 냅색 dp문제
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n, k, w[101], v[101], dp[101][100005];
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
    for (int i = 1; i <= n; i++) {
        for (int j = k; j > 0; j--) {
            if (j - w[i] >= 0) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][k] << "\n";
    return 0;
}