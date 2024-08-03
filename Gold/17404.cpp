/*
    #백준17404 합분해(G4)
        - dp문제
        - 2차원 dp를 이용해 bottom up 방식으로 dp를 최적화해서 문제를 해결하면 됨
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int n, a[1003][1003], dp[1003][3], ans = INF;
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) dp[1][j] = a[1][j];
            else dp[1][j] = INF;
        }
        for (int j = 2; j <= n; j++) {
            dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + a[j][0];
            dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + a[j][1];
            dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + a[j][2];
        }
        for (int j = 0; j < 3; j++) {
            if (j == i) continue;
            ans = min(ans, dp[n][j]);
        }
    }
    cout << ans << "\n";
    return 0;
}