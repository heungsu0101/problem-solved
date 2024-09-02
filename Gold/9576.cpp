/*
    #백준9576 책 나눠주기(G2)
        - 이분 매칭 or 그리디 문제
        - 이분 매칭으로도 문제를 풀 수 있으나, 우선순위큐를 이용해 그리디하게 문제를 해결하면 보다 더 빠르게 해결할 수 있음
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, visited[1003], matched[1003];

bool dfs(vector<pair<int, int>> &v, int cur) {
    for (int i = v[cur].first; i <= v[cur].second; i++) {
        if (visited[i]) continue;
        visited[i] = 1;
        if (matched[i] == 0 || dfs(v, matched[i])) {
            matched[i] = cur;
            return true;
        }
    }
    return false;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int ans = 0;
        fill(matched, matched + 1003, 0);
        cin >> n >> m;
        vector<pair<int, int>> v(1003);
        for (int i = 1; i <= m; i++) {
            cin >> v[i].first >> v[i].second;
        }
        for (int i = 1; i <= m; i++) {
            fill(visited, visited + 1003, 0);
            if (dfs(v, i)) ans++;
        }
        cout << ans << "\n";
    }
}