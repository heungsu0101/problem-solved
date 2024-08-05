/*
    #백준1915 가장 큰 정사각형(G4)
        - dp문제
        - 점화식을 세워서 바텀업방식으로 문제를 해결할 수 있음
        - 점화식 세우는 것이 관건!
*/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n, m, a[1003][1003], dp[1003][1003], ans;
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        for (int j = 1; j <= m; j++) {
            a[i][j] = s[j - 1] - '0';
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j]) {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                ans = max(ans, dp[i][j] * dp[i][j]);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}