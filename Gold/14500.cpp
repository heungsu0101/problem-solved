/*
    #백준14500 테트로미노(G4)
        - 백트래킹을 이용한 구현문제
        - ㅏ,ㅓ,ㅗ,ㅜ를 제외한 나머지 모형들은 백트래킹을 통해 고려가능
        - ㅏ,ㅓ,ㅗ,ㅜ의 경우 백트래킹을 진행하면 로직 상 크기가 3인 모양만 고려하게 됨. 결국 의도한대로 로직이 실행되지 않음
        - 그렇기 때문에 위의 4가지 예외 경우만 따로 고려해주면 됨
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a[502][502], ans = -1, visited[502][502];
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
void dfs(int y, int x, int cnt, int sum) {
    if (cnt == 4) {
        ans = max(ans, sum);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        dfs(ny, nx, cnt + 1, sum + a[ny][nx]);
        visited[ny][nx] = 0;
    }
}
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = 1;
            dfs(i, j, 1, a[i][j]);
            visited[i][j] = 0;
            if (i + 2 < n && j + 1 < m) ans = max(ans, a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 1][j + 1]);
            if (i + 2 < n && j - 1 >= 0) ans = max(ans, a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 1][j - 1]);
            if (j + 2 < m && i + 1 < n) ans = max(ans, a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j + 1]);
            if (j + 2 < m && i - 1 >= 0) ans = max(ans, a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i - 1][j + 1]);
        }
    }
    cout << ans;
    return 0;
}