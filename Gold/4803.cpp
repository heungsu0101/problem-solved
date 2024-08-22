/*
    #백준4803 트리(G4)
        - 유니온파인드 or dfs 문제 (두가지 방법을 풀 수 있음)
        - 사이클의 유무, 그래프의 노드 개수 == 엣지 개수 + 1를 고려하여 트리인지 아닌지를 판단해야함
        - 해당 코드는 사이클의 유무만 판단함,
          이 부분에 대해서 조금만 생각해보면 당연함. 사이클이 있을 경우는 엣지의 수가 노드의 개수 - 1보다 많아야만 사이클이 가능하기 때문에
          실질적으로는 사이클의 유무만 판단해도 노드의 개수 == 엣지의 개수 - 1 또한 고려한 것을 알 수 있음
*/
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int cnt = 1, p[502], n, m;
bool checked[502];
int findRoot(int nd) {
    if (nd == p[nd]) return nd;
    return p[nd] = findRoot(p[nd]);
}
bool isUnion(int u, int v) {
    u = findRoot(u);
    v = findRoot(v);
    if (u == v) return false;
    if (checked[u] == false) checked[v] = false;
    p[u] = v;
    return true;
}
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    while (1) {
        cin >> n >> m;
        if (n == 0) break;
        fill(checked, checked + 502, true);
        for (int i = 1; i <= n; i++) p[i] = i;
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            if (!isUnion(u, v)) {
                checked[findRoot(u)] = false;
            }
        }
        set<int> s;
        for (int i = 1; i <= n; i++) {
            int a = findRoot(i);
            if (checked[a]) s.insert(a);
        }
        if (s.size() == 0) cout << "Case " << cnt << ": No trees.\n";
        else if (s.size() == 1) cout << "Case " << cnt << ": There is one tree.\n";
        else cout << "Case " << cnt << ": A forest of " << s.size() << " trees.\n";
        cnt++;
    }
}