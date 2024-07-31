/*
    #백준1707 나머지 합(G3)
        - 그래프 문제
        - dfs 또는 bfs를 통해 그래프 순회 후 이분그래프로 나눠지는지 확인하면 됨
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, visited[20004];
vector<int> adj[20004];
void dfs(int cur, int flag) {
    visited[cur] = flag;
    flag == 1 ? flag = 2 : flag = 1;
    for (int next : adj[cur]) {
        if (visited[next]) continue;
        dfs(next, flag);
    }
}
bool isChecked() {
    for (int i = 1; i <= n; i++) {
        for (int j : adj[i]) {
            if (visited[i] == visited[j]) return false;
        }
    }
    return true;
}
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    int k; cin >> k;
    while (k--) {
        fill(visited, visited + 20004, 0);
        for (int i = 0; i < 20004; i++) adj[i].clear();
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) dfs(i, 1);
        }
        if (isChecked()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}