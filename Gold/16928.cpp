#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m, visited[101];
vector<int> adj[101];
queue<pair<int, int>> q;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    q.push({0, 1});
    visited[1] = 1;
    int ans = 0;
    while (q.size()) {
        pair<int, int> cur = q.front(); q.pop();
        int cnt = cur.first;
        int node = cur.second;
        if (node == 100) {
            ans = cnt; break;
        }
        for (int i = 1; i <= 6; i++) {
            int next = node + i;
            if (next > 100 || visited[next]) continue;
            if (adj[next].size()) q.push({cnt + 1, adj[next][0]});
            else q.push({cnt + 1, next});
            visited[next] = 1;
        }
    }
    cout << ans << "\n";
    return 0;
}