/*
    #백준1535 안녕(S2)
        - 백트래킹 또는 dp를 이용해 문제해결가능
*/

/*
    dp코드
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n, a[21], h[21], dp[101];
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) {
        for (int j = 100; j > a[i]; j--) {
            dp[j] = max(dp[j], dp[j - a[i]] + h[i]);
        }
    }
    cout << dp[100] << "\n";
    return 0;
}
/*
    백트래킹 코드
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n, a[21], j[21], ans;
void go(int idx, int hp, int ret) {
    if (hp <= 0) return;
    if (idx == n) {
        ans = max(ans, ret);
        return;
    }
    go(idx + 1, hp - a[idx], ret + j[idx]);
    go(idx + 1, hp, ret);
}
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> j[i];
    }
    go(0, 100, 0);
    cout << ans << "\n";
    return 0;
}