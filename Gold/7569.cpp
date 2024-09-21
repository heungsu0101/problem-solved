/*
    #백준7569 토마토(G5)
        - bfs문제
*/
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct node {
    int y, x, z;
};
int n, m, h, a[101][101][101], ans;
int dy[6] = {0, 0, 1, -1, 0, 0};
int dx[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
queue<node> q;

bool isCheck() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < h; k++) {
                if (a[i][j][k] == 0) return false;
            }
        }
    }
    return true;
}
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> m >> n >> h;
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j][k];
                if (a[i][j][k] == 1) q.push({i, j, k});
            }
        }
    }
    if (isCheck()) cout << 0;
    else {
        while (q.size()) {
            int q_size = q.size();
            bool flag = false;
            while (q_size--) {
                node cur = q.front(); q.pop();
                for (int i = 0; i < 6; i++) {
                    int ny = cur.y + dy[i];
                    int nx = cur.x + dx[i];
                    int nz = cur.z + dz[i];
                    if (ny < 0 || nx < 0 || nz < 0 || ny >= n || nx >= m || nz >= h) continue;
                    if (a[ny][nx][nz] == 0) {
                        flag = true;
                        a[ny][nx][nz] = 1;
                        q.push({ny, nx, nz});
                    }
                }
            }
            if (flag) ans++;
        }
        if (isCheck()) cout << ans;
        else cout << -1;
    }

    return 0;
}