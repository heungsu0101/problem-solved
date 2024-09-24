/*
    #백준12100 2048 (Easy) (G1)
        - 백트래킹 + 구현문제
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, ans;
vector<vector<int>> a(21, vector<int>(21, 0));
void isUp() {
    for (int j = 0; j < n; j++) { // 각 열에 대해서
        int idx = 0;
        int prev = 0;
        for (int i = 0; i < n; i++) { // 각 행에 대해서
            int cur = a[i][j];
            if (!cur) continue;
            if (!prev) prev = cur;
            else {
                if (cur != prev) {
                    a[idx++][j] = prev;
                    prev = cur;
                } else {
                    a[idx++][j] = prev * 2;
                    prev = 0;
                }
                ans = max(ans, a[idx - 1][j]);
            }
        }
        if (prev) {
            a[idx++][j] = prev;
            ans = max(ans, a[idx - 1][j]);
        }
        for (int i = idx; i < n; i++) a[i][j] = 0;
    }
}
void isDown() {
    for (int j = 0; j < n; j++) {
        int idx = n - 1;
        int prev = 0;
        for (int i = n - 1; i >= 0; i--) {
            int cur = a[i][j];
            if (!cur) continue;
            if (!prev) prev = cur;
            else {
                if (cur != prev) {
                    a[idx--][j] = prev;
                    prev = cur;
                } else {
                    a[idx--][j] = prev * 2;
                    prev = 0;
                }
                ans = max(ans, a[idx + 1][j]);
            }
        }
        if (prev) {
            a[idx--][j] = prev;
            ans = max(ans, a[idx + 1][j]);
        }
        for (int i = 0; i <= idx; i++) a[i][j] = 0;
    }
};
void isLeft() {
    for (int i = 0; i < n; i++) {
        int idx = 0;
        int prev = 0;
        for (int j = 0; j < n; j++) {
            int cur = a[i][j];
            if (!cur) continue;
            if (!prev) prev = cur;
            else {
                if (cur != prev) {
                    a[i][idx++] = prev;
                    prev = cur;
                } else {
                    a[i][idx++] = prev * 2;
                    prev = 0;
                }
                ans = max(ans, a[i][idx - 1]);
            }
        }
        if (prev) {
            a[i][idx++] = prev;
            ans = max(ans, a[i][idx - 1]);
        }
        for (int j = idx; j < n; j++) a[i][j] = 0;
    }
};
void isRight() {
    for (int i = 0; i < n; i++) {
        int idx = n - 1;
        int prev = 0;
        for (int j = n - 1; j >= 0; j--) {
            int cur = a[i][j];
            if (!cur) continue;
            if (!prev) prev = cur;
            else {
                if (cur != prev) {
                    a[i][idx--] = prev;
                    prev = cur;
                } else {
                    a[i][idx--] = prev * 2;
                    prev = 0;
                }
                ans = max(ans, a[i][idx + 1]);
            }
        }
        if (prev) {
            a[i][idx--] = prev;
            ans = max(ans, a[i][idx + 1]);
        }
        for (int j = 0; j <= idx; j++) a[i][j] = 0;
    }
};
void isMove(int dir) {
    if (dir == 1) isUp();
    else if (dir == 2) isDown();
    else if (dir == 3) isLeft();
    else isRight();
}
void go(int cnt) {
    if (cnt >= 5) return;
    vector<vector<int>> tmp;
    tmp = a;
    for (int i = 1; i <= 4; i++) {
        isMove(i);
        go(cnt + 1);
        a = tmp;
    }
}
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    go(0);
    cout << ans << "\n";
    return 0;
}