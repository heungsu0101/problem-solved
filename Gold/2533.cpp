/*
    #백준2533 사회망 서비스(SNS)(G3)
        - 트리 dp 문제
        - dp 점화식 세우는 연습을 할 필요가 있다고 느낌
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int max_n = 1000006;
int n, dp[2][max_n], visited[max_n];
vector<int> adj[max_n];

void go(int cur) {
    dp[1][cur] = 1;
    visited[cur] = 1;
    for (int next : adj[cur]) {
        if (visited[next]) continue;
        go(next);
        dp[0][cur] += dp[1][next];
        dp[1][cur] += min(dp[0][next], dp[1][next]);
    }
}
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    go(1);
    cout << min(dp[0][1], dp[1][1]) << "\n";
    return 0;
}