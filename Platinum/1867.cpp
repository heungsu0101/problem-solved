/*
    #백준1854 돌멩이 제거(P3)
        - 이분매칭 문제
        - 쾨닉의 정리를 이용하여 문제를 해결
            - 쾨닉의 정리 : 이분 그래프에서 최대 매칭 = 최소 정점 커버
            - 최대 이분매칭을 구해 모든 간선을 색칠한다고 생각하면 됨
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, k, ans, visited[502], matched[502];
vector<int> adj[502];
bool dfs(int cur) {
    for (int next : adj[cur]) {
        if (visited[next]) continue;
        visited[next] = 1;
        if (matched[next] == 0 || dfs(matched[next])) {
            matched[next] = cur;
            return true;
        }
    }
    return false;
}
int main(void) {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        fill(visited, visited + 502, 0);
        if (dfs(i)) ans++;
    }
    cout << ans;
    return 0;
}