/*
    #백준3190 뱀(G4)
        - 큐 + 구현문제
        - 사과가 없을 때 뱀이 한칸씩 이동하는 것을 큐를 이용함
            - 한칸씩 이동하는게 곧 칸의 입장에서 선입선출 방식이므로 큐를 사용하면 됨
*/
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, k, a[101][101], t_dir[10004], pos[101][101], l, ans, dir = 2, y = 1, x = 1, _size = 1; // dir : 서 북 동 남
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};
queue<pair<int, int>> q;
void isDir(int lr) {
    if (lr == 1) {
        if (dir == 0) dir = 3;
        else dir--;
    } else {
        if (dir == 3) dir = 0;
        else dir++;
    }
}
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int y, x; cin >> y >> x;
        a[y][x] = 1;
    }
    cin >> l;
    for (int i = 0; i < l; i++) {
        int t; char d; cin >> t >> d;
        if (d == 'L') t_dir[t] = 1;
        else t_dir[t] = 2;
    }
    a[1][1] = 2;
    q.push({1, 1});
    while (1) {
        ans++;
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny <= 0 || nx <= 0 || ny > n || nx > n || a[ny][nx] == 2) break;
        if (a[ny][nx] == 1) {
            a[ny][nx] = 2;
            q.push({ny, nx});
        } else {
            a[ny][nx] = 2;
            q.push({ny, nx});
            a[q.front().first][q.front().second] = 0;
            q.pop();
        }
        y = ny; x = nx;
        if (t_dir[ans]) isDir(t_dir[ans]);
    }
    cout << ans;
    return 0;
}