/*
    #백준11280 2-SAT - 3(P4)
        - 2-SAT문제 (scc를 이용)
        - 2-SAT(2-Satisfiability)로 충족 가능성 문제 중 하나
        - 충족 가능성 문제 : 여러 개의 boolean 변수들로 이루어진 boolean expression이 있을 때,
                         각 변수읠 값을 true, false 중 하나로 설정하여 전체 식의 결과를 true로 만들 수 있느냐는 문제
        - 여기서 2-SAT는 각 절의 변수 개수가 최대 2개인 경우
            - 절 : 괄호 단위의, OR 연산으로만 이루어진 부분
        - 출처 : https://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220803009418
*/      
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

const int max_n = 20004;
int n, m, disc[max_n], node_scc[max_n], disc_num, scc_num;
vector<vector<int>> scc;
vector<int> adj[max_n];
stack<int> stk;
inline int nX(int x) { return x ^ 1; }
inline int tX(int x) { return x * 2 - 2; }
inline int fX(int x) { return x * 2 - 1; }
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
        if (node_scc[tX(i)] == node_scc[fX(i)]) {
            flag = false; break;
        }
    }
    if (flag) cout << 1;
    else cout << 0;
    return 0;
}