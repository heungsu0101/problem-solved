/*
    #백준3648 아이돌(P3)
        - 2-SAT문제
        - 기본 2-SAT 문제에서 상근이가 무조건 통과해야하므로, 1이 무조건 true임을 설정하기 위해 ~1 -> 1의 간선을 추가해주면 됨.
        - 이후 목록을 만들 수 있는지만 판단하면 문제를 해결할 수 있음
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

inline int nX(int x) { return x ^ 1; }
inline int tX(int x) { return x * 2 - 2; }
inline int fX(int x) { return x * 2 - 1; }

const int max_n = 2003;
int n, m;
int disc_num, disc[max_n], node_scc[max_n], scc_num;
vector<int> adj[max_n];
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
    ios::sync_with_stdio(false); cin.tie(0);
    while (cin >> n >> m) {
        for (int i = 0; i < max_n; i++) adj[i].clear();
        disc_num = 0;
        scc_num = 0;
        fill(disc, disc + max_n, -1);
        fill(node_scc, node_scc + max_n, -1);
        adj[fX(1)].push_back(tX(1));
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            u = u > 0 ? tX(u) : fX(-u);
            v = v > 0 ? tX(v) : fX(-v);
            adj[nX(u)].push_back(v);
            adj[nX(v)].push_back(u); 
        }
        for (int i = 0; i <= 2 * n - 1; i++) {
            if (disc[i] == -1) dfs(i);
        }
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            if (node_scc[tX(i)] == node_scc[fX(i)]) {
                flag = false; break;
            }
        }
        if (flag) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}