/*
    #백준14503 로봇 청소기(G5)
        - 구현 문제
*/
#include <iostream>
#include <algorithm>

using namespace std;
int n, m, y, x, d, a[51][51];
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
bool isCheck() {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (a[ny][nx] == 0) return true;
    }
    return false;
}
void isChange() {
    if (d > 0) d--;
    else d = 3;
}
bool isBack() {
    int _d = 0;
    if (d == 0) _d = 2;
    else if (d == 1) _d = 3;
    else if (d == 2) _d = 0;
    else _d = 1;
    y = y + dy[_d];
    x = x + dx[_d];
    if (y < 0 || x < 0 || y >= n || x >= m || a[y][x] == 1) return false;
    return true;
}
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    cin >> y >> x >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    while (1) {
        if (a[y][x] == 0) {
            a[y][x] = 2;
            ans++;
        } else {
            if (isCheck()) {
                while (1) {
                    isChange();
                    int ny = y + dy[d];
                    int nx = x + dx[d];
                    if (a[ny][nx] == 0) break;
                }
                y = y + dy[d];
                x = x + dx[d];
            } else {
                if (!isBack()) break;
            }
        }
    }
    cout << ans;
}