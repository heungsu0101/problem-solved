/*
    #백준10282 해킹(G4)
        - 다익스트라 문제
        - 전형적인 다익스트라 문제임
        - 해당 문제를 많이 틀렸는데, 문제해석을 잘못함... 마지막 컴퓨터의 의미가 n번째 컴퓨터인줄 알았으나, 마지막으로 해킹되는 컴퓨터를 의미함.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int, int>
using namespace std;

const int INF = 987654321;
int n, d, c, dist[10004], visited[10004];
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        fill(visited, visited + 10004, 0);
        fill(dist, dist + 10004, INF);
        vector<pii> adj[10004];
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        cin >> n >> d >> c;
        for (int i = 0; i < d; i++) {
            int u, v, w; cin >> u >> v >> w;
            adj[v].push_back({w, u});
        }
        pq.push({0, c});
        dist[c] = 0;
        while (pq.size()) {
            int cur, w; tie(w, cur) = pq.top(); pq.pop();
            if (dist[cur] != w) continue;
            for (pii next : adj[cur]) {
                int _next = next.second;
                int _w = next.first;
                if (dist[_next] > dist[cur] + _w) {
                    dist[_next] = dist[cur] + _w;
                    pq.push({dist[_next], _next});
                }
            }
        }
        int cnt = 0, ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] != INF) {
                cnt++;
                ans = max(ans, dist[i]);
            }
        }
        cout << cnt << " " << ans << "\n";
    }
    return 0;
}