/*
    #백준11281 2-SAT - 4(P3)
        - 2-SAT문제
        - x들이 true인지 false인지 판단할 때, 타잔알고리즘을 통해 구해진 scc의 번호는 위상정렬의 역순임을 이용하면 됨
        - p -> q일 때, 전제조건이 거짓이면 무조건 참임을 이용하면 됨
        - ~x -> x일 때는 x가 true여야 하고, x -> ~x일 경우, x가 false야 함
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

inline int nX(int x) { return x ^ 1; }
inline int tX(int x) { return x * 2 - 2; }
inline int fX(int x) { return x * 2 - 1; }

const int max_n = 20004;
int n, m, scc_num, disc_num, disc[max_n], node_scc[max_n];
stack<int> stk;
vector<vector<int>> scc;
vector<int> adj[max_n];
int dfs(int cur) {
    disc[cur] = disc_num++;
    stk.push(cur);
    int val = disc[cur];
    for (int next : adj[cur]) {
        if (disc[next] == -1) val = min(val, dfs(next));
        else if (node_scc[next] == -1) val = min(val, disc[next]);
    }
    if (val == disc[cur]) {
        vector<int> ret;
        while (1) {
            int target = stk.top(); stk.pop();
            node_scc[target] = scc_num;
            ret.push_back(target);
            if (target == cur) break;
        }
        scc.push_back(ret);
        scc_num++;
    }
    return val;
} 

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    fill(disc, disc + max_n, -1);
    fill(node_scc, node_scc + max_n, -1);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u = u > 0 ? tX(u) : fX(-u);
        v = v > 0 ? tX(v) : fX(-v); 
        adj[nX(u)].push_back(v);
        adj[nX(v)].push_back(u);
    }
    for (int i = 0; i <= n * 2 - 1; i++) {
        if (disc[i] == -1) dfs(i);
    }
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (node_scc[i] == node_scc[nX(i)]) {
            flag = false; break;
        }
    }
    if (!flag) cout << 0;
    else {
        cout << "1\n";
        for (int i = 1; i <= n; i++) {
            if (node_scc[tX(i)] < node_scc[fX(i)]) cout << 1 << " ";
            else cout << 0 << " ";
        }
    }
    return 0;
}