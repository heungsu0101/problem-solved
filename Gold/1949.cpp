/*
    #백준1949 우수 마을(G2)
        - 트리 dp 문제
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, a[10004], dp[10004][2], visited[10004];
vector<int> adj[10004];
void go(int nd) {
    visited[nd] = 1;
    dp[nd][0] = 0;
    dp[nd][1] = a[nd];
    for (int child : adj[nd]) {
        if (visited[child]) continue;
        go(child);
        dp[nd][0] += max(dp[child][0], dp[child][1]);
        dp[nd][1] += dp[child][0];
    }
}
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    go(1);
    cout << max(dp[1][0], dp[1][1]) << "\n";
    return 0;
}