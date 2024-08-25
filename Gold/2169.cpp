/*
    #백준2169 로봇조종하기(G2)
        - dp문제
        - 몇차원 dp를 사용해야할지 고민될 떄, 고려해야할 요소가 몇개인지 생각해보면 됨
        - 해당 문제에서 y, x좌표만 고려하면 된다고 생각하고 2차원dp를 이용하게 되면 꼬이게 됨
        - 이 문제의 경우 y, x좌표 뿐만 아니라, 해당 좌표를 어느 방향에서 왔는지 또한 고려해야하기 때문에 3차원dp를 통해 문제를 해결할 수 있음
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int INF = -2e9;
int n, m, a[1003][1003], dp[1003][1003][3];
int dy[3]= {0, 0, 1}, dx[3] = {-1, 1, 0};
int dfs(int y, int x, int d) {
    if (y == n - 1 && x == m - 1) return a[y][x];

    int &ret = dp[y][x][d];
    if (ret != INF) return ret;

    int val = INF;
    for (int i = 0; i < 3; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if ((d == 0 && i == 1) || (d == 1 && i == 0)) continue;
        val = max(val, a[y][x] + dfs(ny, nx, i));
    }

    return ret = val;
}
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    fill(&dp[0][0][0], &dp[0][0][0] + 1003 * 1003 * 3, INF);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    cout << max({dfs(0, 0, 0), dfs(0, 0, 1), dfs(0, 0, 2)});
    return 0;
}