/*
    #백준11048 이동하기(S2)
        - dp문제
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a[1003][1003], dp[1003][1003];
int go(int y, int x) {
    if (y < 0 || x < 0) return 0;
    int &ret = dp[y][x];
    if (ret != -1) return ret;
    ret = a[y][x];
    return ret += max({go(y - 1, x - 1), go(y - 1, x), go(y, x - 1)});
}
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    fill(&dp[0][0], &dp[0][0] + 1003 * 1003, -1);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    cout << go(n, m);
    return 0;
}