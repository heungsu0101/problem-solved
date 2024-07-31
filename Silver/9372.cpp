/*
    #백준9372 상근이의 여행(S4)
        - MST 문제
        - MST는 n - 1개의 간선으로 이루어져 있음을 알면 됨
        - 따라서 주어진 간선의 종류 상관없이 무조건 답은 n - 1개
*/
#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    int k; cin >> k;
    while (k--) {
        int n, m; cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
        }
        cout << n - 1 << "\n";
    }
}