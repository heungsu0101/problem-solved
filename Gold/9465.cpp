/*
    #백준9465 스티커(S1)
        - 2차원 dp문제
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n, dp[2][100005], a[2][100005];
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        dp[0][0] = a[0][0]; 
        dp[1][0] = a[1][0];
        dp[0][1] = a[0][1] + a[1][0];
        dp[1][1] = a[1][1] + a[0][0];
        for (int i = 2; i < n; i++) {
            dp[0][i] = a[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
            dp[1][i] = a[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
        }
        cout << max(dp[0][n - 1], dp[1][n - 1]) << "\n"; 
    }

    return 0;
}