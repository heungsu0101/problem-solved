/*
    #백준2316 도시 왕복하기2(P3)
        - maximum flow 문제
        - 이 문제는 엣지 중복처리가 아닌, 정점 중복처리를 해줘야하므로 
          정점 내에 가중치를 주기 위해서 정점을 in, out으로 분리시켜 문제를 해결할 수 있음     
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
const int max_n = 400 * 2 + 3;
int n, p, visited[max_n], c[max_n][max_n], f[max_n][max_n], ans;
vector<int> adj[max_n];
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> p;
    for (int i = 0; i < p; i++) {
        int u, v; cin >> u >> v;
        int u_in, u_out, v_in, v_out;
        u_in = u * 2 - 1; u_out = u * 2;
        v_in = v * 2 - 1; v_out = v * 2;
        adj[u_out].push_back(v_in);
        adj[v_in].push_back(u_out);
        adj[v_out].push_back(u_in);
        adj[u_in].push_back(v_out);
        c[u_out][v_in] = 1;
        c[v_out][u_in] = 1; 
    }
    for (int i = 1; i < max_n; i += 2) {
        adj[i].push_back(i + 1);
        c[i][i + 1] = 1;
    }
    c[1][2] = 987654321;
    while (1) {
        fill(visited, visited + max_n, 0);
        queue<int> q;
        q.push(1);
        visited[1] = 1;
        bool flag = false;
        while (q.size()) {
            int cur = q.front(); q.pop();
            if (cur == 3) {
                flag = true; break;
            }
            for (int next : adj[cur]) {
                if (visited[next]) continue;
                if (c[cur][next] - f[cur][next] > 0) {
                    visited[next] = cur;
                    q.push(next);
                }
            }
        }
        if (!flag) break;
        else {
            int cur = 3;
            while (cur != 1) {
                int prev = visited[cur];
                f[prev][cur] += 1;
                f[cur][prev] -= 1;
                cur = prev;
            }
            ans++;
        }
    }
    cout << ans;
}