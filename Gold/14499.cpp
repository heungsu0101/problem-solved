/*
    #백준14499 주사위굴리기(G4)
        - 구현문제
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, x, y, k, a[21][21], u = 1, s = 3, dise[7];
int dy[5] = {0, 0, 0, -1, 1}, dx[5] = {0, 1, -1, 0, 0};
void move(int i) {
    int tmp = dise[1];
    if (i == 1) {
        dise[1] = dise[4];
        dise[4] = dise[6];
        dise[6] = dise[3];
        dise[3] = tmp;
    } else if (i == 2) {
        dise[1] = dise[3];
        dise[3] = dise[6];
        dise[6] = dise[4];
        dise[4] = tmp; 
    } else if (i == 3) {
        dise[1] = dise[5];
        dise[5] = dise[6];
        dise[6] = dise[2];
        dise[2] = tmp;
    } else {
        dise[1] = dise[2];
        dise[2] = dise[6];
        dise[6] = dise[5];
        dise[5] = tmp;
    }
}
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> y >> x >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    while (k--) {
        int i; cin >> i;
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        move(i);
        if (a[ny][nx] == 0) a[ny][nx] = dise[6];
        else {
            dise[6] = a[ny][nx];
            a[ny][nx] = 0;
        }
        cout << dise[1] << "\n";
        y = ny; x = nx;
    }
    return 0;
}