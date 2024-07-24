/*
    #백준16235 나무 재테크(G3)
        - 구현문제
        - 상하좌우가 아닌 대각선 포함 총 8개방향으로 퍼지는 dy, dx 문제
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[11][11], n, m, k, s[11][11];
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<int> tree[11][11];

void treeSort(int y, int x) {
    if (tree[y][x].size() >= 2) sort(tree[y][x].begin(), tree[y][x].end());
}
void isSS() { // 봄 여름
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (tree[i][j].size()) {
                for (int k = 0; k < tree[i][j].size(); k++) {
                    int &t = tree[i][j][k];
                    if (a[i][j] >= t) {
                        a[i][j] -= t; t += 1;
                    } else {
                        for (int l = k; l < tree[i][j].size(); l++) {
                            a[i][j] += tree[i][j][l] / 2;
                        }
                        tree[i][j].erase(tree[i][j].begin() + k, tree[i][j].end());
                        break;
                    }
                }
            }
        }
    }
}
void isF() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int t : tree[i][j]) {
                if (t % 5 == 0) {
                    for (int k = 0; k < 8; k++) {
                        int ny = i + dy[k];
                        int nx = j + dx[k];
                        if (ny <= 0 || nx <= 0 || ny > n || nx > n) continue;
                        tree[ny][nx].push_back(1);
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            treeSort(i, j);
        }
    } 
}
void isW() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] += s[i][j];
        }
    }
}
int isAns() {
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ret += tree[i][j].size();
        }
    }
    return ret;
}
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    fill(&a[0][0], &a[0][0] + 11 * 11, 5);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> s[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        int y, x, z; cin >> y >> x >> z;
        tree[y][x].push_back(z);
    }
    while (k--) {
        isSS();
        isF();
        isW();
    }
    cout << isAns() << "\n";
}