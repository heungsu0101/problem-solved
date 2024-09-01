/*
    #백준2188 축사 배정(P4)
        - 이분매칭 문제
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, matched[202], visited[202], ans;
vector<int> adj[202];
bool dfs(int cur) {
    for (int next : adj[cur]) {
        if (visited[next]) continue;
        visited[next] = true;
        if (matched[next] == 0 || dfs(matched[next])) {
            matched[next] = cur;
            return true;
        }
    }
    return false;
}
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int tmp; cin >> tmp;
        for (int j = 0; j < tmp; j++) {
            int _tmp; cin >> _tmp;
            adj[i].push_back(_tmp);
        }
    }
    for (int i = 1; i <= n; i++) {
        fill(visited, visited + 202, 0);
        if (dfs(i)) ans++;
    }
    cout << ans;
    return 0;
}