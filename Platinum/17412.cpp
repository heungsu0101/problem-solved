/*
    #백준17412 도시 왕복하기 1(P4)
        - 네트워크 플로우 문제
        - 단방향 간선의 capacity를 1로 설정하여 augmenting path를 계속 찾아나가면 됨
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m, c[402][402], f[402][402], visited[402], ans;
vector<int> adj[402];

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        c[u][v] = 1;
    }
    while (1) {
        fill(visited, visited + 402, -1);
        queue<int> q;
        q.push(1);
        visited[1] = 0;
        bool flag = false;
        while (q.size()) {
            int cur = q.front(); q.pop();
            if (cur == 2) {
                flag = true; break;
            }
            for (int next : adj[cur]) {
                if (visited[next] != -1) continue;
                if (c[cur][next] - f[cur][next] > 0) {
                    q.push(next);
                    visited[next] = cur;
                }
            }
        }
        if (!flag) break;
        else {
            int cur = 2;
            while (cur != 1) {
                int prev = visited[cur];
                f[prev][cur] += 1;
                f[cur][prev] -= 1;
                cur = prev;
            }
        }
        ans++;
    }
    cout << ans;
    return 0;
}