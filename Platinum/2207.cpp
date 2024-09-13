/*
    #백준2207 가위바위보(P4)
        -기본 2-SAT문제
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

inline int nX(int x) { return x ^ 1; }
inline int tX(int x) { return x * 2 - 2; }
inline int fX(int x) { return x * 2 - 1; }
const int max_m = 20004;
int n, m, disc[max_m], node_scc[max_m], disc_num, scc_num;
vector<int> adj[max_m];
stack<int> stk;
int dfs(int cur) {
    disc[cur] = disc_num++;
    stk.push(cur);
    int val = disc[cur];
    for (int next : adj[cur]) {
        if (disc[next] == -1) val = min(val, dfs(next));
        else if (node_scc[next] == -1) val = min(val, disc[next]);
    }
    if (val == disc[cur]) {
        while (1) {
            int target = stk.top(); stk.pop();
            node_scc[target] = scc_num;
            if (target == cur) break;
        }
        scc_num++;
    }
    return val;
}
int main(void) {
    ios::sync_with_stdio(false);cin.tie(0);
    fill(disc, disc + max_m, -1);
    fill(node_scc, node_scc + max_m, -1);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int u, v; cin >> u >> v;
        u = u > 0 ? tX(u) : fX(-u);
        v = v > 0 ? tX(v) : fX(-v);
        adj[nX(u)].push_back(v);
        adj[nX(v)].push_back(u);
    }
    for (int i = 0; i <= m * 2 - 1; i++) {
        if (disc[i] == -1) dfs(i);
    }
    bool flag = true;
    for (int i = 1; i <= m; i++) {
        if (node_scc[fX(i)] == node_scc[tX(i)]) {
            flag = false; break;
        }
    }
    if (flag) cout << "^_^";
    else cout << "OTL";
    return 0;
}