#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int level[200005], parent[200005];
struct edge{
    int u, v, w;
};
bool compare(edge a, edge b) {
    return a.w < b.w;
}
int findRoot(int node) {
    while (node != parent[node]) {
        node = parent[node];
    }
    return node;
}
bool isUnion(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);
    if (a == b) return false;
    if (level[a] >= level[b]) {
        if (level[a] == level[b]) level[a]++;
        parent[b] = a;
    } else parent[a] = b;
    return true;
}
int main (void) {
    ios::sync_with_stdio(false); cin.tie(0);
    while (1) {
        fill(level, level + 200005, -1);
        fill(parent, parent + 200005, -1);
        vector<edge> e;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        for (int i = 0; i < n; i++) {
            level[i] = 1;
            parent[i] = i;
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            int u, v, w; cin >> u >> v >> w;
            ans += w;
            e.push_back({u, v, w});
        }
        sort(e.begin(), e.end(), compare);
        for (edge _e : e) {
            int a = _e.u;
            int b = _e.v;
            if (isUnion(a, b)) {
                ans -= _e.w;
            }
        }
        cout << ans << "\n";
    }
    

    return 0;
}