/*
    #백준14267 회사 문화 1(G4)
        - 트리 dp문제
        - dp값을 업데이트 시켜줄 때마다, dfs를 돌리면 변질 이진 트리일 경우, O(n * m)의 시간복잡도로 인해 시간초과가 발생함
        - 그렇게 때문에 값을 다 받아서, 최초로 칭찬받은 사람의 dp에 저장해준 후 나중에 한번에 하는 것이 좋음
            - 부모노드의 칭찬 수치는 자식노드의 칭찬 수치에 무조건적으로 포함되기 때문.

*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, root, dp[100005];
vector<int> adj[100005];
void go(int nd) {
    for (int next : adj[nd]) {
        dp[next] += dp[nd];
        go(next);
    }
}
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int p; cin >> p;
        if (p == -1) root = i;
        else adj[p].push_back(i);
    }
    while (m--) {
        int a, b; cin >> a >> b;
        dp[a] += b;
    }
    go(root);
    for (int i = 1; i <= n; i++) cout << dp[i] << " ";
    return 0;
}