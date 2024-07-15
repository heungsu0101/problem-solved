#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int n, ans = INF, dp[5003];
void go(int n, int cnt) {
    if (dp[n] != 0) return;
    dp[n] = 1;
    if (n == 0) {
        ans = cnt;
        return;
    }
    if (n - 5 >= 0) go(n - 5, cnt + 1);
    if (n - 3 >= 0) go(n - 3, cnt + 1);
}
int main(void) {
    cin >> n;
    go(n, 0);
    if (ans == INF) cout << "-1\n";
    else cout << ans << "\n";
    return 0;
}